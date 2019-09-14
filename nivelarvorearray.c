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


no* criar_arvore(int item, no* esq, no* dir)
{
  no *novo_no = (no*)malloc(sizeof(no));
  novo_no->valor = item;
  novo_no->esquerda = esq;
  novo_no->direita = dir;
  return novo_no;
}


 void print_preorder(no * tree) {
  if (tree) 
  {
    printf(" %d ",tree->valor);
    print_preorder(tree->esquerda);
    print_preorder(tree->direita);
  }
 }

int main() 
{
  int n;
  scanf("%d", &n);
  no **nos=(no**)malloc(sizeof(no*)*n);
  no* raiz=NULL;
  int i;
  for ( i = 0; i < n; i++)
  {
    nos[i]=NULL;
  }
  int valorno, filhod, filhoe;
  for ( i = 0; i < n; i++)
  {

    scanf("%d%d%d", &valorno, &filhoe, &filhod);
    if(filhoe==-1 && filhoe==-1)
    {
      raiz=criar_arvore(valorno, NULL, NULL);
    }
    else if(filhoe==-1)
    {
      raiz=criar_arvore(valorno, NULL, nos[filhod]);
    }
    else if(filhod==-1)
    {
      raiz=criar_arvore(valorno, nos[filhoe], NULL);
    }

    else
    {
      raiz=criar_arvore(valorno, nos[filhoe], nos[filhod]);
    }
    nos[i]=raiz;
    nos[i]->esquerda=nos[filhoe];
    nos[i]->direita= nos[filhod];
  }
  
  for ( i = 0; i < n; i++)
  {
    printf("%d\n", nos[i]->valor);
  }
  printf("----------------\n");
  print_preorder(nos[0]);
  



	return 0;
}
