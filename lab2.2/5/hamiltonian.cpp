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
bool flag = false;


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

bool hamiCheck(int V) {
  bool check = true;
  for (int i = 0; i < V-1; i++) {
    int v = answ[V - i -1];
    if (check) {
      check = false;
      for (int j = 0; j < G[v].size(); j++) {
        if (G[v][j] == answ[V-i-2]) {
          check = true;
        }
      }
    } else break;
  }
  return check;
}

int main() {
  ifstream fin("hamiltonian.in");
  ofstream fout("hamiltonian.out");

  int V, E;
  fin >> V >> E;

  G.resize(V);
  used.resize(V, 0);
  answ.resize(V, 0);

  int i, j, x, y;
  for (i = 0; i < E; i++) {
    fin >> x >> y;
    G[x-1].push_back(y-1);
  }

  topsort(V);

  fout << (hamiCheck(V) ? "YES" : "NO");

  return 0;
}
