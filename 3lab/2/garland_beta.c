#include <stdio.h>

float binsearch(float l, float r, int n) 
{
    float h2;
    float A = r;
    int i;
    for (i = 0; i < 100; i++) 
    {
	float curr = (l + r) / 2.0;
	float h0 = A;
	float h1 = curr;
	int neg = 0;
	if (h0 <= 0) 
		neg++;
	if (h1 <= 0) 
		neg++;
	int j;
	for (j = 0; j < n - 2; j++) 
	{
	   h2 = 2.0 * h1 + 2.0 - h0;
	   if (h2 <= 0)
	   {
	       ++neg;
	   }
	   h0 = h1;
	   h1 = h2;
	}
	if (neg >= 1) 
	{
	   l = curr;
	} else r = curr;
   }
    return h2;
}


int main(void)
{
	int i, n;
	float A;
	FILE *fin, *fout;
	fin = fopen("garland.in", "r");
	fout = fopen("garland.out", "w");

	fscanf(fin, "%d %f\n", &n, &A);
	
	fprintf(fout, "%4.2f\n", binsearch(0, A, n));
	
	fclose(fin);
	fclose(fout);
	return 0;
}
