#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

vector< vector<int> > G;
vector<int> used;

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

int main() {
  ifstream fin("components.in");
  ofstream fout("components.out");

  int V, E;
  fin >> V >> E;

  G.resize(V);
  used.resize(V, 0);
  int answ[E];

  int i, j, x, y;
  for (i = 0; i < E; i++) {
    fin >> x >> y;
    G[x-1].push_back(y-1);
    G[y-1].push_back(x-1);
  }

  int iter = 0;

  for (i = 0; i < V; i++) {
    if (used[i] == 0) {
      iter++;
      BFS(i+1 , iter);
    }
  }
  
  fout << iter << endl;
  for (j = 0; j < V; j++) {
    fout << used[j] << ' ';
  }
  return 0;
}
