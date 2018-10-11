#include <stdio.h>

int merge(int a[], int p, int q, int r)
{
	int p1, p2, i = 0, j = 0;
	p1 = q-p+1;
	p2 = r-q;
	int L[p1];
	int R[p2];
	int result[p1+p2];
	int *pres;
	pres = &result[0];
	int *pa;
  	pa = &a[0];

	for (i=0; i<p1; i++) // L[0..p1]=A[p..q]
	{
		L[i] = *(pa +p +i);
	}
	for (i=0; i<p2; i++) // R[0..p2]=A[q+1..r]
	{
		R[i] = *(pa +q+1 +i);
	}

	i=0;
									
	int k=0; // index
	while((i<p1)&&(j<p2))	// basic merge
	{
		if (L[i]<R[j])
		{
			*(pres+k) = L[i];
			i++;
		}
		else
		{
			*(pres+k) = R[j];
			j++;
		}
		k++; // index++	
	}
									
	while ((i < p1)||(j < p2)) // final merge
	{
		if (i < p1)
		{
			*(pres+k) = L[i];
			i++;
		}
		else
			if (j < p2)
			{
				*(pres+k) = R[j];
				j++;
			}
		k++;
	}
	for (i=0; i<p1+p2; i++)
	{
		*(pa+p+i) = result[i];
	}						
}
									
									
									

int merge_sort(int a[], int p, int r)
{
	int q;
	if (p < r)
	{
		q = (p+r)/2;
		merge_sort(a, p, q);
		merge_sort(a, q+1, r);
		merge(a, p, q, r);
	}
}



int main(void)
{
  int i, N;
  FILE *fin, *fout;
  fin = fopen("sort.in", "r");
  fout = fopen("sort.out", "w");
  
  fscanf(fin, "%d\n", &N);
  
  int a[N];
  
  
  for (i=0; i<N; i++)
  {
  	fscanf(fin, "%d ", &a[i]);
  }
  
  merge_sort(a, 0, N-1);
  
  for (i=0; i<N; ++i)
  {
  	fprintf(fout, "%d ", a[i]);
  }
  
  fclose(fin);
  fclose(fout);
  return 0;
}
