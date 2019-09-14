#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void unidade(int n)
{
  printf("Algarismo das unidades: %d\n",  n%10);
}

int main() {
  printf("Digite um numero:\n");
  int n;
  unidade(n);
	return 0;
}
