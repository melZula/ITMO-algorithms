#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;

vector < vector<pair<unsigned int,unsigned short int> > > g;
const int INF = 1000000;
vector <unsigned long int> d;

void dijkstra (unsigned int s, unsigned int n) {
  vector <bool> used (n, false);
  d.resize(n, INF);

  priority_queue < pair<long int, unsigned int> > q;   // using priority_queue to find min
  q.push (make_pair (0, s));

  d[s] = 0;

  while (!q.empty()) {
    int v = q.top().second;
    unsigned int currdist = -q.top().first;
    q.pop();
    if (currdist > d[v])  continue; // check dist to same v

    for (size_t j = 0; j < g[v].size(); j++) {  // relax
      unsigned int to = g[v][j].first,
      len = g[v][j].second;
      if (d[v]+len < d[to]) {
        d[to] = d[v]+len;
        q.push (make_pair (-d[to], to));
      }
    }
  }
}

int main() {
  ifstream fin("pathbgep.in");
  ofstream fout("pathbgep.out");

  unsigned int V, E;
  fin >> V >> E;

  g.resize(V);

  int i, j, x, y, z;
  for (i = 0; i < E; i++) { // to adj
    fin >> x >> y >> z;
    g[x-1].push_back(make_pair(y-1, z));
    g[y-1].push_back(make_pair(x-1, z));
  }

  dijkstra(0, V);

  for (size_t i = 0; i < V; i++) {
    fout << d[i] << ' ';
  }

  return 0;
}
