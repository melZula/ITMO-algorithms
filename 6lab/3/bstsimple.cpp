#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;

struct leaf{
	long long value;
	leaf *parent;
	leaf *lchild;
	leaf *rchild;
};

void insert(leaf *curr,long long key){
	if (curr->value == -1000000001){			//insert first node
		curr->value = key;
	}else{
		if (curr->value < key){							//write right
			if (curr->rchild != NULL){
				insert(curr->rchild, key); 
				}
			else{
				leaf *node = new(leaf);
				curr->rchild = node;
				node->parent = curr;
				node->lchild = NULL;
				node->rchild = NULL;
				node->value = key;
			}
		}
		else{
			if (curr->value > key){								//write left
				if (curr->lchild != NULL){
					insert(curr->lchild, key); 
					}
				else{
					leaf *node = new(leaf);
					curr->lchild = node;
					node->parent = curr;
					node->lchild = NULL;
					node->rchild = NULL;
					node->value = key;
				}
			}
		}
	}
}

leaf *search(leaf *curr, long long key){				printf("search %lld (%lld)\n", curr->value, key);
	if (curr->value == key){	printf("YES \n");
		return curr;                          
	}else{
		if ((curr->lchild == NULL)&&(curr->rchild == NULL)){
			return NULL;
		}
		if (key > curr->value)
			return search(curr->rchild, key);
		else{
			if (key < curr->value)
				return search(curr->lchild, key);
		}
	}
}

leaf *prev(leaf *curr,long long key){			//prev for functions
	leaf *state = search(curr, key);
	if (state->lchild == NULL)
		return NULL;
	else{
		state = state->lchild;
		while (state->rchild != NULL){
			state = state->rchild;
		}
		return state;
	}
}
leaf *next(leaf *curr,long long key){			//next for functions
	leaf *state = search(curr, key);
	if (state->rchild == NULL)
		return NULL;
	else{
		state = state->rchild;
		while (state->lchild != NULL){
			state = state->lchild;
		}
		return state;
	}
}

void del(leaf *curr,long long key){
	leaf *delleaf = search(curr, key); printf("delleaf %p\n", delleaf);
	if (delleaf != NULL){
		if ((delleaf->lchild != NULL) != (delleaf->rchild != NULL)){	//simple case 1 child
			if (delleaf->lchild == NULL){
				delleaf->rchild->parent = delleaf->parent;
				delleaf->parent->rchild = delleaf->rchild;	
				printf(" %lld  %lld\n",delleaf->rchild->parent->value, delleaf->parent->rchild->value);
				free(delleaf);
			}else{												printf("del L ");
				delleaf->lchild->parent = delleaf->parent;
				delleaf->parent->lchild = delleaf->lchild;
				printf(" %lld  %lld\n",delleaf->lchild->parent->value, delleaf->parent->lchild->value);
				free(delleaf);
			}
		} else if ((delleaf->lchild == NULL)&&(delleaf->rchild == NULL)){						// simple case 0 child
			if (delleaf->parent->rchild == delleaf)
				delleaf->parent->rchild = NULL;
			else 															//if (delleaf->parent->lchild == delleaf)
				delleaf->parent->lchild = NULL;
			free(delleaf);
		} if (prev(curr, key) != NULL){											// hard case
			leaf *change = prev(curr, key);
			curr->value = change->value;
			curr->parent = change->parent;
			curr->lchild = change->lchild;
			curr->rchild = change->rchild;
			del(change, change->value);
		} else if (next(curr, key) != NULL){
			leaf *change = next(curr, key);
			curr->value = change->value;
			curr->parent = change->parent;
			curr->lchild = change->lchild;
			curr->rchild = change->rchild;
			del(change, change->value);
		}
	}
}

long long prevImg(leaf *curr, long long key){					// search prev that may not exists
	insert(curr, key); 								printf ("insert elem ");

	leaf *state = search(curr, key);
	long long max = -1000000001;
	while (state->parent != NULL){
		if ((state == state->parent->rchild)&&(state->parent->value > max)){
			max = state->parent->value;	printf ("max = %lld", max);
			}
		state = state->parent;
	}
	*state = *search(curr, key);				//delete insert
	del(state, key);
	
	return max;
}

long long nextImg(leaf *curr, long long key){					// search next that may not exists
	insert(curr, key); 								printf ("insert elem ");

	leaf *state = search(curr, key);
	long long min = 1000000001;
	while (state->parent != NULL){
		if ((state == state->parent->lchild)&&(state->parent->value < min)){
			min = state->parent->value;	printf ("min = %lld", min);
			}
		state = state->parent;
	}
	*state = *search(curr, key);				//delete insert
	del(state, key);
	
	return min;
}



int main() {
    ifstream fin("bstsimple.in");
    ofstream fout("bstsimple.out");
    string cmd;
    long long now;
	
	leaf *node = new(leaf); //first leaf
	node->value = -1000000001;
	node->parent = NULL;
	node->lchild = NULL;
	node->rchild = NULL;
	
    while (fin >> cmd) {
    	fin >> now;
    	if (cmd == "insert") 
            insert(node, now);
		else if (cmd == "delete"){
				del(node, now);
		} else if (cmd == "prev"){
				long long answ = prevImg(node, now);
				if (answ == -1000000001)
					fout << "null" << endl;
				else fout << answ;
		} else if (cmd == "next"){
			long long answ = nextImg(node, now);
				if (answ == 1000000001)
					fout << "null" << endl;
				else fout << answ;
		} else if (cmd == "exists"){
			leaf *answ = search(node, now);
			fout << ((answ == NULL) ? "false" : "true") << endl;
		}
    }
    
    return 0;
}
