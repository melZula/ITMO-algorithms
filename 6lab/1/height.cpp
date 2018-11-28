#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
 
int tree[200001][3];
int HGT = -1;
 
void height(int curr, int h){
	HGT = (h > HGT) ? h : HGT;
    if (tree[curr][1] != 0){
        height(tree[curr][1], h+1);
    }
    if (tree[curr][2] != 0){
        height(tree[curr][2], h+1);
    }
   
}
int main() {
    ifstream fin("height.in");
    ofstream fout("height.out");
 
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
   
    height(1, 1);
   
    fout << HGT;
    return 0;
}
