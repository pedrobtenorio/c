#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct arvore no;

struct arvore{
  int valor;
  no* esquerda;
  no* direita;

};

no* criar_no(int item, no* esquerda, no* direita)
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

 no* criararvore(char *chararovre, int *posicao)
{
    if(strlen(chararovre) == *posicao) return NULL;
    while (chararovre[*posicao] == ' ' || chararovre[*posicao] == '(')
    {
        (*posicao)++;
    }
    if (chararovre[*posicao] == ')')
    {
        while (chararovre[*posicao] == ')')
        {
            (*posicao)++;
        }
        return NULL;
    }
    char num[256];
    int flag = 0;
    while (chararovre[*posicao] >= '0' && chararovre[*posicao] <= '9')
    {
        num[flag] = chararovre[*posicao];
        flag++;
        (*posicao)++;
    }
    num[flag] = '\0';
    long long int k;
    k = atoi(num);
    return criar_no(k,criararvore(chararovre, posicao), criararvore(chararovre, posicao));
}

int procurarno(no *temp, int value)
{
    int flage, flagd;
    if(temp==NULL)
    {
      //printf("NAO ESTA NA ARVORE\n");
      return -100000;
    }
    

        if(temp->valor == value)
        {
            
            return 0;
        }
        
        
         flage=procurarno(temp->esquerda, value);
    flagd=procurarno(temp->direita, value);
    if(flage>=flagd)
    {
        return flage+1;
    }
    else
    {
        return flagd+1;
    }
    
    
}

int main()
{
  char* arvore;
  arvore=malloc(sizeof(char)*300);
  int pos = 0;
  int n, len;
  no* root=NULL;
  fgets(arvore, 300, stdin);
  len=strlen(arvore);
  scanf("%d", &n);
  root=criararvore(arvore, &pos);
  int resposta=procurarno(root, n);
  if(resposta>=0)
  {
      printf("ESTA NA ARVORE\n%d\n", resposta);
  }
  else
  {
      printf("NAO ESTA NA ARVORE\n-1\n");
  }
  
  print_preorder(root);
 

}
