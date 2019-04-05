#include <iostream>
#include <fstream>
#include <vector>
#include <set>

using namespace std;

ifstream fin;
ofstream fout;

class Graph {
public:
    int vertices, edges;
    const int INFINITY = 1000000000;
    vector<vector<pair<int, int>>> adj; // first: adjacent vertex, second: weight

    Graph() {
        fin >> vertices >> edges;
        adj.resize(vertices + 1);
        for (int i = 0; i < edges; i++) {
            int v, u, weight;
            fin >> v >> u >> weight;
            adj[v].push_back(make_pair(u, weight));
            adj[u].push_back(make_pair(v, weight));
        }
    }

    void find_shortest_paths(int start, vector<int> &distance) {
        distance.resize(vertices + 1);
        for (int i = 1; i <= vertices; i++) {
            distance[i] = INFINITY;
        }
        distance[start] = 0;
        set<pair<int, int>> set;
        set.insert(make_pair(distance[start], start)); // first: distance, second: vertex
        while (!set.empty()) {
            int v = set.begin()->second;
            set.erase(set.begin());

            for (int i = 0; i < adj[v].size(); i++) {
                int adjacent_vertex = adj[v][i].first;
                int weight = adj[v][i].second;
                if (distance[v] + weight < distance[adjacent_vertex]) {
                    set.erase(make_pair(distance[adjacent_vertex], adjacent_vertex));
                    distance[adjacent_vertex] = distance[v] + weight;
                    set.insert(make_pair(distance[adjacent_vertex], adjacent_vertex));
                }
            }
        }
    }

    ~Graph() {
        fin.close();
        fout.close();
    }

};

int main() {

    fin.open("pathbgep.in");
    fout.open("pathbgep.out");

    Graph graph;
    vector<int> shortest_paths;
    graph.find_shortest_paths(1, shortest_paths);
    for (int i = 1; i < shortest_paths.size(); i++) {
        fout << shortest_paths[i] << " ";
    }

    fin.close();
    fout.close();

    return 0;
}
