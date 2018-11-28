#include <fstream>
#include <iostream>
#include <cstring>
 
using namespace std;
 
 
int main() {
    int n, m, q, cnt = 0;
    char c;
    ifstream fin("stack.in");
    ofstream fout("stack.out");
     
    fin >> n;
 
    int a[n];
     
    for (int i = 0; i < n; i++)
    {
        fin >> c;
         
        if (c == '+')
            fin >> a[cnt++];
        else
            fout << a[--cnt] << "\n";
             
    }
 
    fin.close();
    fout.close();
    return 0;
}
