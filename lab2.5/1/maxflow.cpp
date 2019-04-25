#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

vector < vector<int> > C; // flow matrix
vector < vector<int> > F; // current flow
vector <int> push; // flow in v
vector <int> mark;
vector <int> pred;
int n, m, s, t;
int max_flow;
const int INF = INT_MAX;

void init() {
  for (size_t i = 0; i < n; i++) {
    mark[i] = false;
    push[i] = 0;
    pred[i] = 0;
  }
}

bool bfs(int s, int t) {
  init();
  queue<int> Q;
  mark[s] = true;
  pred[s] = s;
  push[s] = INF;
  Q.push(s);
  while (!mark[t] && !Q.empty()) {
    int u = Q.front();
    Q.pop();
    for (int v = 0; v < n; v++) {
      if (!mark[v] && (C[u][v] - F[u][v] > 0)) {
        push[v] = (push[u] < C[u][v] - F[u][v]) ? push[u] : C[u][v] - F[u][v];
        mark[v] = true;
        pred[v] = u;
        Q.push(v);
      }
    }
  }

  return mark[t];
}

void max_flow_ff(){
  int u, v, flow = 0;
  while (bfs(s, t)) {
    int add = push[t];
    v = t;
    u = pred[v];
    while (v != s) {
      F[u][v] += add;
      F[v][u] -= add;
      v = u;
      u = pred[v];
    }
    flow += add;
  }
  max_flow = flow;
}

int main() {
  ifstream fin("maxflow.in");
  ofstream fout("maxflow.out");

  fin >> n >> m;
  s = 0;
  t = n-1;

  C.resize(n);
  for (size_t i = 0; i < n; i++) {
    C[i].resize(n);
  }
  F.resize(n);
  for (size_t i = 0; i < n; i++) {
    F[i].resize(n);
  }
  push.resize(n);
  mark.resize(n);
  pred.resize(n);

  int i, j, x, y;
  int z;
  for (i = 0; i < m; i++) {
    fin >> x >> y >> z;
    C[x-1][y-1] = z;
  }


  max_flow_ff();

  fout << max_flow;

  return 0;
}
