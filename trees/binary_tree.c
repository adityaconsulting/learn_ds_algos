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

int main()
{
    Node *root = newNode(2);
    root->left = newNode(4);
    root->right = newNode(6);

    root->left->left = newNode(8);
    root->left->right = newNode(10);

    Node *ref = root;

    printf("right nodes\n");
    while(ref != NULL)
    {
        printf("%d ",ref->data);
        ref = ref->right;
    }
    printf("left nodes\n");
    ref = root;
    while(ref != NULL)
    {
        printf("%d ",ref->data);
        ref = ref->left;
    }
    return 0;
}