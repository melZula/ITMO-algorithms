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

    int G[V][V];
    int i, j, x, y;

    for (i = 0; i < V; i++) {
      for (j = 0; j < V; j++) {
        G[i][j] = 0;
      }
    }

    int flag = 0;

    for (i = 0; i < E; i++) {
      fin >> x >> y;
      if (G[x-1][y-1] == 1) flag = 1;
      G[x-1][y-1] = 1;
    }

    for (i = 0; i < V; i++) {
      for (j = 0; j < V; j++) {
        if ((G[i][j] == G[j][i])&&(G[i][j] == 1)&&(i != j)) {
          flag = 1;
        }
        //printf("step %d %d flag %d\n",i, j, flag );
      }
    }
    fout << ((flag == 1) ? "YES" : "NO");
    return 0;
}
