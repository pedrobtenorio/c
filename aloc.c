#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *vetor;
    int i, tamanho;
    printf("Insira o tamanho do vetor e em seguida seus elementos\n");
    scanf("%d", &tamanho);
    vetor =  malloc(tamanho* sizeof(int));//aloca dinamicmente a quantidade necessaria de memoria 
    for ( i = 0; i < tamanho; i++)
    {
        scanf("%d", &vetor[i]);
    }
    for ( i = 0; i < tamanho; i++)
    {
        printf("elemento %d:  %d\n", i, vetor[i]);
    }
    free(vetor);//libera a memoria
    return 0;
}