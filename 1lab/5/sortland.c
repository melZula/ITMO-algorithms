#include <stdio.h>
#define SWAP(A, B) { float t = A; A = B; B = t; }

int main(void)
{
  int i, n, m, x, s, l;         //i: index; x, m: for sort; n: size; s - smallest; m - middle; l- largest
  FILE *fin, *fout;
  fin = fopen("sortland.in", "r");
  fout = fopen("sortland.out", "w");
  fscanf(fin, "%d\n", &n);

  float M[n], origin[n];
  for (i=1; i<n+1; ++i)    //reading
  {
		fscanf(fin, "%e", &M[i]);	
		origin[i]=M[i];
	}

	x=n; //size
  do{												//sort
		m=0;
  	for (i=1; i<x+1; i++)
  	{
  		if (M[i-1]>M[i])
  		{
				SWAP(M[i-1],M[i]);
				m=i;
  		}
  	}
  	x=m;    //last ordered
  }while (x!=0);
 
  for (i=1; i<n+1; ++i)   //finding indexes 
  {
  	if (origin[i]==M[1])
  		s=i;
  	if (origin[i]==M[n/2+1])
  		m=i;
  	if (origin[i]==M[n])
  		l=i;
  }
    
  fprintf(fout, "%d %d %d", s, m, l);
  fclose(fin);
  fclose(fout);
  return 0;
}
