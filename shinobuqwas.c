#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Armazena o primeiro item da fila
typedef struct _stack STACK;

//Armazena o conteudo do no e um ponteiro para o proximo no da fila
typedef struct _node NODE;

struct _stack
{
    NODE* head;
};
struct _node
{
    int element;
    NODE* next;
};

//Cria uma stack com o a head NULL
STACK* Create_stack();

//Recebe um elemento e cria e retorna um novo node
// com o elemento passado
NODE* create_node(int element);

//Verifica se a pilha esta vazia
int IS_EMPTY(STACK* stack);

//Recebe uma pilha e Retorna o elemento que esta no topo da fila
int POP(STACK* stack);

//Recebe uma pilha e um inteiro e retorna a nova pilha
//Adiciona um novo node no topo da pilha
void PUSH(STACK* stack, int element);

//Recebe a pilha e a operacao a ser feita
//faz a operacao da calculadora
void result(STACK* stack, char operation);

//Recebe uma pilha vazia e quantas strings serao lidas
//Le as n strings que vao seguir e resolve as expressoes
void Calculadora(STACK* calculadora, int size);

int main()
{
    STACK* calculadora = Create_stack();
    int k;
    scanf("%d", &k);
    Calculadora(calculadora, k);
    printf("Coordenada 1: %d\n", POP(calculadora));
    scanf("%d", &k);
    Calculadora(calculadora, k);
    printf("Coordenada 2: %d\n", POP(calculadora));

    return 0;

}
//Cria uma stack com o a head NULL
STACK* Create_stack()
{
    STACK* new_stack=(STACK*) malloc(sizeof(STACK));
    new_stack->head=NULL;
    return new_stack;

}

//Recebe um elemento e cria e retorna um novo node
// com o elemento passado
NODE* create_node(int element)
{
    NODE* new_node=(NODE*) malloc(sizeof(NODE));
    new_node->element=element;
    new_node->next=NULL;
    return new_node;
}

//Verifica se a pilha esta vazia
int IS_EMPTY(STACK* stack)
{
    if(stack->head==NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }

}

//Recebe uma pilha e Retorna o elemento que esta no topo da fila
int POP(STACK* stack)
{
  if (stack->head != NULL)
  {
      int aux = stack->head->element;
      stack->head=stack->head->next;
      return aux;
  }
  return -1;
}

//Recebe uma pilha e um inteiro e retorna a nova pilha
//Adiciona um novo node no topo da pilha
void PUSH(STACK* stack, int element)
{
    NODE *new_node = create_node(element);
    NODE *aux;
    if (stack->head != NULL)
    {
      aux = stack->head;
      stack->head = new_node;
      new_node->next = aux;
    }
    else
    {
      stack->head = new_node;
    }

}


//Recebe a pilha e a operacao a ser feita
//faz a operacao da calculadora
void result(STACK* stack, char operation)
{
  int num1, num2;
  num1=POP(stack);
  num2=POP(stack);
  if(operation=='+')
  {
    PUSH(stack, num1+num2);
  }
  else if(operation=='-')
  {
    PUSH(stack, num2-num1);
  }
  else if(operation=='*')
  {
    PUSH(stack, num1*num2);
  }
  else if(operation=='/')
  {
    PUSH(stack, num2/num1);
  }
}


void Calculadora(STACK* calculadora, int size)
{
    int i, num1, num2;
    char op[10];
    for ( i = 0; i < size; i++)
    {
      scanf("%s ", op);
      if(op[0]=='+' || op[0]=='-' || op[0]=='*' || op[0]=='/' )
      {
        result(calculadora, op[0]);

      }
      else
      {
        PUSH(calculadora, atoi(op));
      }
    }
}
