#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;

vector< vector<int> > G;

int main() {
  ifstream fin("input.txt");
  ofstream fout("output.txt");

  int N, S, F;
  fin >> N >> S >> F ;

  G.resize(N);

  int i, j, x, y;
  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      fin >> x;
      printf("%d ", x);
      G[i].push_back(x-1);
    }
  }

  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      printf("%d ", G[i][j]);
    }
  }

  return 0;
}
