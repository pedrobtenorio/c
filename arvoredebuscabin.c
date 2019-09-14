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







int cehcarbst(no *temp, int aux)
{

     if(temp==NULL)
    {
        return 1;
    }  
    if(!cehcarbst(temp->esquerda, aux))
    {
        return 0;
    }
    if(temp->valor<aux)
    {
      return 0;
    }
    aux=temp->valor;

    return cehcarbst(temp->direita, aux);
    
}

no* arvoredestr(char *str, int *pos) {

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

		arvore = criar_no(num, NULL, NULL); 
		arvore->esquerda = arvoredestr(str, pos); 
		arvore->direita = arvoredestr(str, pos); 
	}

	*pos += 1;
	return arvore; //retorna o ponteiro para a arvore
}

int main()
{
  
  char * str;
  char * certa;
  str=malloc(sizeof(char)*400);
  certa=malloc(sizeof(char)*400);
  fgets(str, 400, stdin);
  int tam=0;

  no* raiz= arvoredestr(str, &tam);
 //print_preorder(raiz);

//printf("\n");
    int pos=0;
  int resposta=cehcarbst(raiz, &pos );
  if(resposta)
  {
      printf("VERDADEIRO");
  }
  else
  {
      printf("FALSO");
  }
//printf("\n");



}
