#include <stdio.h>
 
int binsearch_first(long int arr[], int l, int r, int x, int N)
{
   if (r > l)
   {
        int mid = l + (r - l)/2; 
        if ((arr[mid] == x)&&((arr[mid-1] != x)||(mid == 0)))
            return mid + 1;
            
        if (arr[mid] < x)  
        	return binsearch_first(arr, mid+1, r, x, N);
        return binsearch_first(arr, l, mid, x, N);
   }
   return -1;
}
int binsearch_last(long int arr[], int l, int r, int x, int N)
{
   if (r > l)
   {
        int mid = l + (r - l)/2; 
        if (r == l + 1) 
        	mid++;
        if ((arr[mid] == x)&&((arr[mid+1] != x)||(mid == N-1)))
            return mid + 1;

        if (arr[mid] > x)
        	return binsearch_last(arr, l, mid-1, x, N);
		return binsearch_last(arr, mid, r, x, N);
	}
 
   return -1;
}
 
int main(void)
{
  int i, N;
  FILE *fin, *fout;
  fin = fopen("binsearch.in", "r");
  fout = fopen("binsearch.out", "w");
 
  fscanf(fin, "%d\n", &N);
 
  long int a[N];
 
  for (i=0; i<N; i++)
  {
    fscanf(fin, "%ld ", &a[i]);
  }
  fscanf(fin, "\n");
 
  int nreq, req;
  fscanf(fin, "%d\n", &nreq);
 
  for (i=0; i<nreq; i++)
  {
    fscanf(fin, "%d ", &req);
    fprintf(fout, "%d ", binsearch_first(a, 0, N-1, req, N));
    fprintf(fout, "%d\n", binsearch_last(a, 0, N-1, req, N));
  }
 
  fclose(fin);
  fclose(fout);
  return 0;
}
