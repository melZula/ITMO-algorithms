#include <stdio.h>

int binarySearch(int arr[], int l, int r, int x) 
{ 
   if (r >= l) 
   { 
        int mid = l + (r - l)/2; 
  
        if (arr[mid] == x)   
            return mid; 

        if (arr[mid] > x)  
            return binarySearch(arr, l, mid-1, x); 

        return binarySearch(arr, mid+1, r, x); 
   } 
   return -1; 
} 

float bini(float b, int i)
{
	printf("b=%f i=%d\n", b, i);
	return ((b > 1) ? bini(b/2 - 1, ++i) : i );
}

int main(void)
{
	int i, n;
	float A;
	FILE *fin, *fout;
	fin = fopen("garland.in", "r");
	fout = fopen("garland.out", "w");

	fscanf(fin, "%d %f\n", &n, &A);
	
	n--;
	while (A > 1)
	{
		A = A/2 - 1;
		printf("A=%f\n", A);
		n--;
	}
	printf ("n=%d\n", n);
	printf ("bini=%f\n", bini(15, 0));
	
	fclose(fin);
	fclose(fout);
	return 0;
}
