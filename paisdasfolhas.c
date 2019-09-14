#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

 typedef struct arvore no;

struct arvore{
  int valor;
  no* esquerda;
  no* direita;

};

void troca(int *a, int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;

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

  void print_preorder(no * tree) {
   
  if (tree) 
  {
    printf("  ");
    printf(" ( %d ",tree->valor);
    print_preorder(tree->esquerda);
    print_preorder(tree->direita);
    printf(") ");
  }
    else
    {
        printf(" () ");
    }
  }


no* criar_arvore(int n, int matriz[n][3], int x)
{
  no * novo;
  int aux=x;
  if(x==-1)
  {
    return NULL;
  }
  novo=malloc(sizeof(no));
  novo->valor=matriz[x][0];
  x=matriz[x][1];
  novo->esquerda=criar_arvore(n, matriz, x);
  x=matriz[aux][2]; 
  novo->direita=criar_arvore(n, matriz, x);
  
  return novo;
}
void navegar(no* arvore, int  pais[], int  *i)
{
    int flag=1;
    
  if(arvore)
  {
    if(arvore->direita!=NULL )  
    {
        if(arvore->direita->direita==NULL && arvore->direita->esquerda==NULL)
        {
            printf("valor q deveria entrar %d\n", arvore->valor);
            pais[*i]=arvore->valor;
            (*i)++;
            flag=0;
        } 
    }
    if(arvore->esquerda!=NULL && flag)
    {
        if(arvore->esquerda->esquerda==NULL && arvore->esquerda->direita==NULL)
        {
            printf("valor q deveria entrar %d\n", arvore->valor);
            pais[*i]=arvore->valor;
            (*i)++;
        }
    }
        
    navegar(arvore->esquerda, pais, i);
    navegar(arvore->direita, pais, i);
  }
  return;
}


int main() 
{
  int n, i, j, contm;
  scanf("%d", &n);
  int pais[n];
  for ( i = 0; i < n; i++)
  {
    pais[i]=INT_MAX;
  }
  
  int matriz[n][3];
  no *arvore=NULL;
  for ( i = 0; i <n ; i++)
  {
    for ( j = 0; j < 3; j++)
    {
      matriz[i][0]=contm;
     
    }
     contm++;
  }

  for ( i = 0; i <n ; i++)
  {
    for ( j = 0; j < 2; j++)
    {
      scanf("%d", &matriz[i][j+1]);
    } 
  }
  arvore=criar_arvore(n, matriz, 0);

  navegar(arvore, pais, 0);
  for ( i = 0; i < n; i++)
  {
    printf("%d\n", pais[i]);
  }
  

  
	return 0;
}
