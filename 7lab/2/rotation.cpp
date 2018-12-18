#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
using namespace std;

struct node {
    int key;
    node *left;
    node *right;
    node *parent;
};

int a[200001][3];
node *root;
node *n;
int allNums = 1;

node* rotateright(node* p) {
    node* q = p->left;
    p->left = q->right;
    q->right = p;
    return q;
}

node* rotateleft(node* q) {
    node* p = q->right;
    q->right = p->left;
    p->left = q;
    return p;
}



void insert(node *curr, int k) {
    if (curr == NULL) {
        n = new node;
        n->key = k;
        n->left = 0;
        n->right = 0;
    } else if (curr->key > k) {
        insert(curr->left, k);
        if (curr->left == NULL) {
            curr->left = n;
            n->parent = curr;
        }
    } else {
        insert(curr->right, k);
        if (curr->right == NULL) {
            curr->right = n;
            n->parent = curr;
        }
    }
}

void show(node* curr, int currNum) {
    a[currNum][0] = curr->key;
    if (curr->left != NULL) {
        allNums++;
        a[currNum][1] = allNums;
        show(curr->left, allNums);
    } else {
        a[currNum][1] = 0;
    }
    if (curr->right != NULL) {
        allNums++;
        a[currNum][2] = allNums;
        show(curr->right, allNums);
    } else {
        a[currNum][2] = 0;
    }
}

int maxhL = 0;
int maxhR = 0;


void heightL(int key, int h) {
    if (a[key][1] != 0) {
        heightL(a[key][1], h + 1);
    } else if (h > maxhL) {
        maxhL = h;
    }
    if (a[key][2] != 0) {
        heightL(a[key][2], h + 1);
    } else if (h > maxhL) {
        maxhL = h;
    }
}

void heightR(int key, int h) {
    if (a[key][1] != 0) {
        heightR(a[key][1], h + 1);
    } else if (h > maxhR) {
        maxhR = h;
    }
    if (a[key][2] != 0) {
        heightR(a[key][2], h + 1);
    } else if (h > maxhR) {
        maxhR = h;
    }
}

int getBalance(int key) {
    if ((a[key][2] == 0) && (a[key][1] != 0)) {
        maxhL = 0;
        heightL(a[key][1], 1);
        return 0 - maxhL;
    } else if ((a[key][2] != 0) && (a[key][1] == 0)) {
        maxhR = 0;
        heightR(a[key][2], 1);
        return maxhR;
    } else if ((a[key][1] == 0) && (a[key][2] == 0)) {
        return 0;
    } else {
        maxhL = 0;
        maxhR = 0;
        heightL(a[key][1], 1);
        heightR(a[key][2], 1);
        return maxhR - maxhL;
    }
}

void balance(node* p) {
        if(getBalance(a[1][2]) < 0)
            p->right = rotateright(p->right);
        root = rotateleft(p);
}



int main() {
    ifstream fin("rotation.in");
    ofstream fout("rotation.out");
    int k, curr;
    fin >> k;
    
    for (int i = 1; i <= k; i++) {
        fin >> curr;
        a[i][0] = curr;
        fin >> curr;
        a[i][1] = curr;
        fin >> curr;
        a[i][2] = curr;
        insert(root, a[i][0]);
        if (root == NULL) root = n;
    }
    
    balance(root);
    fout << k << endl;
    show(root, allNums);
    
    for (int i = 1; i <= k; i++) {
        fout << a[i][0] << " ";
        fout << a[i][1] << " ";
        fout << a[i][2] << endl;
    }
    
    return 0;
}
