#include<iostream>
#include <fstream>
#include <vector>
#include <string.h>
#include <deque>
using namespace std;

struct Edge{
	int from,to,number;
	long long flow,cap;
};

bool bfs(int n,int s,int t,vector<int> * g,vector<Edge>& e,int * d) {
	int q[n];
	int qh = 0,qt = 0;
	q[qt++] = s;
	memset(d,-1,n*sizeof(d[0]));
	d[s] = 0;
	while(qh < qt && d[t] == -1){
		int v = q[qh++];
		for(int i = 0; i < g[v].size();++i){
			int id = g[v][i],
			 to = e[id].to;
			if(d[to] == -1 && e[id].flow < e[id].cap){
				q[qt++] = to;
				d[to] = d[v] + 1;
			}
		}
	}
	return d[t] != -1;

}
long long dfs(int v, long long flow,int * ptr,vector<Edge>& e,int t,vector<int> * g,int * d){
	if(!flow) return 0;
	if(v == t) return flow;
	for(;ptr[v] < (int)g[v].size();++ptr[v]){
		int id = g[v][ptr[v]],
		 to = e[id].to;
		if(d[to] != d[v] + 1) continue;
		long long pushed = dfs(to,min(flow,e[id].cap - e[id].flow),ptr,e,t,g,d);
		if(pushed){
			e[id].flow += pushed;
			if(e[id].to == e[id+1].from && e[id].from  == e[id+1].to)
				e[id+1].flow -= pushed;
			else if(e[id].from == e[id-1].to && e[id].to == e[id-1].from)
				e[id-1].flow -= pushed;
			return pushed;
		}
	}
	return  0;
}

void decomposition(int s,vector<int> * g,int t,vector<pair<long long,deque<int>>>& decomp,vector<Edge>& edges){
	long long decomp_flow = 0;
	deque<int> decompos;
	do {
		decomp_flow = 0;
		int v = s;
		vector<bool> visited(t+1,0);
		while(!visited[v]){
			if(v == t){
				break;
			}

			int edge_n = -1;
			for(int i =  0; i < g[v].size();i++){
				int  id = g[v][i];
				if(edges[id].flow > 0){
					edge_n = id;
					break;
				}
			}
			if(edge_n == -1){
				decompos.clear();
				break;
			}
			decompos.push_back(edge_n);
			visited[v] = true;
			v = edges[edge_n].to;
		}
		if(visited[v]){
			while(edges[decompos.front()].from != v){
				decompos.pop_front();
			}
		}
		if(decompos.empty()){
			break;
		}
		decomp_flow = 10e10;
		for(auto x : decompos){
			if(edges[x].flow < decomp_flow){
				decomp_flow = edges[x].flow;
			}
		}
		for(auto x : decompos){
			edges[x].flow -= decomp_flow;
		}
		if(decomp_flow != 10e10){
			decomp.push_back({decomp_flow,decompos});
			decompos.clear();
		}
	}while(true);
}


int main(){
	int n,m;
	ifstream input("decomposition.in");
	ofstream output("decomposition.out");
	input >> n >> m;
	vector<int> g[n];
	int ptr[n];
	int d[n];
	Edge e;
	vector<Edge> edges(n);
	for(int i = 0; i < m;i++){
		input >> e.from >> e.to >> e.cap;
		e.from--,e.to--;
		e.number = i + 1;
		g[e.from].push_back((int)edges.size());
		edges.push_back({e.from,e.to,e.number,0,e.cap});
		g[e.to].push_back((int)edges.size());
		edges.push_back({e.to,e.from,e.number,0,0});	
	}
		long flow = 0;

	for(;;){
		if(!bfs(n,0,n-1,g,edges,d)) break;
		memset(ptr,0,n*sizeof(ptr[0]));
		while(long long pushed = dfs(0,10e10,ptr,edges,n-1,g,d)){
		}
	}
	vector<pair<long long,deque<int>>> decompositions;
	decomposition(0,g,n-1,decompositions,edges);
	output << decompositions.size() << "\n";
	for(auto x : decompositions){
		output << x.first << " ";
		output << x.second.size() << " ";
		for(auto y : x.second){
			output << edges[y].number << " ";
		}
		output << "\n";
	}

}