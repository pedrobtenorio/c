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


no* criar_no(int item)
{
    no* novo_no=malloc(sizeof(no));
    novo_no->valor=item;
    novo_no->direita=NULL;
    novo_no->esquerda=NULL;

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

int direita(int i)
{
  return (i*2)+1;
}
int esquerda(int i)
{
  return (i*2);
}

int maior(int x,int y)
{
  return x >= y ? x : y;
}

int p(no * arvore)
{
  if(arvore->direita==NULL && arvore->esquerda==NULL)
  {
    return arvore->valor;
  }
  else
  {
    
    return maior(arvore->valor*p(arvore->direita), arvore->valor*p(arvore->esquerda) );
  }
}

int main()
{
  int i=1, aux, h, array[1000];
  no* nos[1000];
  scanf("%d", &h);
  printf("%d\n", h);
  while (scanf("%d", &array[i]) != EOF)
	{
	    nos[i] = criar_no(array[i]);
	    i++;
	}

  for ( aux = 1; aux <= i; aux++)
  {
    if(nos[aux]!=NULL)
    {
      nos[aux]->direita=nos[direita(aux)];
      nos[aux]->esquerda=nos[esquerda(aux)];
    }
    
  }
  int resp=p(nos[1]);

  printf("%d", resp);

}
