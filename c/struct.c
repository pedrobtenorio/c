#include <stdio.h>
#include <stdlib.h>

struct pessoa 
{
    int idade;
    float altura, peso;
    
};

int main()
{
    
    printf("escreva sua idade altura peso)\n");
    struct pessoa pedrinho;
    scanf("%d%f%f", &pedrinho.idade, &pedrinho.altura, &pedrinho.peso);
    printf("%d\n%.2f\n%.2f\n", pedrinho.idade, pedrinho.altura, pedrinho.peso);
    
}