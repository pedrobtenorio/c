#include <stdio.h>


int main()


{
    char caractere;
    int inteiro;
    float Float;
    double Double;
    long int inteirog;
    long long int inteirogg;

    printf("Caractere: %ld byte \n", sizeof(caractere));
    printf("Inteiro: %ld bytes \n", sizeof(inteiro));
    printf("Float: %ld bytes \n", sizeof(Float));
    printf("Double: %ld bytes \n", sizeof(Double));
    printf("Inteiro long: %ld bytes \n", sizeof(inteirog));
    printf("Inteiro long long: %ld bytes \n", sizeof(inteirogg));

    return 0;


}
