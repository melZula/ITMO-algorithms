#include <iostream>
#include <fstream>
#include <math.h>
#include <vector>
using namespace std;

vector < vector<long long int> > e;
const long long int INF = 6000000000000000000;
vector <long long int> d;
vector <bool> cycle;

void ford_bellman(int n, int m, int s) {
  d.resize (n, INF);
  cycle.resize(n, false);
  d[s] = 0;
  for (size_t i = 0; i < n; i++) {
    bool any = false;
    for (size_t j = 0; j < m; j++) {
      if (d[e[j][0]] < INF && d[e[j][0]] > -INF) {
        if (d[e[j][1]] > d[e[j][0]] + e[j][2]) {
          d[e[j][1]] = d[e[j][0]]+e[j][2];    // relax for all edges
          if (i == n-1)
          cycle[e[j][1]] = true;  // check negative cycle on n iter.
        }
        any = true;
      }
    }
    if (!any)  break;
  }
}

int main() {
  ifstream fin("path.in");
  ofstream fout("path.out");

  unsigned int V, E, S;
  fin >> V >> E >> S;

  e.resize(E);
  for (size_t i = 0; i < E; i++) {
    e[i].resize(3);
  }

  int i, j, x, y;
  long long z;
  for (i = 0; i < E; i++) {
    fin >> x >> y >> z;
    e[i] = {x-1, y-1, z};
  }

  ford_bellman(V, E, S-1);

  for (size_t i = 0; i < V; i++) {
    if (cycle[i] || abs(d[i]) > 5000000000000000000) {
      fout << '-' << endl;
    } else
    if (d[i] == INF) {
      fout << '*' << endl;
    } else
    fout << d[i] << endl;
  }

  return 0;
}
