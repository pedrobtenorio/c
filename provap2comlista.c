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


no* criar_arvore(int n, int matriz[n][2], int x, int cont)
{
  no * novo;
  int aux=x;
  novo=malloc(sizeof(no));
  novo->valor=cont;
  if(x==-1)
  {
    return NULL;
  }
  x=matriz[x][0];
  novo->esquerda=criar_arvore(n, matriz, x, cont+1);
  x=matriz[aux][1]; 
  novo->direita=criar_arvore(n, matriz, x, cont+1);
  
  return novo;
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
  int matriz[n][2];
  no *raiz=NULL;
  for ( i = 0; i <n ; i++)
  {
    for ( j = 0; j < 2; j++)
    {
      scanf("%d", &matriz[i][j]);
    }
    
  }
 
  raiz=criar_arvore(n, matriz, 0, 0);
  int tamanho;
  tamanho=tam(raiz);
  
  
	return 0;
}
