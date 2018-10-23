#include <stdio.h>
#define SWAP(A, B) { int t = A; A = B; B = t; }

int siftDown (long long arr[], int i, int n)
{
	if (i < n/2)
	{
		if ((arr[i] < arr[2*i+1])&&(!(2*i+2 < n)||(arr[2*i+1] > arr[2*i+2]))) // a*(b->c)
		{
			SWAP(arr[i], arr[2*i+1]);
			if (2*i+1 < n/2)
				siftDown (arr, 2*i+1, n);
		}
		else
		{
			if ((arr[i] < arr[2*i+2])&&(2*i+2 < n))
			{
				SWAP (arr[i], arr[2*i+2]);
				if (2*i+2 < n/2)
					siftDown (arr, 2*i+2, n);
			}
		}
		i++;
	}
}

int buildHeap (long long arr[], int n)
{
	int i;
	for (i = n/2-1; i>=0; i--)
		siftDown(arr, i, n);
}

int heapsort(long long arr[], int n)
{
	int i;
	int heapsize = n;
	buildHeap(arr, n);
	for (i = 0; i < n-1; i++)
	{						
		SWAP(arr[0], arr[n-1-i]);
		heapsize--;
		siftDown(arr, 0, heapsize);
	}
}

int main(void)
{
	int i, n;
	FILE *fin, *fout;
	fin = fopen("sort.in", "r");
	fout = fopen("sort.out", "w");

	fscanf(fin, "%d\n", &n);
	long long a[n];

	for (i = 0; i<n; i++)
		fscanf(fin, "%lld ", &a[i]);
		
	heapsort(a, n);
	
	for (i = 0; i<n; i++)
		fprintf(fout, "%lld ", a[i]);
		
	fclose(fin);
	fclose(fout);
	return 0;
}
