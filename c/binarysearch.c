#include <stdio.h>
#include <stdlib.h>

int binary(int *vet, int el, int size)
{
    int start = 0;        
    int final = size-1;
    int mid;
    while (start <= final)
    {
        mid = final+start/2;
        if (el == vet[mid])
        {
            return mid;
        }
        if (el < vet[mid])
        {
           final = mid-1;
        }
        else
        {
            start = mid+1;
        }
    }
    return -1;   
}

int main()
{

    FILE *myFile;
    myFile = fopen("list.txt", "r");
    int *array;
    int i, size, result, x;
    printf("insert array size.\n");
    scanf("%d", &size);
    array = malloc(size*sizeof(int)); 
    for (i = 0; i < size; i++)
    {
        fscanf(myFile, "%d", &array[i]);
    }
    printf("insert the element that you want to find\n");
    scanf("%d", &x);
    result=binary(array, x, size);
    if(result==-1)
    {
        printf("not found.\n");
    }
    else
    { 
       printf("the element %d is at %d position\n", array[result], result);
    }

    return 0;

}