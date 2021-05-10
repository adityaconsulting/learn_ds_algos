#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct _node
{
    int data_type;
    union 
    {
        char str[20];
        int num;
        float value;
    };    
    struct _node *next;
}Node,*Nodeptr;
 

int addnode(Node **ref,int data_type, void *data)
{
    Nodeptr p=NULL,*q = ref,temp;
    //printf("%d ",(*q)->data);
    p = (Node*)malloc(sizeof(Node));
    p->next = NULL;
    if(data_type == 1)
    {
        p->data_type = 1;
        p->num = *((int*)data);
        printf("%d",p->num);
    }
    else if(data_type == 3)
    {    
        p->data_type = 3;
        p->value = *((float*)data);
        printf("%f",p->value);
    }
    else
    {
        p->data_type = 2;
        strncpy(p->str,(char*)data,19);
    }
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
int removenode(Node **ref)
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
        if(p->data_type == 1)
        {
            printf("%d\t",p->num);
        }
        else if(p->data_type == 3)
        {
            printf("%f\t",p->value);
        }
        else
        {
            printf("%s\t",p->str);
        }
        p = p->next;
    }
    printf("\n");
}

int main()
{
	Node *head=NULL;
    int data_type,choice,type;
    int data=0;
    char str[20]={0};
    float value=0;
	//CustomerInfo cinfo;

	while(1)
	{
		printf("\n*****Welcome to asymmetric linked list as queue****\n");
		printf("Enter your choice\n");
		printf("1. Add item to queue\n");
		printf("2. Delete item from Q\n");
		printf("3. Display Queue items\n");
		printf("4. To exit the menu\n");
		printf("****************************************\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
			{
                printf("Enter your choice\n");
		        printf("1. Add int type data to queue\n");
		        printf("2. Add string type data to queue\n");
		        printf("3. Add float type data to Queue\n");
                scanf("%d",&type);
                switch(type)
                {
                    case 1:
                        data_type = 1;
                        printf("Please enter int data");
                        scanf("%d",&data);
                        addnode(&head,data_type,(void*)&data);
                    break;
                    case 2:
                        data_type = 2;
                        printf("Please enter string data");
                        scanf("%s",str);
                         addnode(&head,data_type,(void*)str);
                    break;
                    case 3:
                        data_type = 3;
                        printf("Please enter float data");
                        scanf("%f",&value);
                         addnode(&head,data_type,(void*)&value);
                    break;
                    default:
                    printf("improper choice - enter a proper value\n");
                    break;
                }
				
				
               
			}
			break;
			case 2:
			{
				removenode(&head);
			}
			break;
			case 3:
                displayList(head);
                break;
			case 4:
                exit(0);
            default:
            printf("Enter a proper choice\n");
			break;
		}
	}

}
