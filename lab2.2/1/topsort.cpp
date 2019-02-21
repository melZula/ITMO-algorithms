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
int flag = 0;

void DFS (int v) {
  used[v] = 1;  // 1 - gray 2 - black
  int i;
  for (i = 0; i < G[v].size(); i++) {
    if (used[G[v][i]] == 1) {
      flag = 1;
    } else {
      if (used[G[v][i]] == 0) DFS (G[v][i]);
    }
  }
  used[v] = 2;
  answ.push_back(v);
}

void topsort(int V) {
  answ.clear();
  for (int i=0; i < V; ++i) {
    if (!used[i]) {
      DFS (i);
    }
  }
}

int main() {
  ifstream fin("topsort.in");
  ofstream fout("topsort.out");

  int V, E;
  fin >> V >> E;

  G.resize(V);
  used.resize(V, 0);
  answ.resize(V);

  int i, j, x, y;
  for (i = 0; i < E; i++) {
    fin >> x >> y;
    G[x-1].push_back(y-1);
  }

  topsort(V);

  if (!flag) {
    for (j = answ.size()-1; j > -1; j--) {
      fout << answ[j]+1 << ' ';
    }
  } else fout << -1;

  return 0;
}
