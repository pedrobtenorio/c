#include <stdio.h>

int serie(int n, int resultado)
{
    if(n==1)
    {
        resultado+=3;
        return resultado;
    }
    else if(n%2==0 )
    {
        serie(n-1, resultado+4);
    }
    else
    {
        serie(n-1, resultado+1);
    }
}

int main()
{
    int n, resultado=0;
    scanf("%d", &n);
    resultado=serie(n, resultado);
    printf("%d\n", resultado);
}