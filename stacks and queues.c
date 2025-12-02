#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL;
struct node *top = NULL;
struct node *front = NULL;
struct node *rear = NULL;

struct node* createNode(int value) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newnode->data = value;
    newnode->next = NULL;
    return newnode;
}


void push(int value)
{
    struct node *newnode=createNode(value);
    newnode -> next = top;
    top=newnode;
    printf("%d pushed to stack\n", value);

}

void pop()
{
    if (top==NULL){
        printf("Stack is empty. \n");
        return;}
    struct node *temp;
    temp=top;
    printf("%d popped from stack\n", temp->data);
    top=top->next;
    free(temp);
}
void enque(int value)
{
    struct node *newnode=createNode(value);
    if(rear==NULL)
        front = rear = newnode;
    else {
        rear->next=newnode;
        rear=newnode;
    }
    printf("%d enqueued to queue\n", value);
}

void deque()
{
    if (front==NULL)
    {
        printf("Queue is empty. \n");
        return;
    }
    struct node *temp=front;
    printf("%d dequeued from queue\n", temp->data);
    front=front->next;
    if(front==NULL)
        rear=NULL;
    free(temp);
}

void main()
{
    int n;
    printf("1.push 2.pop 3.enque 4.deque\n");
    while(1){
    printf("Enter your choice: ");
    scanf("%d",&n);

    switch(n)
    {
        int data;

        case 1:
            printf("Enter data to insert: ");
            scanf("%d",&data);
            push(data);
            break;

        case 2:
            pop();
            break;

        case 3:
            printf("Enter data to insert: ");
            scanf("%d",&data);
            enque(data);
            break;

        case 4:
            deque();
            break;


    }

    }
}

