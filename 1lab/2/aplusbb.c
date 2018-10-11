#include <stdio.h>

int main(void)
{
  long long a, b;
  FILE *fin, *fout;
  fin = fopen("aplusbb.in", "r");
  fout = fopen("aplusbb.out", "w");
  fscanf(fin, "%lld%lld", &a, &b);
  fprintf(fout, "%lld", a+b * b);
  fclose(fin);
  fclose(fout);
  return 0;
}
