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
int inCycle = 0;
int start;

void DFS (int v) {
  used[v] = 1; // 1 - gray 2 - black
  for (int i = 0; i < G[v].size(); i++) {
    int to = G[v][i];
    if (used[to] == 1) { // if gray
      start = to;
      flag = true;
      inCycle = true;
    } else {
      if (!used[to]) DFS (to);
    }
    if (inCycle) {
      answ.push_back(v + 1);
      if (v == start) {
        inCycle = false;
      }
      used[v] = 2;
      return;
    }
  }
  used[v] = 2;
}

void topsort(int V) {
  for (int i=0; i < V; ++i) {
    if (!used[i] && !flag) {
      DFS (i);
    }
  }
}

int main() {
  ifstream fin("cycle.in");
  ofstream fout("cycle.out");

  int V, E;
  fin >> V >> E;

  G.resize(V);
  used.resize(V, 0);

  int i, j, x, y;
  for (i = 0; i < E; i++) {
    fin >> x >> y;
    G[x-1].push_back(y-1);
  }

  topsort(V);

  if (!flag) {
    fout << "NO";
  } else {
    fout << "YES" << endl;
    for (j = answ.size()-1; j > -1; j--) {
      fout << answ[j] << ' ';
    }
  }

  return 0;
}
