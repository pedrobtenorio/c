#include <stdio.h>
#include <stdlib.h>

typedef struct binary_tree{
    int item;
    struct binary_tree* left;
    struct binary_tree* right;
}Tree;



Tree* newleaf(int item, Tree* left, Tree* right)
{
    Tree* new_tree = (Tree*) malloc(sizeof(Tree));
    new_tree->item = item;
    new_tree->left = left;
    new_tree->right = right;
    return new_tree;
}

Tree* construct_binary_tree(char *str, int *pos) {

	Tree *btree = NULL; //ponteiro para a arvore
	int i = 0;
	int numInt;       //numero do no (inteiro)
	char numStr[100];  //numero do no (string)
 
	while(str[*pos] == '(') { //ignora os parenteses abrindo
		*pos += 1;
	}

	if(str[*pos] == ')') { //se encontrar parentese fechando, retorna null
		*pos += 1;         // pois o ponteiro eh nulo
		return NULL;
	}
	else {
		while(str[*pos] != '(') {    //se for diferente de abre parenteses
			numStr[i++] = str[*pos]; //le o numero string
			*pos += 1;
		}
		numStr[i] = '\0'; //finalizando a string com '/0'
		numInt = atoi(numStr); //converte o numero string para inteiro

		btree = newleaf(numInt, NULL, NULL); //cria um no com o numero inteiro
		btree->left = construct_binary_tree(str, pos);  //constroi a arvore para o no esquerdo
		btree->right = construct_binary_tree(str, pos); //constroi a arvore para o no direito
	}

	*pos += 1;
	return btree; //retorna o ponteiro para a arvore
}

int isBST(Tree * root) 
{ 
    static Tree *prev = NULL;
      
    // traverse the tree in inorder fashion and keep track of prev node 
    if (root) 
    { 
        if (!isBST(root->left)) 
          return 0; 
  
        // Allows only distinct valued nodes  
        if (prev != NULL && root->item <= prev->item) 
          return 0; 
  
        prev = root; 
  
        return isBST(root->right); 
    } 
  
    return 1; 
}

int main()
{
    Tree * arvore;
    int p=0;
    char * str;
    str=malloc(sizeof(char)*400);
    fgets(str, 400, stdin);

    arvore = construct_binary_tree(str, &p);
    if (isBST(arvore)) printf("verdadeiro\n");
    else printf("falso\n");
}