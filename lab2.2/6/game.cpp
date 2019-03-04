#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;

vector< vector<int> > G;
vector< vector<int> > Ginv;
vector<int> wins;
vector<int> used;

void BFS(int V) {
  queue<int> q;
  for (int s = 0; s < V; s++) {
    if (G[s].size() == 0) {
      used[s] = 1;
      wins[s] = 1; // 1, -1 wins
      q.push(s);
    }
  }

  while (!q.empty()) {
    int v = q.front();
    q.pop();
    for (size_t i = 0; i < Ginv[v].size(); i++) {
      int to = Ginv[v][i];
      if (!used[to]) {
        wins[to] = -wins[v];
        q.push(to);
        used[to] = 1;
      }
    }
  }
}

int main() {
  ifstream fin("game.in");
  ofstream fout("game.out");

  int V, E, S;
  fin >> V >> E >> S;

  G.resize(V);
  Ginv.resize(V);
  wins.resize(V, 0);
  used.resize(V, 0);

  int i, j, x, y;
  for (i = 0; i < E; i++) {
    fin >> x >> y;
    G[x-1].push_back(y-1);
    Ginv[y-1].push_back(x-1);
  }

  BFS(V);

  fout << (wins[S-1] == -1 ? "First player wins" : "Second player wins");

  return 0;
}
