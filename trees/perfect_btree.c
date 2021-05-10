/*
A perfect binary tree is a type of binary tree in which every internal node 
has exactly two child nodes and all the leaf nodes are at the same level.
            1
           / \
          2    3
        /  \  / \
       4   5 6   7
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct  _Node
{
    int data;
    struct _Node *left;
    struct _Node *right;
    
}Node;

Node* newNode(int data)
{
    Node *ptr = (Node*) malloc(sizeof(Node));
    ptr->data = data;    
    ptr->left = NULL;
    ptr->right = NULL;

    return ptr;
}
int is_perfect_binary_tree(Node *root)
{
    int status = -1;
    if (root == NULL)
        status = 0;
    if (root->left == NULL && root->right == NULL)
        status = 0;
    if(root->left != NULL && root->right != NULL)
    {
       if( is_perfect_binary_tree(root->left) == 0 && is_perfect_binary_tree(root->right) == 0)
       {
           status = 0;
       }
       else
       {
           status = 1;
       }
            
    }
    return status;
}
int height_of_tree(Node *root)
{
    int height = 0;
    if(root == NULL)
        return -1;
    if(root->left == NULL && root->right == NULL)
    {
        height = 0; // means only root node present
    }
    else
    {
        while(root->left != NULL)
        {
            height++;
            root = root->left;
        }
    }
    return height;

}

int main()
{
    int ret = -1;
    Node *root = newNode(2);
    root->left = newNode(4);
    root->right = newNode(6);

    root->left->left = newNode(8);
    root->left->right = newNode(10);
    root->right->left = newNode(12);
   root->right->right = newNode(14);
   Node *current =  root->left->left;
   current->left = newNode(16);
   current->right = newNode(18);7

    Node *ref = root;
    int hgt = height_of_tree(root);
    printf("height of the tree is %d\n",hgt);

    //ret = is_full_binary_tree(root);
    (ret == 0)? printf("full binary tree\n"): printf("Not a full binary tree.\n");
    
    return 0;
}