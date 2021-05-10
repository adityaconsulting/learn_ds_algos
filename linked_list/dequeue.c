#include<stdio.h>
#include<stdlib.h>
#include<strings.h>
typedef struct _node
{
    int data;
    struct _node *next;
}Node,*Nodeptr;
 

int addnode_front(Node **ref,int data)
{
    Nodeptr p=NULL,*q = ref,temp;
    //printf("%d ",(*q)->data);
    p = (Node*)malloc(sizeof(Node));
    p->next = NULL;
    p->data = data;
    if(*q == NULL)
    {
        *q =p;
    }
    else
    {
        temp = *q;
        p->next = temp;
        *q = p;
        
    }  
return 0;
   
}
int addnode_rear(Node **ref,int data)
{
    Nodeptr p=NULL,*q = ref,temp;
    //printf("%d ",(*q)->data);
    p = (Node*)malloc(sizeof(Node));
    p->next = NULL;
    p->data = data;
    if(*q == NULL)
    {
        *q =p;
    }
    else
    {
        temp = *q;
        while( temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = p;
        
    }  
return 0;
   
}
int removenode_front(Node **ref)
{
    Nodeptr ptr=(*ref);
    if(ptr->next == NULL)
    {
        printf("only head node ----removing\n");
        free(ptr);
        (*ref) = NULL;
    }
    else
    {
        (*ref) = (*ref)->next;
        free(ptr);

    }
return 0;
}

int removenode_rear(Node **ref)
{
    Nodeptr ptr=(*ref),temp=NULL;
    if(ptr->next == NULL)
    {
        printf("only head node ----removing\n");
        free(ptr);
        (*ref) = NULL;
    }
    else
    {
        while( ptr->next->next != NULL)
        {
            ptr = ptr->next;
        }
        free(ptr->next);
        ptr->next = NULL;

    }
return 0;
}

void displayList(Node *head)
{
    Node *p = head;
    if(p == NULL)
    {
        printf("stack List is empty\n");
        return;
    }
    while(p != NULL)
    {
        printf("%d\t",p->data);
        p = p->next;
    }
    printf("\n");
}

int main()
{
	Node *head=NULL;
    int data,choice;
	//CustomerInfo cinfo;

	while(1)
	{
		printf("\n*****Welcome to linked list as stack****\n");
		printf("Enter your choice\n");
		printf("1. Add item to front\n");
		printf("2. Delete item from front\n");
        printf("3. Add item to rear\n");
		printf("4. Delete item from rear\n");
		printf("5. Display DQueue items\n");
		printf("6. To exit the menu\n");
		printf("****************************************\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
			{
				printf("choice 1 selected, enter the element to push\n");
				scanf("%d",&data);
                addnode_front(&head,data);
			}
			break;
			case 2:
			{
				removenode_front(&head);
			}
			break;
            case 3:
			{
				printf("choice 1 selected, enter the element to push\n");
				scanf("%d",&data);
                addnode_rear(&head,data);
			}
			break;
            case 4:
			{
				removenode_rear(&head);
			}
			break;
			case 5:
                displayList(head);
                break;
			case 6:
                exit(0);
            default:
            printf("Enter a proper choice\n");
			break;
		}
	}

}
