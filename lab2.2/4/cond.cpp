#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

vector< vector<int> > G;
vector< vector<int> > Ginv;
vector<int> used;
stack<int> times;
vector<int> answ;
int tout = 0;
int iter = 1;

void timeDFS (int v) {
  used[v] = 1;
  for (int i = 0; i < G[v].size(); i++) {
    if (!used[G[v][i]]) timeDFS (G[v][i]);
  }
  times.push(v);
}

void DFS (int v) { // inversed
  used[v] = 1;
  for (int i = 0; i < Ginv[v].size(); i++) {
    if (!used[Ginv[v][i]]) DFS (Ginv[v][i]);
  }
  answ[v] = iter;
}

void topsort(int V) {
  answ.clear();
  for (int i=0; i < V; ++i) {
    if (!used[i]) {
      timeDFS (i);
    }
  }
}

void condition(int V) {
  topsort(V);
  used.clear();
  used.resize(V, 0);
  for (int i = 0; i < V; i++) {
    printf("%d \n", times.top());
    if (!used[times.top()]) {
      DFS(times.top());
      iter++;
    }
    times.pop();
  }
}

int main() {
  ifstream fin("cond.in");
  ofstream fout("cond.out");

  int V, E;
  fin >> V >> E;

  G.resize(V);
  Ginv.resize(V);
  used.resize(V, 0);
  answ.resize(V, 0);

  int i, j, x, y;
  for (i = 0; i < E; i++) {
    fin >> x >> y;
    G[x-1].push_back(y-1);
    Ginv[y-1].push_back(x-1);
  }

  condition(V);

  fout << iter - 1 << endl;
  for (int i = 0; i < V; i++) {
    fout << answ[i] << ' ';
  }

  return 0;
}
