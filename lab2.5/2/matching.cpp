#include <iostream>
#include <fstream>
#include <cstdio>
#include <vector>
#define MAX 10001
using namespace std;

vector<int> G2B( MAX, 0 );    
vector< vector<int> > W( MAX );

int k;  // start and color

vector<int> V(MAX, 0); // цвета вершин

int dfs( int b ) {
  if( V[b] != k ) {
    V[b] = k;
    for( int j = 0; j < W[b].size(); j++ ) {
      if( G2B[ W[b][j] ] == 0 || dfs( G2B[ W[b][j] ] ) ) {
        G2B[ W[b][j] ] = b;
        return 1;
      }
    }
  }
  return 0;
}

int main() {
  ifstream fin("matching.in");
  ofstream fout("matching.out");
  int Ng, Nb;
  int E;
  int g, b, res;
  fin >> Ng >> Nb >> E;
  while(E--) {
    fin >> g >> b;
    W[b].push_back(g);
  }
  for(k = 1, res = 0; k <= Nb; k++) {
    res += dfs(k);
  }
  fout << res;
  return 0;
}
