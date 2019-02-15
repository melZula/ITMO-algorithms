#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;


int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int V, E;
    fin >> V;
    if (V == 0){
        return 0;
    }
    int G[V][V];

    int i, j, x, y, temp;
    for (i = 0; i < V; i++) {
      for (j = 0; j < V; j++) {
        fin >> temp;
        G[i][j] = temp;
      }
    }

    int flag = 0;

    for (i = 0; i < V; i++) {
      for (j = 0; j < V; j++) {
        if ((G[i][j] != G[j][i]) || ((i == j)&&(G[i][j] == 1))) {
          flag = 1;
        }
        //printf("step %d %d flag %d\n",i, j, flag );
      }
    }
    fout << ((flag == 1) ? "NO" : "YES");
    return 0;
}
