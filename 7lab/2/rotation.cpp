#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
 
int tree[200001][3];
 



int main() {
    ifstream fin("rotation.in");
    ofstream fout("rotation.out");
 
    int n, i, temp;
    fin >> n;
    if (n == 0){
        fout << 0;
        return 0;
    }
   
    for (i = 1; i < n+1; i++) {
        fin >> temp;            //fin >> tree[n][0] >> tree[n][1] >> tree[n][2];
        tree[i][0] = temp;
        fin >> temp;
        tree[i][1] = temp;
        fin >> temp;
        tree[i][2] = temp;
    }
   
   
    fout << HGT;
    return 0;
}
