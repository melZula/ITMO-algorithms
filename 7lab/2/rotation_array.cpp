#include <fstream>
#include <stdlib.h>
#define SWAP(A, B) { int t = A; A = B; B = t; }
using namespace std;
 
long long tree[200001][5]; // 0-value 1-left 2-right 3-height 4-balance

long long max(long long a, long long b){
	return (a > b) ? a : b;
}
 
void heightBalance(int curr){
	if (curr != 0){
		heightBalance(tree[curr][1]);
		heightBalance(tree[curr][2]);
		tree[curr][3] = 1 + max(tree[tree[curr][1]][3],tree[tree[curr][2]][3]);
		tree[curr][4] = tree[tree[curr][2]][3] - tree[tree[curr][1]][3];
	}
}

void smallLrot(){
	int i;
	int change = tree[1][2];
	for (i = change; i > 1; i--){
		SWAP(tree[i][0], tree[i-1][0]);
		
		if ((tree[i-1][1] != 0)and(tree[i-1][1] < change)) tree[i-1][1]++;
		SWAP(tree[i][1], tree[i-1][1]);
		
		if ((tree[i-1][2] != 0)and(tree[i-1][1] < change)) tree[i-1][2]++;
		SWAP(tree[i][2], tree[i-1][2]);
	}
	tree[1][1] = 2;
}

void bigLrot(){
	int i;
	int change = tree[ tree[1][2] ][1];
	for (i = change; i > 1; i--){
		SWAP(tree[i][0], tree[i-1][0]);
		
		if ((tree[i-1][1] != 0)and(tree[i-1][1] < change)) tree[i-1][1]++;
		SWAP(tree[i][1], tree[i-1][1]);
		
		if ((tree[i-1][2] != 0)and(tree[i-1][2] < change)) tree[i-1][2]++;
		SWAP(tree[i][2], tree[i-1][2]);
	}
	
	change = tree[2][2];
	for (i = change; i > 3; i--){
		SWAP(tree[i][0], tree[i-1][0]);
		
		if ((tree[i-1][1] != 0)and(tree[i-1][1] < change)) tree[i-1][1]++;
		SWAP(tree[i][1], tree[i-1][1]);
		
		if ((tree[i-1][2] != 0)and(tree[i-1][2] < change)) tree[i-1][2]++;
		SWAP(tree[i][2], tree[i-1][2]);
	}
	tree[2][2] = tree[1][1];
	tree[3][1] = tree[1][2];
	tree[1][1] = 2;
	tree[1][2] = 3;
}

int main() {
    ifstream fin("rotation.in");
	ofstream fout("rotation.out");
	
    int n, i, temp;
    fin >> n;
   	
    for (i = 1; i < n+1; i++) {
        fin >> temp;
        tree[i][0] = temp;
        fin >> temp;
        tree[i][1] = temp;
        fin >> temp;
        tree[i][2] = temp;
        tree[i][3] = 1;
    }
    
    heightBalance(1);	
    
    if (tree[ tree[1][2] ][4] != -1){
    	smallLrot();
    } else
    	bigLrot();
    
    
    fout << n << endl;
    for (i = 1; i < n+1; i++) {
		temp = tree[i][0];
		fout << temp << ' ';
		temp = tree[i][1];
		fout << temp << ' ';
		temp = tree[i][2];
		fout << temp << endl;
    }
    return 0;
}
