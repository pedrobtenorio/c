#include <stdio.h>
#include <stdlib.h>
typedef struct arvore no;

struct arvore{
  int valor;
  int altura;
  no* esquerda;
  no* direita;

};

no* criar_no(int item, no* esquerda, no*  direita)
{
  no* novo_no=malloc(sizeof(no));
  novo_no->valor=item;
  novo_no->altura=1;
  novo_no->esquerda=esquerda;
  novo_no->direita=direita;

  return novo_no;
}

int is_empty(no *bt) {
	return bt == NULL;
}

int max(int a, int b) {
	return (a > b) ? a : b;
}

int altura(no * bt)
{
    if(bt==NULL)
    {
        return -1;
    }
    else
    {
        return 1+ max(altura(bt->esquerda), altura(bt->direita));
    }
    
}


no* rr(no* bt)
{
    no *subtree = NULL;
  if(bt!= NULL && bt->esquerda != NULL)
  {
    subtree=bt->esquerda;
    bt->esquerda = subtree->direita;
    subtree->direita=bt;
  }

  subtree->altura=altura(subtree);
  bt->altura=altura(bt);
  return subtree;
}

no* rl(no* bt)
{
   no *subtree = NULL;
  if(bt!= NULL && bt->direita != NULL)
  {
    subtree=bt->direita;
    bt->direita = subtree->esquerda;
    subtree->esquerda=bt;
  }

  subtree->altura=altura(subtree);
  bt->altura=altura(bt);
  return subtree;
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

int is_balanced(no *bt) { 
	if (bt == NULL) {
		return 0; 
	}
	return altura(bt->esquerda) - altura(bt->direita); 
} 

 no* add(no *bt, int item, int *flag, no *aux)
{
    
if (bt == NULL) {
return criar_no(item, NULL, NULL);
} 
if (bt->valor > item) 
{
    bt->esquerda = add(bt->esquerda, item, flag, aux);
} 
else if(bt->valor < item)
{
    bt->direita = add(bt->direita, item, flag, aux);
}
else
{
    return bt;
}

bt->altura= 1+ max(altura(bt->esquerda), altura(bt->direita)); 

int equilibrio=is_balanced(bt);

if(equilibrio>1 || equilibrio<-1)
{
    printf("Antes de ajustar balanceamento...\n");
    printf("  ");
    print_preorder(aux);
    printf("\n");
    *flag=1;

}

if(equilibrio>1 && item < bt->esquerda->valor)
{
    return rr(bt);
}

if(equilibrio<-1 && item > bt->direita->valor)
{
    return rl(bt);
}

if(equilibrio<-1 && item < bt->direita->valor)
{
    bt->direita= rr(bt->direita);
    return rl(bt);
}

if(equilibrio>1 && item > bt->esquerda->valor)
{
    bt->esquerda= rl(bt->esquerda);
    return rr(bt);
}

return bt;


}

int main()
{


  struct arvore *root = NULL;
  no *aux=NULL;
  int n;
  int flag;
  while (scanf("%d", &n)!=EOF)
  {
      flag=0;
      printf("----\n");
      printf("Adicionando %d\n", n);
      aux=root;
      root=add(root, n, &flag, aux);
      if(flag)
      {
        printf("Depois de ajustar balanceamento...\n");
      }
      else
      {
        printf("Continuou AVL...\n");
      }
      printf("  ");
      print_preorder(root);
      printf("\n");
  }
  printf("----\n");
  printf("\n");

}
