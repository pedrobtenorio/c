#include <stdio.h>
#include <stdlib.h>

int main()
{

    FILE *myFile;
    myFile = fopen("list.txt", "r");
    int *array;
    int i, size;
    printf("insert array size.\n");
    scanf("%d", &size);
    array = malloc(size*sizeof(int)); 
    for (i = 0; i < size; i++)
    {
        fscanf(myFile, "%d", &array[i]);
    }
    for (i = 0; i < size; i++)
    {
        printf("Number is: %d\n", array[i]);
    }

    return 0;

}