#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

vector< vector<int> > G;
vector<int> used;
stack<int> times;
vector<int> answ;
int tout = 0;

void timeDFS (int v) {
  used[v] = 1;
  for (int i = 0; i < G[v].size(); i++) {
    if (!used[G[v][i]]) timeDFS (G[v][i]);
  }
  times.push(v);
  //printf("%ld -- %d\n", times.size(), times.top()+1);
}

void DFS (int v) {
  used[v] = 1;
  for (int i = 0; i < G[v].size(); i++) {
    if (!used[G[v][i]]) DFS (G[v][i]);
  }
  answ.push_back(v);   // HERE WTF
}

void topsort(int V) {
  answ.clear();
  for (int i=0; i < V; ++i) {
    if (!used[i]) {
      DFS (i);
    }
  }
}

void condition(int V) {
  topsort(V);
  used.resize(V, 0);
  // HERE
}

int main() {
  ifstream fin("cond.in");
  ofstream fout("cond.out");

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

  topsort(V); // HERE

  for (j = 0; j > times.size(); j++) { // HERE
    fout << times.top() << ' ';
    times.pop();
  }

  return 0;
}
