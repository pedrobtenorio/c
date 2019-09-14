#include <stdio.h>
#include <stdlib.h>
#include <string.h>



struct pilha{
    int tam_atual;
    char items[300];
};

typedef struct pilha pilha;

pilha* criarpilha()
{
    pilha* nova_pilha= malloc(sizeof(pilha));
    nova_pilha->tam_atual=0;
    return nova_pilha;
}

int checar_vazia(pilha *p)
{
    if(p->tam_atual==0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
}



//add item a pilha
void push(pilha* p, char item)
{
    if(p->tam_atual==300)
    {
        printf("stack overflow");
    }
    else
    {
        p->items[p->tam_atual++] = item;
    }
    
}


//remover item do topo
int pop(pilha *p)
{
    if(checar_vazia(p))
    {
        printf("stack underflow");

        return -1;
    }
    else
    {
        return p->items[--p->tam_atual];
    }

}
char peek(pilha *p)
{
    if(checar_vazia(p))
    {
        printf("stack underflow");

        return -1;
    }
    else
    {
        return p->items[p->tam_atual-1];
    }
}

typedef struct Node Node;

struct Node { 
    int data; 
    Node *left, *right; 
};
/* Helper function that allocates a new node */
Node* newNode(int data) 
{ 
    Node* node = (Node*)malloc(sizeof(Node)); 
    node->data = data; 
    node->left = node->right = NULL; 
    return (node); 
} 
  
  
/* This funtcion is here just to test  */
void preOrder(Node* node) 
{ 
    if (node == NULL) 
        return; 
    printf("%d ", node->data); 
    preOrder(node->left); 
    preOrder(node->right); 
} 
  
// functin to return the index of close parenthesis 
int findIndex(char str[], int si, int ei) 
{ 
    if (si > ei) 
        return -1; 
  
    // Inbuilt stack 
    pilha *s;
    s=criarpilha(); 
    char t;
  
    for (int i = si; i <= ei; i++) { 
  
        // if open parenthesis, push it 
        if (str[i] == '(') 
            push(s, str[i]); 
  
        // if close parenthesis 
        else if (str[i] == ')') { 
            if (t=peek(s) == '(') { 
                pop(s); 
  
                // if stack is empty, this is  
                // the required index 
                if (checar_vazia(s)) 
                    return i; 
            } 
        } 
    } 
    // if not found return -1 
    return -1; 
} 
  
// function to construct tree from string 
Node* treeFromString(char str[], int si, int ei) 
{ 
    // Base case 
    if (si > ei) 
        return NULL; 
  
    // new root 
    Node* root = newNode(str[si] - '0'); 
    int index = -1; 
  
    // if next char is '(' find the index of 
    // its complement ')' 
    if (si + 1 <= ei && str[si + 1] == '(') 
        index = findIndex(str, si + 1, ei); 
  
    // if index found 
    if (index != -1) { 
  
        // call for left subtree 
        root->left = treeFromString(str, si + 2, index - 1); 
  
        // call for right subtree 
        root->right = treeFromString(str, index + 2, ei - 1); 
    } 
    return root; 
} 
  
// Driver Code 
int main() 
{ 
    char str[100] = "(4(2(3)(1)) (6(5)))";
    char certa[100];
    int i, j=0;
    for ( i = 1; i < strlen(str)-1; i++)
    {
       if(str[i]!=' ')
        {
            certa[j]=str[i];
            j++;
        }
        
       
    }
    certa[j]='\0';

    Node* root = treeFromString(certa, 0, strlen(certa) - 1); 
    preOrder(root);
    printf("\n");
}