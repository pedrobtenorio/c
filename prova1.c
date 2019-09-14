#include <stdio.h>
#include <stdlib.h>

void troca(char *a, char *b)
{
    char temp;
    temp=*a;
    *a=*b;
    *b=temp;

}
void bubble_sort(char *v, char n)
{
    int i, j;
    for(i=n-1; i>=0; i--)
    {
        for ( j = 0; j < i; j++)
        {
            if(v[j]>v[j+1])
            {
                troca(&v[j], &v[j+1]);
            }
        }
        
    }
}

int main()
{
    char *num;
    num=malloc(sizeof(char)*4);
    scanf("%s", num);
    bubble_sort(num, 4);
    printf("%s", num);
}