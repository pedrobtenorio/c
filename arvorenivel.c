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

 void print_preorder(no * tree) {
  if (tree) 
  {
    printf(" %d ",tree->valor);
    print_preorder(tree->esquerda);
    print_preorder(tree->direita);
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

void procura(no * tree, int level, int * max, int*  mim,  int procurado, int i) {
  if (tree) 
  {
      if(level==procurado)
      {
          if(tree->valor>max[procurado])
          {
              max[procurado]=tree->valor;
          }
          if(tree->valor<mim[procurado])
          {
              mim[procurado]=tree->valor;
          }
      }
    
    procura(tree->esquerda, level+1, max, mim, procurado, i);
    procura(tree->direita, level+1,max, mim, procurado, i);
  }
 }


int tam(no * tree) 
{
    int max;
    if (tree) 
    {
        int esq= tam(tree->esquerda);
        int dir=tam(tree->direita);
        if(esq>dir)
        {
            max=esq+1;
            return max;
        }
        else
        {
            max=dir+1;
            return max;
        }
    
    }
    
    return 0;
}

int main() 
{
  int n, i, j;
  scanf("%d", &n);
  int matriz[n][3];
  no *raiz=NULL;
  for ( i = 0; i <n ; i++)
  {
    for ( j = 0; j < 3; j++)
    {
      scanf("%d", &matriz[i][j]);
    }
    
  }
  int max[100];
  int mim[100];
  
  
  for ( i = 0; i <= 100; i++)
  {
      max[i]=INT_MIN;
  }
   for ( i = 0; i <= 100; i++)
  {
      mim[i]=INT_MAX;
  }
  raiz=criar_arvore(n, matriz, 0);
  int tamanho;
  tamanho=tam(raiz);
  for (i = 1; i <= tamanho; i++)
  {
    printf("Nivel %d: ", i);
    procura(raiz, 1, max, mim, i,  0);
    printf("Maior = %d, Menor = %d\n", max[i], mim[i]);
    
  }
  
	return 0;
}
