#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

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
            if(v[j]<v[j+1])
            {
                troca(&v[j], &v[j+1]);
            }
        }
        
    }
}
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

int maiordonivel(no * tree, int level, int* v, int i)
{
  if(tree==NULL)
  {
    return i;
  }
  if(level==1)
  {
    v[i]=tree->valor;
    i++;

  }
  else if(level>1)
  {
    maiordonivel(tree->esquerda, level-1, v, i);
    maiordonivel(tree->esquerda, level-1, v, i);
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
}
void print_inorder(no * tree) {
  if (tree) 
  {
    print_inorder(tree->esquerda);
    print_inorder(tree->direita);
  }
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
  int* v;
  v=malloc(sizeof(int)*100);
  raiz=criar_arvore(n, matriz, 0);
  int tamanho=tam(raiz);
  for (i = 1; i <= tamanho; i++)
  {
    //printf("Nivel %d: ", i);
    int m=maiordonivel(raiz, i, v, 0);
    bubble_sort(v, m);
    int a;
    for ( a = 0; a < m; a++)
    {
      printf("%d ", v[a]);
    }
    printf("\n");
    
    //printf("Maior = %d, Menor = %d\n", v[0], v[m]);
  }
  
    



	return 0;
}
