#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

vector< vector<int> > G;
vector<int> used;
vector<int> time;
vector<int> answ;
int tout = 0;

void DFS (int v) {
  used[v] = 1;
  int i;
  for (i = 0; i < G[v].size(); i++) {
    if (!used[G[v][i]]) DFS (G[v][i]);
  }
  time[v] = tout++;
  printf("%d -- %d\n",v+1, time[v]);
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
  ifstream fin("cond.in");
  ofstream fout("cond.out");

  int V, E;
  fin >> V >> E;

  G.resize(V);
  used.resize(V, 0);
  answ.resize(V);
  time.resize(V);

  int i, j, x, y;
  for (i = 0; i < E; i++) {
    fin >> x >> y;
    G[x-1].push_back(y-1);
  }

  topsort(V);


  for (j = 0; j > time.size(); j++) {
    fout << time[j] << ' ';
  }

  return 0;
}
