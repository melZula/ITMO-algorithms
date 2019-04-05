#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;

vector < vector<int> > g;
vector <bool> used;
const long int INF = 100000;
vector <int> d;

void dijkstra (int s, int n) {
  used.resize(n, false);
  d.resize(n, INF);
  d[s] = 0;

  for (size_t i = 0; i < n; i++) {
    int v = -1;
    for (size_t j = 0; j < n; j++) {  // finding min from all unused
      if (!used[j] && (v == -1 || d[j] < d[v]))
      v = j;
    }

    if (d[v] == INF) break;
    used[v] = true;

    for (size_t j = 0; j < n; j++) {  // relax
      if (d[v]+g[v][j] < d[j]) {
        d[j] = d[v]+g[v][j];
      }
    }
  }
}

int main() {
  ifstream fin("pathbgep.in");
  ofstream fout("pathbgep.out");

  int V, E;
  fin >> V >> E;

  g.resize(V);
  for (size_t i = 0; i < V; i++) {
    g[i].resize(V);
  }

  int i, j, x, y, z;
  for (i = 0; i < V; i++) {
    for (j = 0; j < V; j++) {
      if (i == j) g[i][j] = 0;
      else
      g[i][j] = INF;
    }
  }
  for (i = 0; i < E; i++) { // to adj
    fin >> x >> y >> z;
    g[x-1][y-1] = z;
    g[y-1][x-1] = z;
  }

  dijkstra(0, V);

  for (size_t i = 0; i < V; i++) {
    fout << d[i] << ' ';
  }

  return 0;
}
