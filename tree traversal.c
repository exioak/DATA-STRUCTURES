#include <stdio.h> 
#include <stdlib.h> 

struct tree 
{ 
    int data; 
    struct tree* left; 
    struct tree* right; 
}; 
struct tree* newtree(int data) 
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
    printf("%d ", tree->data); 
} 
void Inorder(struct tree* tree) 
{ 
    if (tree == NULL) 
        return;
    Inorder(tree->left); 
    printf("%d ", tree->data); 
    Inorder(tree->right); 
} 

void Preorder(struct tree* tree) 
{ 
    if (tree == NULL) 
        return; 
    printf("%d ", tree->data); 
    Preorder(tree->left); 
    Preorder(tree->right); 
}     
int main() 
{ 
    struct tree *root = newtree(1); 
    root->left = newtree(2); 
    root->right = newtree(3); 
    root->left->left = newtree(4); 
    root->left->right = newtree(5); 

    printf("\nPreorder traversal of binary tree is \n"); 
    Preorder(root); 

    printf("\nInorder traversal of binary tree is \n"); 
    Inorder(root); 

    printf("\nPostorder traversal of binary tree is \n"); 
    Postorder(root); 

    getchar(); 
    return 0; 
} 

