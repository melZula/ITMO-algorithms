#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;


int main() {
  ifstream fin("pathsg.in");
  ofstream fout("pathsg.out");

  int V, E;
  fin >> V >> E;

  int g[V][V];

  int i, j, x, y, z;
  for (i = 0; i < V; i++) {
    for (j = 0; j < V; j++) {
      if (i == j) g[i][j] = 0;
      else
      g[i][j] = 100000;
    }
  }
  for (i = 0; i < E; i++) {
    fin >> x >> y >> z;
    g[x-1][y-1] = z;
  }


  for (int k=0; k<V; ++k) {
    for (int i=0; i<V; ++i) {
      for (int j=0; j<V; ++j)
      g[i][j] = (g[i][j] < g[i][k] + g[k][j]) ? g[i][j] : g[i][k] + g[k][j];
    }
  }

  for (size_t i = 0; i < V; i++) {
    for (size_t j = 0; j < V; j++) {
      cout << g[i][j] << ' ';
    }
    cout << endl;
  }
  return 0;
}
