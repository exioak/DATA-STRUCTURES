#include <stdio.h> 
#include <stdlib.h> 
struct node  
{ 
    int data; 
    struct node* left; 
    struct node* right; 
}; 
unsigned int getLeafCount(struct node* node) 
{ 
  if(node == NULL)        
    return 0; 
  if(node->left == NULL && node->right==NULL)       
    return 1;             
  else 
    return getLeafCount(node->left)+ 
           getLeafCount(node->right);       
} 
struct node* newNode(int data)  
{ 
  struct node* node = (struct node*) 
                       malloc(sizeof(struct node)); 
  node->data = data; 
  node->left = NULL; 
  node->right = NULL; 
    
  return(node); 
} 

int countNonleaf(struct node* node) 
{ 
    if (node == NULL || (node->left == NULL && node->right == NULL)) 
        return 0; 
    return (1 + countNonleaf(node->left) + countNonleaf(node->right)); 
}


int main() 
{ 
  struct node *root = newNode(1); 
  root->left        = newNode(2); 
  root->right       = newNode(3); 
  root->left->left  = newNode(4); 
  root->left->right = newNode(5);     
  printf("Leaf count of the tree is %d \n", getLeafCount(root)); 
  printf("Non Leaf count of the tree is %d", countNonleaf(root)); 
    
  getchar(); 
  return 0; 
} 
