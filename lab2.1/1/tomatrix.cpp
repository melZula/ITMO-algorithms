#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;


int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int V, E;
    fin >> V >> E;
    if (V == 0){
        return 0;
    }
    int G[V][V];

    int i, j, x, y;
    for (i = 0; i < V; i++) {
      for (j = 0; j < V; j++) {
        G[i][j] = 0;
      }
    }

    for (i = 0; i < E; i++) {
      fin >> x >> y;
      G[x-1][y-1] = 1;
    }

    for (i = 0; i < V; i++) {
      for (j = 0; j < V; j++) {
        fout << G[i][j];
        if (j != V-1) fout << ' ';
      }
      fout << endl;
    }

    return 0;
}
