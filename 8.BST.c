
#include <stdio.h> 
#include <stdlib.h> 

struct tree 
{ 
    char data; 
    struct tree* left; 
    struct tree* right; 
}; 
struct tree* newtree(char data) 
{ 
    struct tree* tree = (struct tree*)malloc(sizeof(struct tree)); 
    tree->data = data; 
    tree->left = NULL; 
    tree->right = NULL; 

    return(tree); 
} 
void Postorder(struct tree* tree) 
{ 
    if (tree == NULL) 
        return; 
    Postorder(tree->left);
    Postorder(tree->right); 
    printf("%c ", tree->data); 
} 
void Inorder(struct tree* tree) 
{ 
    if (tree == NULL) 
        return;
    Inorder(tree->left); 
    printf("%c ", tree->data); 
    Inorder(tree->right); 
} 

void Preorder(struct tree* tree) 
{ 
    if (tree == NULL) 
        return; 
    printf("%c ", tree->data); 
    Preorder(tree->left); 
    Preorder(tree->right); 
}     
int main() 
{ 
    struct tree *root = newtree('A'); 
    root->left = newtree('B'); 
    root->right = newtree('C'); 
    root->left->left = newtree('D'); 
    root->left->right = newtree('E'); 
    /* Sample Tree of Chaacters
	       A
		 /  \ 
	   B     C
	 /  \
	D    E 
	 
	*/

    printf("\nPreorder traversal of binary tree is \n"); 
    Preorder(root); 

    printf("\nInorder traversal of binary tree is \n"); 
    Inorder(root); 

    printf("\nPostorder traversal of binary tree is \n"); 
    Postorder(root); 

    getchar(); 
    return 0; 
} 

