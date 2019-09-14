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

 void print_preorder(no * tree) {
   
  if (tree) 
  {
    printf("(%d ",tree->valor);
    print_preorder(tree->esquerda);
    print_preorder(tree->direita);
    printf(")");
  }
    else
    {
        printf("()");
    }
    
 }

 no* add(no *bt, int item)
{
if (bt == NULL) {
bt = criar_no(item, NULL, NULL);
} else if (bt->valor > item) {
bt->esquerda = add(bt->esquerda, item);
} else {
bt->esquerda = add(bt->direita, item);
}
return bt;
}

int main()
{
  



  struct arvore *root = NULL;

  int n;
  while (scanf("%d", &n)!=EOF)
  {
      printf("----\n");
      printf("Adicionando %d\n", n);
      root=add(root, n);
      print_preorder(root);

  }
  printf("----\n");
  printf("\n");

}
