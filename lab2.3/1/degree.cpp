#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;

vector< vector<int> > G;

int main() {
  ifstream fin("input.txt");
  ofstream fout("output.txt");

  int V, E;
  fin >> V >> E;

  G.resize(V);

  int i, j, x, y;
  for (i = 0; i < E; i++) {
    fin >> x >> y;
    G[x-1].push_back(y-1);
    G[y-1].push_back(x-1);
  }

  for (j = 0; j < V; j++) {
    fout << G[j].size() << ' ';
  }

  return 0;
}
