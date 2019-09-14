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
            if(v[j]>v[j+1])
            {
                troca(&v[j], &v[j+1]);
            }
        }
        
    }
}

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


no* arvoredestr(char *str, int *pos, int *tnos) {

	no *arvore = NULL; 
	int i = 0;
	int num;       
	char numStr[100]; 
 
	while(str[*pos] == '(' || str[*pos] == ' ') 
    { 
		*pos += 1;
	}

	if(str[*pos] == ')' )
     { 
		*pos += 1;         
		return NULL;
	}
	else {
		while(str[*pos] != '(' ) {    
			numStr[i++] = str[*pos]; 
			*pos += 1;
		}
		numStr[i] = '\0'; 
		num = atoi(numStr);
        *tnos=*tnos+1;
		arvore = criar_no(num, NULL, NULL); 
		arvore->esquerda = arvoredestr(str, pos, tnos); 
		arvore->direita = arvoredestr(str, pos, tnos); 
	}

	*pos += 1;
	return arvore; //retorna o ponteiro para a arvore
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
  
  char * str;
  str=malloc(sizeof(char)*1000); 
  fgets(str, 1000, stdin);
  int tam=0, i;
  int resp[1000];
  int tnos=0;
  for ( i = 0; i < 1000; i++)
  {
      resp[i]=INT_MAX;
  }
  i=1;

  no* raiz= arvoredestr(str, &tam, &tnos);
 //print_preorder(raiz);
 int n;
 n=pf(raiz);
 //printf("\n%d", n);
 int procr=n-1;
 procura(raiz, i, resp, procr);
 int flag=0;
 for ( i = 0; i < 1000; i++)
 {
    if(resp[i]!=INT_MAX)
    {
        flag=1;
        break;
    }

 }

 if(flag)
 {
     printf("nao completa\n");
     bubble_sort(resp, 1000);
    printf("nos com um filho:");
    i=0;
    while (resp[i]!=INT_MAX)
    {
        printf(" %d", resp[i]);
        i++;
    }
    printf("\n");
 }
 else
 {
    printf("completa\n");
    printf("total de nos: %d\n", tnos);
    

 }
 
 

//printf("\n");
 
//printf("\n");



}
