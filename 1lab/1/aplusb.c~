#include <stdio.h>

int main(void)
{
  long a, b;
  FILE *fin, *fout;
  fin = fopen("aplusb.in", "r");
  fout = fopen("aplusb.out", "w");
  fscanf(fin, "%ld%ld", &a, &b);
  fprintf(fout, "%ld", a + b);
  fclose(fin);
  fclose(fout);
  return 0;
}
