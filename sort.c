#include <stdio.h>
#include <stdlib.h>

void troca(int *a, int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;

}
void selection_sort(int *v, int n)
{
    int i, j, min;
    for ( i = 0; i < n; i++)
    {
        min=i;
        for ( j = i+1; j<n; j++)
        {
            if(v[j]<v[min])
            {
                min=j;
            }
            troca(&v[i], &v[min]);
        }
        
    }
    
}
void bubble_sort(int *v, int n)
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
void quicksort(int *values, int began, int end)
{
	int i, j, pivo, aux;
	i = began;
	j = end-1;
	pivo = values[(began + end) / 2];
	while(i <= j)
	{
		while(values[i] < pivo && i < end)
		{
			i++;
		}
		while(values[j] > pivo && j > began)
		{
			j--;
		}
		if(i <= j)
		{
			aux = values[i];
			values[i] = values[j];
			values[j] = aux;
			i++;
			j--;
		}
	}
	if(j > began)
		quicksort(values, began, j+1);
	if(i < end)
		quicksort(values, i, end);
}
void insertion_sort(int *v, int n)
{
    int i, j, chave;
    for ( i = 1; i < n; i++)
    {
        chave = v[i];
        j=i-1;
        while (j>=0 && v[j]>chave)
        {
            v[j+1]=v[j];
            j--;
        }
        v[j+1]=chave;

    }
    
}

int main()
{
    FILE *myFile;
    myFile = fopen("list.txt", "r");
    int *array;
    int i, size, x;
    printf("insert array size.\n");
    scanf("%d", &size);
    array = malloc(size*sizeof(int)); 
    for (i = 0; i < size; i++)
    {
        fscanf(myFile, "%d", &array[i]);
    }
    fail:
    printf("choose the sorting algorithym\n1 bubble\n2 selection\n3 quick\n4 insertion\n");
    scanf("%d", &x);
    if(x>4 || x<1)
    {
        goto fail;
    }
    else if(x==1)
    {
        bubble_sort(array, size);
    }
    else if(x==2)
    {
        selection_sort(array, size);
    }
    else if(x==3)
    {
        quicksort(array, size, 0);
    }
    else
    {
        insertion_sort(array, size);
    }

    for ( i = 0; i < size; i++)
    {
        printf("%d\n", array[i]);
    }
        
}