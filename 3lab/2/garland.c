#include <stdio.h>

int realz;
double h_prev=10000;

double binsearch(int l, int r, double a)
{
	int zero;
	zero = (l + r) / 2;
	int n = zero - 1;

	if (a/(n+1) - n == h_prev)
	{
		realz = zero;
		return h_prev;
	}
	h_prev = (a/(n+1) - n);
	if (h_prev > 0)
	{
		realz = zero;
		binsearch(zero+1, r, a);
	}
	else
		binsearch(l, zero-1, a);
		
	return h_prev;
}

int main(void)
{
	int i, n;
	double A, h0, h1, h2;
	FILE *fin, *fout;
	fin = fopen("garland.in", "r");
	fout = fopen("garland.out", "w");

	fscanf(fin, "%d %lf\n", &n, &A);
	
	h1 = binsearch(1, n-1, A);
	h2 = 0;
	for (i = realz+1; i<n; i++)
	{
		h0 = h1;
		h1 = h2;
		h2 = 2*h1 + 2 - h0;
	}
	
	fprintf(fout, "%4.2f\n", h2);

	fclose(fin);
	fclose(fout);
	return 0;
}
