#include <stdio.h>
#include <stdlib.h>
typedef struct arvore no;

struct arvore{
  int valor;
  no* esquerda;
  no* direita;

};

no* criar_no(int item, no* esquerda, no*  direita)
{
  no* novo_no=malloc(sizeof(no));
  novo_no->valor=item;
  novo_no->esquerda=esquerda;
  novo_no->direita=direita;

  return novo_no;
}

/* no* inserir_direita(no* raiz, int item)
{
  raiz->direita=criar_no(item);
  return raiz->direita;
}

no* inserir_esquerda(no* raiz, int item)
{
  raiz->esquerda=criar_no(item);
  return raiz->esquerda;
}*/

void print_inorder(no * tree) {
  if (tree) 
  {
    print_inorder(tree->esquerda);
    printf(" %d ",tree->valor);
    print_inorder(tree->direita);
  }
 }

int pf(no * tree) 
{
    int max;
    if (tree) 
    {
        int esq= pf(tree->esquerda);
        int dir=pf(tree->direita);
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

 void procura(no * tree, int lvl,   int h) {
 
    int v=8/lvl;
    int f;
    if(lvl=1)
    {
        f=v;
    }
    else
    {
        h=pf(tree);
        f=(2*h)+1;
    }
    
    while (v--)
    {
        printf("_");
    }  

  if (tree) 
  {

    printf("%d",tree->valor);
    while (f--)
    {
        printf("_");
    } 
     printf("\n");
     procura(tree->esquerda, lvl+1,   h);
    procura(tree->direita, lvl+1,  h);
    
  }
  else
    {
        printf("x");
        return;
    }
    
 }
 


 no* add(no *bt, int item)
{
    
if (bt == NULL) {
bt = criar_no(item, NULL, NULL);
} 
else if (bt->valor > item) 
{
    bt->esquerda = add(bt->esquerda, item);
} 
else 
{
    bt->direita = add(bt->direita, item);
}
return bt;
}



int main()
{
  
  struct arvore *root = NULL;

  int n, tam, altura, lvl;
  scanf("%d", &tam);
  while (scanf("%d", &n)!=EOF)
  {
      root=add(root, n);
      
  }
   altura=pf(root);
      procura(root, 0, altura);
      printf("\n");
  printf("\n");
    lvl=0;
}
