#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;

vector< vector<float> > G;


float range(vector<float> a, vector<float> b) {
  return ( sqrt( pow(b[0]-a[0], 2) + pow(b[1]-a[0], 2) ) );
}

void prim() {

}

int main() {
  ifstream fin("spantree.in");
  ofstream fout("spantree.out");

  int V;
  fin >> V;

  G.resize(4);

  int i, j, x, y;
  for (i = 0; i < V; i++) {
    fin >> x >> y;
    G[i].push_back(x);
    G[i].push_back(y);
  }

  fout << range(G[0], G[1]);

  return 0;
}
