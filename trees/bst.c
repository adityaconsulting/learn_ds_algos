#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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
Node* insert_bst(int data,Node *root)
{
    //printf("dats is %d\n",data);
    if(root == NULL)
    {
        root = newNode(data);
    }
    else if(data < root->data )
    {
        root->left = insert_bst(data,root->left);
    }
    else
    {
        root->right = insert_bst(data,root->right);
    }
    return root;
}
void insert_bst_norecursion(int data, Node **root)
{
    //printf("in func data is %d\n",data);
    Node *new = (*root);
    
    if( new == NULL)
    {
        //printf("first node\n");
        new = newNode(data);
    }
    else
    {
        //printf("non -- first node\n");

        while( new != NULL)
        {
            if( data < new->data )
            {
                
                if(new->left == NULL)
                {
                    new->left =  newNode(data);
                    //printf("left assigned %d \n",data);
                    break;
                }
                else
                {
                    new = new->left;
                }
            }
            else
            {
                 
                if(new->right == NULL)
                {
                    //printf("right assigned %d \n",data);
                    new->right = newNode(data);
                    break;
                }
                {
                    new = new->right;
                }
            }
        }
    }    
}
int inorder_travarsal(Node *root)
{
    if(root == NULL)
        return 0;
    inorder_travarsal(root->left);
    printf("%d ",root->data);
    inorder_travarsal(root->right);

}
void delete_node_norecursion(int data,Node **root)
{
    Node *tmp = (*root);
     
    while(tmp->data != data)
    {
        if(data < tmp->data )
        {
            tmp = tmp->left;
        }
        else
        {
            tmp = tmp->right;
        }
    }
    printf("element found %d\n",data);
    if(tmp->left == NULL && tmp->right == NULL)
    {
        Node *temp = (*root);
        while(temp != NULL)
        {
            if(data < temp->data )
            {
                if(temp->left->data == data)
                {
                    printf("left -- found the leaf node to delete %d\n",data);
                    free(temp->left);
                    temp->left = NULL;
                    break;
                }
                else
                    temp = temp->left;
            }
            else
            {
                 if(temp->right->data == data)
                {
                    printf("right -- found the leaf node to delete %d\n",data);
                    free(temp->right);
                    temp->right = NULL;
                    break;
                }
                else
                    temp = temp->right;
            }
            
        }
        
    }
    else if(tmp->left != NULL && tmp->right == NULL)
    {
        printf("left node present\n");
        
    }
    else if(tmp->left == NULL && tmp->right != NULL)
    {
        printf("right node present\n");
       
       
    }
    else
        printf("internal node\n");
}
int main()
{
    int arr[] = {23,4,5,11,34,78,7,56,9,15,45,90},ind=1,idx=0;
    
    Node *ref = newNode(23);
    int len = sizeof(arr)/sizeof(arr[0]);
    Node *temp= NULL;
    while(ind < len )
    {
        
        insert_bst_norecursion(arr[ind++],&ref);
    }
    while (idx <len)
    {
        temp = insert_bst(arr[idx++],temp);
    }
    printf("with recursion\n");
    inorder_travarsal(temp);
    printf("with out recursion\n");
    inorder_travarsal(ref);
    /*ind = 0;
    while (ind < len )
    {
        delete_node_norecursion(arr[ind++],&ref);
    }*/
    delete_node_norecursion(90,&ref);
     inorder_travarsal(ref);
     delete_node_norecursion(45,&ref);
     inorder_travarsal(ref);
    
    return 0;
}