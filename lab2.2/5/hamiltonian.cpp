#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

vector< vector<int> > G;
vector<int> used;
vector<int> group;
bool flag = false;

void BFS(int s) {
  s--;
  queue<int> q;
  used[s] = 1;
  group[s] = 1; // 1, -1 group
  q.push(s);
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    for (size_t i = 0; i < G[v].size(); i++) {
      int to = G[v][i];
      if (group[to] != group[v]) {
        group[to] = -group[v];
      } else flag = true;
      if (!used[to]) {
        q.push(to);
        used[to] = 1;
      }
    }
  }
}

void 

int main() {
  ifstream fin("hamiltonian.in");
  ofstream fout("hamiltonian.out");

  int V, E;
  fin >> V >> E;

  G.resize(V);
  used.resize(V, 0);
  group.resize(V, 0);

  int i, j, x, y;
  for (i = 0; i < E; i++) {
    fin >> x >> y;
    G[x-1].push_back(y-1);
  }

  for (i = 0; i < V; i++) {
    if (!used[i]) {
      BFS(i + 1);
    }
  }

  fout << (flag ? "NO" : "YES");

  return 0;
}
