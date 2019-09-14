#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    char alfabeto[26]="ABCDEFGHIJKLMNOPQRSTVWXYZ";
    char letras[4];
    int i;
    for ( i = 0; i < 5; i++)
    {
        scanf("%c", &letras[i]);
        letras[i]=toupper(letras[i]);
    }
    for ( i = 0; i < 5; i++)
    {
        printf("%c",letras[i] );
    }
    
    
	return 0;
}