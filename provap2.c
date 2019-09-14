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

void print_inorder(no * tree, int* in) {
  if (tree) 
  {
    int i;
    
    
    print_inorder(tree->esquerda, in);
    for ( i = 0; i < 1000; i++)
    {
      if(in[i]==INT_MAX)
        {
          in[i]=tree->valor;
          break;
        }
    }
    print_inorder(tree->direita, in);

  }
 }

 void print_preorder(no * tree, int* pre) {
  if (tree) 
  {
    for ( i = 0; i < 1000; i++)
    {
      if(pre[i]==INT_MAX)
        {
          pre[i]=tree->valor;
          break;
        }
    }
    print_preorder(tree->esquerda, pre);
    print_preorder(tree->direita, pre);
  }
 }

  void print_post(no * tree, int* pos) {
  if (tree) 
  { 
    print_post(tree->esquerda, pos);
    print_post(tree->direita, pos);
    for ( i = 0; i < 1000; i++)
    {
      if(pos[i]==INT_MAX)
        {
          pos[i]=tree->valor;
          break;
        }
    }

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
      if(j==0)
      {
        matriz[i][j]=i;
      }
      else
      {
        scanf("%d", &matriz[i][j]);
      }
      
      
    }
    
  }


  
  
  
 
  raiz=criar_arvore(n, matriz, 0);
  int tamanho;
  int in[1000];
  int pre[1000];
  int pos[1000];
  for ( i = 0; i < 1000; i++)
  {
      in[i]=INT_MAX;
      pre[i]=INT_MAX;
      pos[i]=INT_MAX;
  }
  print_preorder(raiz, pre);
  printf("\n");
  print_post(raiz, pos);
   printf("\n");
  print_inorder(raiz, in);
  int prev, next;
  for ( i = 0; i < 100; i++)
  {
    if(i-1>0)
    {
      prev=-1
    }
    else
    {
      prev=pre[i-1];
    }
    if(i+1==INT_MAX)
    {
      next=-1;
    }
    
    
    printf("Node %d: previous = %d next = %d", i, )
  }
  
  
	return 0;
}
