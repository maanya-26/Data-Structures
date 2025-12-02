#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL;

void createList(int n)
{
    struct node *newnode, *temp;
    int data, i;

    if (n <= 0)
    {
        printf("Number of nodes should be greater than zero.\n");
        return;
    }

    for (i = 1; i <= n; i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        if (newnode == NULL)
        {
            printf("Memory allocation failed\n");
            return;
        }

        printf("Enter data: ");
        scanf("%d", &data);
        newnode->data = data;
        newnode->next = NULL;

        if (head == NULL)
        {
            head = temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
    }
}


void insertAtBeginning(int data)
{

    struct node *newnode=(struct node*)malloc (sizeof(struct node));
    newnode-> data=data;
    newnode->next=head;
    head = newnode;
    printf("Node inserted in the beginning \n");
}
void insertAtEnd(int data)
{
    struct node*newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;
    if (head==NULL)
        head = newnode;
    else {
        struct node *temp=head;
        while(temp -> next != NULL)
        {
            temp=temp->next;
            temp->next=newnode;
        }
    }
    printf("Node inserted at the end \n");
}
void insertAtPosition(int data,int pos)
{
    int i;
    struct node *newnode,*temp=head;
    if (pos<1)
    {
        printf("Invalid position \n");
        return;
    }
    if(pos==1)
    {
        insertAtBeginning(data);
        return;
    }
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    for(i=1;i<pos-1 && temp != NULL; i++)
    {
        temp=temp->next;
    }
    if(temp==NULL)
    {
        printf("Position out of range; \n");
        free(newnode);
    }
    else
    {
        newnode->next=temp->next;
        temp->next=newnode;
    }
    printf("Node inserted at position %d \n",pos);
}

void deleteFirst()
{
    struct node *temp;
    if(head==NULL)
    {
        printf("List is empty. Nothing to delete. \n");
        return;
    }
    temp=head;
    head=head -> next;
    printf("Deleted element: %d\n",temp -> data);
    free(temp);
}

void deleteLast()
{
    struct node *temp,*prev;
    if (head==NULL)
    {
        printf("List is empty. Nothing to delete. \n");
        return;
    }
    if (head -> next == NULL){
        printf("Deleted element: %d\n",head -> data);
        free(head);
        head=NULL;
        return;
    }
    temp=head;
    while(temp->next != NULL)
    {
        prev=temp;
        temp=temp->next;
    }
    printf("Deleted element: %d\n",temp -> data);
    prev->next=NULL;
    free(temp);

}

void DeleteSpecific(int value)
{
    struct node *temp=head,*prev=NULL;
    if (head==NULL)
    {
        printf("List is empty. Nothing to delete. \n");
        return;
    }
    if (head -> data == value){
        head=head->next;
        printf("Deleted element: %d\n",temp -> data);
        free(temp);
        return;
    }
    while(temp != NULL && temp->data != value)
    {
        prev=temp;
        temp=temp->next;
    }
    if(temp==NULL)
    {
        printf("Element not found.\n");
        return;
    }
    prev->next=temp->next;
    printf("Deleted element: %d\n",temp -> data);;
    free(temp);
}

void displayList()
{
    struct node *temp=head;
    if (head == NULL)
    {
        printf("List is empty \n");
        return;
    }
    printf("\n Linked List: ");
    while(temp != NULL)
    {
        printf("%d ->",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}
void main()
{
    int choice,n,data,pos;
    printf(" 1.Create linked list \n 2.Insert at beginning \n 3.Insert at position \n 4.Insert at end \n 5.Delete at front \n 6.Delete at end \n 7.Delete specific \n 8.Display list \n 9.Exit \n");
    while(1)
    {
        printf("Enter your choice:");
        scanf("%d",&choice);
        int value;
        switch(choice)
        {
        case 1:
            printf("Enter number of nodes: ");
            scanf("%d",&n);
            createList(n);
            break;

        case 2:
            printf("Enter data to insert: ");
            scanf("%d",&data);
            insertAtBeginning(data);
            break;

        case 3:
            printf("Enter data and position: ");
            scanf("%d%d",&data,&pos);
            insertAtPosition(data,pos);
            break;

        case 4:
            printf("Enter data to insert: ");
            scanf("%d",&data);
            insertAtEnd(data);
            break;

        case 5:
            deleteFirst();
            break;

        case 6:
            deleteLast();
            break;

        case 7:
            printf("Enter value to delete: ");
            scanf("%d",&value);
            DeleteSpecific(value);
            break;

        case 8:
            displayList();
            break;

        case 9:
            printf("Exiting...\n");
            exit(0);

        default:
            printf("Invalid choice. Try again \n");
        }
    }
    return 0;
}
