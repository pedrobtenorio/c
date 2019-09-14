#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

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


char* read_tree()
{
  char c;
  char *s=(char*)malloc(10000*sizeof(char));
  int abrindo=0, fechando=0, i=0;
  scanf("%c ", &c);
  for(;;)
  {
    if(c != ' ' && c != '\n')
    {
      s[i++] = c;
    }

    if(c == '(')
      abrindo++;
    else if(c==')')
      fechando++;

    if(abrindo==fechando)
      break;

    scanf("%c", &c);
  }
  s[i] = '\0';
  return s;
}

no* construct_tree(char *s, int *i)
{
  no *bt=NULL;
  if(s[(*i)++] == '(')
  {
    if(s[*i] == ')')
    {
      (*i)++;
      return NULL;
    }

  char num[100];
  int j=0, x;
  while(s[*i] != '(')
  {
    num[j++] = s[(*i)++];
  }

  num[j]='\0';
  x=atoi(num);

  bt=criar_no(x,NULL,NULL);
  bt->esquerda=construct_tree(s,i);
  bt->direita=construct_tree(s,i);
  }
  (*i)++;
  return bt;
}

void navegar(no* tree, int soma, int acc, int *flag)
{
    int a, b;
    if(tree)
    {
        acc+=tree->valor;
        if(tree->esquerda == NULL && tree->direita==NULL)
        {
            if(acc==soma)
            {
                *flag=1;
            }
        
        }

        navegar( tree->direita,  soma, acc, flag);
        navegar( tree->esquerda,  soma,  acc, flag);
    }
    
}

 int main()
{
  char *str;
  int k=0, soma, flag;
  char lixo;
  scanf("%d ", &soma);

  while(soma != -1000)
  {
      flag=0;
    no *bt=NULL;
    str=read_tree();
    if(strcmp(str,"()")==0)
    {
      printf("nao\n");
    }
    else
    {
        bt=construct_tree(str,&k);
        k=0;
        navegar(bt,soma, 0, &flag);
        if(flag)
        {
          printf("sim\n");
        }
        else
        {
          printf("nao\n");
        }
        
    }
    scanf("%d ", &soma);
   

  }
  return 0;




}
