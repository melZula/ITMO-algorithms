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

void BFS(int s) {
  s--;
  queue<int> q;
  used[s] = 1;
  q.push(s);
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    for (size_t i = 0; i < G[v].size(); i++) {
      int to = G[v][i];
      if (!used[to]) {
        q.push(to);
        used[to] = 1;
        // add group and check for inbi
      }
    }
  }
}

int main() {
  ifstream fin("bipartite.in");
  ofstream fout("bipartite.out");

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

  // check all components


  return 0;
}
