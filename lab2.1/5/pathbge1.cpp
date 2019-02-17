#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

vector< vector<int> > G;
vector<int> used;
vector<int> dist;

void BFS(int s) {
  s--;
  queue<int> q;
  used[s] = 1;
  dist[s] = 0;
  q.push(s);
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    for (size_t i = 0; i < G[v].size(); i++) {
      int to = G[v][i];
      if (!used[to]) {
        q.push(to);
        used[to] = 1;
        dist[to] = dist[v] + 1;
      }
    }
  }
}

int main() {
  ifstream fin("pathbge1.in");
  ofstream fout("pathbge1.out");

  int V, E;
  fin >> V >> E;

  G.resize(V);
  used.resize(V, 0);
  dist.resize(V, 0);
  int answ[E];

  int i, j, x, y;
  for (i = 0; i < E; i++) {
    fin >> x >> y;
    G[x-1].push_back(y-1);
    G[y-1].push_back(x-1);
  }

  BFS(1);

  for (j = 0; j < V; j++) {
    fout << dist[j] << ' ';
  }
  return 0;
}
