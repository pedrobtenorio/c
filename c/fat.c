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
    int n, resultado=0;
    scanf("%d", &n);
    resultado=fat(n);
    printf("%d", resultado);
    return 0;
}