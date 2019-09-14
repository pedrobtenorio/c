#include <stdio.h>
#include <stdlib.h>
typedef struct arvore no;

struct arvore{
  void* valor;
  int frequency;
  no* esquerda;
  no* direita;

};

no* criar_no(int item, int esquerda, int direita)
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
    printf(" %d ",tree->valor);
    print_preorder(tree->esquerda);
    print_preorder(tree->direita);
  }
 }

 no *createTree(char *tree_t, int *position)
{
    if(strlen(tree_t) == *position) return NULL;
    while (tree_t[*position] == ' ' || tree_t[*position] == '(')
    {
        (*position)++;
    }
    if (tree_t[*position] == ')')
    {
        while (tree_t[*position] == ')')
        {
            (*position)++;
        }
        return NULL;
    }
    char num[256];
    int pos = 0;
    while (tree_t[*position] >= '0' && tree_t[*position] <= '9')
    {
        num[pos] = tree_t[*position];
        pos++;
        (*position)++;
    }
    num[pos] = '\0';
    long long int k;
    k = atoi(num);
    return criar_no(k,createTree(tree_t, position), createTree(tree_t, position));
}

int main()
{
  



  struct arvore *root = NULL;
  int *pos = 0;

  print_inorder(root);
  printf("\n");
  print_preorder(root);
  printf("\n");

}
