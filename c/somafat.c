#include <stdio.h>

int fat(int n)
{
    if(n==1 || n==0)
    {
        return 1;
    }
    else
    {
        return fat(n-1)*n;
    }
}

int main()
{
    int vetor[4], resultado=0, i;
    for (i = 0; i < 4; i++)
    {
        scanf("%d", &vetor[i]);
        if(vetor[i]%3==0)
        {
            resultado+=fat(vetor[i]);
        }
    }
    printf("%d\n", resultado);
    return 0;
    
}