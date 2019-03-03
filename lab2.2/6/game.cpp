#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

vector< vector<int> > G;
bool flag = false;

void DFS (int v, int len) {
  //printf("DFS %d len %d flag %d\n", v, len, flag);
  if ((G[v].size() == 0)&&(len % 2 == 1)) {
    flag = true;
  }
  for (int i = 0; i < G[v].size(); i++) {
    //printf("%d - %d len %d flag %d\n",v ,G[v][i], len, flag);
    DFS (G[v][i], len+1);
  }
}

int main() {
  ifstream fin("game.in");
  ofstream fout("game.out");

  int V, E, S;
  fin >> V >> E >> S;

  G.resize(V);

  int i, j, x, y;
  for (i = 0; i < E; i++) {
    fin >> x >> y;
    G[x-1].push_back(y-1);
  }

  DFS(S-1, 0);

  fout << (flag ? "First player wins" : "Second player wins");

  return 0;
}
