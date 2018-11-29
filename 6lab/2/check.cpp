#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;
 
int tree[200001][3];
int flag = 1;
 
void check(long long curr, long long min, long long max){
	if ((tree[curr][0] <= min)||(tree[curr][0] >= max)){
		flag = 0;
	}
    if (tree[curr][1] != 0){
        check(tree[curr][1], min, tree[curr][0]);
    }
    if (tree[curr][2] != 0){
        check(tree[curr][2], tree[curr][0], max);
    }
}
int main() {
    ifstream fin("check.in");
    ofstream fout("check.out");
 
    int n, i, temp;
    fin >> n;
    if (n == 0){
        fout << "YES";
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
	check(1, -1000000000, 1000000000);
    fout << ((flag == 1) ? "YES" : "NO");
    return 0;
}
