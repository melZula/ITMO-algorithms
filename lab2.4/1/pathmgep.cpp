#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;


vector< vector<long long int> > g;
vector <bool> used;
const long long int INF = 40000000000000;
long long int answ;

void dijkstra (int s, int f, int n) {
  used.resize(n, false);
  vector <long long int> d (n, INF);
  d[s] = 0;

  for (size_t i = 0; i < n; i++) {
    int v = -1;
    for (size_t j = 0; j < n; j++) {  // finding min
      if (!used[j] && (v == -1 || d[j] < d[v]))
      v = j;
    }

    if (d[v] == INF) break;
    used[v] = true;

    for (size_t j = 0; j < n; j++) {  // relax
      if (g[v][j] > 0 && d[v]+g[v][j] < d[j]) {
        d[j] = d[v]+g[v][j];
      }
    }
  }
  answ = d[f];
}

int main() {
  ifstream fin("pathmgep.in");
  ofstream fout("pathmgep.out");

  int N, S, F;
  fin >> N >> S >> F;

  g.resize(N);

  int i, j, x, y;
  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      fin >> x;
      g[i].push_back(x);
    }
  }
  /*
  for (size_t i = 0; i < g.size(); i++) {
  cout << g[i][0] << g[i][1] << g[i][2] << endl;
}
*/
answ = -1;

dijkstra(S-1, F-1, N);

if (answ == INF)
fout << -1;
else
fout << answ;

return 0;
}
