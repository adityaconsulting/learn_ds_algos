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

int inorder_travarsal(Node *root)
{
    if(root == NULL)
        return 0;
    inorder_travarsal(root->left);
    printf("%d ",root->data);
    inorder_travarsal(root->right);

}

int preorder_travarsal(Node *root)
{
    if(root == NULL)
        return 0;
    printf("%d ",root->data);
    preorder_travarsal(root->left);
    preorder_travarsal(root->right);

}

int postorder_travarsal(Node *root)
{
    if(root == NULL)
        return 0;   
    postorder_travarsal(root->left);
    postorder_travarsal(root->right);
    printf("%d ",root->data);

}


int main()
{
    Node *root = newNode(2);
    root->left = newNode(4);
    root->right = newNode(6);

    root->left->left = newNode(8);
    root->left->right = newNode(10);

    Node *ref = root;
    printf("in-order traversal\n");
    inorder_travarsal(ref);
    printf("\npre-order traversal\n");  
    preorder_travarsal(ref);
    printf("\npost-order traversal\n");
    postorder_travarsal(ref);
    return 0;
}