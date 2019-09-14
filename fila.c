#include <stdio.h> 
#include <stdlib.h> 
#include <limits.h> 

#define tammax 300
  
struct fila
{ 
    int comeco, fim, tam; 
    int array[tammax]; 
}; 
  
typedef struct fila fila;

fila* criarfila() 
{ 
    fila* nova_fila = (fila*) malloc(sizeof(fila)); 
    nova_fila->comeco =  0;
    nova_fila->tam = 0; 
    nova_fila->fim = tammax - 1;    
    return nova_fila; 
} 
  
 
int isFull(fila* f) 
{  return (f->tam == tammax);  } 
  

int isEmpty(fila* f) 
{  return (f->tam == 0); } 
  

void enfileirar(fila* f, int item) 
{ 
    if (isFull(f)) 
        return; 
    f->fim = (f->fim + 1)%tammax; 
    f->array[f->fim] = item; 
    f->tam = f->tam + 1; 
    printf("%d enfileirarado to f\n", item); 
} 
  
int desenfireilar(fila* f) 
{ 
    if (isEmpty(f)) 
        return INT_MIN; 
    int item = f->array[f->comeco]; 
    f->comeco = (f->comeco + 1)%tammax; 
    f->tam = f->tam - 1; 
    return item; 
} 
  
 
int comeco(fila* f) 
{ 
    if (isEmpty(f)) 
        return INT_MIN; 
    return f->array[f->comeco]; 
} 
  

int fim(fila* f) 
{ 
    if (isEmpty(f)) 
        return INT_MIN; 
    return f->array[f->fim]; 
} 
  
int main() 
{ 
    fila* f = criarfila(); 
  
    enfileirar(f, 10); 
    enfileirar(f, 20); 
    enfileirar(f, 30); 
    enfileirar(f, 40); 
  
    printf("%d desenfireilado da fila\n\n", desenfireilar(f)); 
  
    printf("item do começo é %d\n", comeco(f)); 
    printf("item do fim é %d\n", fim(f)); 
  
    return 0; 
} 
