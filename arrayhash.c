#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int func_hash(int indice, int cont_entrada, int pos)
{
    int key=indice+cont_entrada+pos;
    return key;
}

int alfabetocont(char alfabeto[25], char letra)
{
    int i=0;
    for ( i = 0; i < 25; i++)
    {
       if(letra==alfabeto[i])
       {
           return i;
       }
    }
    
}

int main()
{
    int casos, total, entradas, cont, i, n, posalfa;
    char alfabeto[25]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char palavra[100];
    scanf("%d", &casos);
    while (casos--)
    {
        total=0;
        cont=0;
        scanf("%d", &entradas);
        while (entradas--)
        {
            scanf("%s", palavra);
            n=strlen(palavra);
            for ( i = 0; i < n; i++)
            {
                posalfa=alfabetocont(alfabeto, palavra[i]);
                total=total+func_hash(i, cont, posalfa);

            }
            cont++;    
        }
        printf("%d\n", total);

    }
    
}