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
  char *s=(char*)malloc(500*sizeof(char));
  int op=0, cl=0, i=0;
  scanf("%c", &c);
  for(;;)
  {
    if(c != ' ' && c != '\n')
    {
      s[i++] = c;
    }
 
    if(c == '(')
      op++;
    else if(c==')')
      cl++;
 
    if(op==cl)
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


void procura(no * tree, int level, int * resp,  int procurado) {
  if (tree) 
  {
      if(level==procurado)
      {
          if(tree->esquerda==NULL || tree->direita==NULL)
          {
              int i=0;
              for ( i = 0; i < 1000; i++)
              {
                 if(resp[i]==INT_MAX)
                 {
                    resp[i]=tree->valor;
                    break;
                 }
              }
              
          }
         
      }
    
    procura(tree->esquerda, level+1,  resp, procurado);
    procura(tree->direita, level+1, resp, procurado);
  }
 }



int main()
{
  
  char * str, l;
  str=malloc(sizeof(char)*1000); 
  int tam=0, i;
  int resp;
  int tnos=0, cont;
  no* raiz;
  str=read_tree();
  getchar();
  while (strcmp(str, "()")!=0)
  {
      raiz= construct_tree(str, 0);
      print_preorder(raiz);
      str=read_tree();
        getchar();
        
  }
    

  return 0;




}
