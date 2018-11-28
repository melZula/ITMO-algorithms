#include <stdio.h>

/* объявление типа структуры */
struct struct_type {
int a, b;
char ch;
};

void f1(struct struct_type parm);

int main(void)
{
struct struct_type arg;    /* объявление arg */
arg.a = 1000;
f1(arg);
return 0;
}

void f1(struct struct_type parm) {
printf("%d", parm.a);
}
