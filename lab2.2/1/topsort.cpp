#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

vector< vector<int> > G;
vector<int> used;
vector<int> answ;

void BFS(int s, int iter) {
  s--;
  queue<int> q;
  used[s] = iter;
  q.push(s);
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    for (size_t i = 0; i < G[v].size(); i++) {
      int to = G[v][i];
      if (!used[to]) {
        q.push(to);
        used[to] = iter;
      }
    }
  }
}

void DFS (int v) {
  printf("%d\n", v );
  used[v] = true;
  for (size_t i = 0; i < G[v].size(); i++) {
    if (!used[G[v][i]])
    DFS (G[v][i]);
  }
}

void topsort() {
  for (int i=0; i<n; ++i)
  used[i] = false;
  answ.clear();
  for (int i=0; i<n; ++i) {
    if (!used[i]) {
      dfs (i);
    }
  }
  reverse (answ.begin(), answ.end());
}

int main() {
  ifstream fin("topsort.in");
  ofstream fout("topsort.out");

  int V, E;
  fin >> V >> E;

  G.resize(V);
  used.resize(V, 0);
  int answ[E];

  int i, j, x, y;
  for (i = 0; i < E; i++) {
    fin >> x >> y;
    G[x-1].push_back(y-1);
  }

  for (i = 0; i < V; i++) {
    printf("%d: ",i );
    for (j = 0; j < G[i].size(); j++) {
      printf("%d ", G[i][j]);
    }
    printf("\n" );
  }


  DFS(0);

  for (j = 0; j < V; j++) {
    fout << used[j] << ' ';
  }
  return 0;
}
