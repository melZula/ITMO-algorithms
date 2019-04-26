#include<iostream>
#include <fstream>
#include <vector>
#include <string.h>
using namespace std;


ifstream input ("circulation.in");
ofstream output("circulation.out");


struct Edge{
	int from,to,max_cap,flow,min_cap;
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
			if(d[to] == -1 && e[id].flow < e[id].max_cap){
				q[qt++] = to;
				d[to] = d[v] + 1;
			}
		}
	}
	return d[t] != -1;

}
int  dfs(int v, int flow,int * ptr,vector<Edge>& e,int t,vector<int> * g,int * d){
	if(!flow) return 0;
	if(v == t) return flow;
	for(;ptr[v] < (int)g[v].size();++ptr[v]){
		int id = g[v][ptr[v]],
		 to = e[id].to;
		if(d[to] != d[v] + 1) continue;
		int pushed = dfs(to,min(flow,e[id].max_cap - e[id].flow),ptr,e,t,g,d);
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


int main(){
	int n,m;
	input >> n >> m;
	n += 2;
	vector<int> g[n];
	int ptr[n];
	int d[n];
	int position[m];
	Edge e;
	vector<Edge> edges(n);
	for(int i = 0; i < m;i++){
		input >> e.from >> e.to >> e.min_cap >> e.max_cap;
		g[e.from].push_back(edges.size());
		position[i] = g[e.from].back();
		int delta_cap = e.max_cap - e.min_cap;
		edges.push_back({e.from,e.to,delta_cap,0,e.min_cap});
		g[e.to].push_back(edges.size());
		edges.push_back({e.to,e.from,0,0,0});
		g[e.from].push_back(edges.size());
		edges.push_back({e.from,n-1,e.min_cap,0,0});
		g[n-1].push_back(edges.size());
		edges.push_back({n-1,e.from,0,0,0});
		g[0].push_back(edges.size());
		edges.push_back({0,e.to,e.min_cap,0,0});
		g[e.to].push_back(edges.size());
		edges.push_back({e.to,0,0,0,0});
	}
		long flow = 0;
	for(;;){
		if(!bfs(n,0,n-1,g,edges,d)) break;
		memset(ptr,0,n*sizeof(ptr[0]));
		while(int pushed = dfs(0,10e6,ptr,edges,n-1,g,d)){
			flow += pushed;
		}
	}
	for(auto x : g[0]){
		if(edges[x].flow < edges[x].max_cap){
			output << "NO\n";
			return 0;
		}
	}
	output << "YES\n";

		for(auto x : position){
			if(edges[x].to != n-1 && edges[x].from != 0){
				output << edges[x].flow + edges[x].min_cap << "\n";
			}
		}
	}	
