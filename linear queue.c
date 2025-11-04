#include<stdio.h>
#define N 2
int queue[N];
int front=-1;
int rear =-1;

void enque() {
    int x;
    printf("Enter number: ");
    scanf("%d",&x);
    if (rear==N-1)
    {
        printf("Queue is full \n");
    }
    else if (front==-1 && rear==-1)
    {
        front=rear=0;
        queue[rear]=x;
    }
    else {
        rear++;
        queue[rear]=x;
    }
}
void deque()
{
    if (front==-1 && rear==-1){
        printf("Queue is empty \n");
    }
    else if (front==rear){
        printf("Deleted element is %d \n",queue[front]);
        front=rear=-1;
    }
    else{
        printf("Deleted element is %d \n",queue[front]);
        front++;
    }
}
void peek()
{
    if (front==-1 && rear==-1){
        printf("Queue is empty \n");
    }
    else{
        printf("Top element is %d \n",queue[front]);
    }
}
void display()
{
    if (front==-1 && rear==-1){
        printf("Queue is empty \n");
    }
    else{
        int i;
        printf("Queue elements are: \n");
        for (i=front;i<=rear;i++){
            printf("%d \n",queue[i]);
        }
    }
}
void main()
{
    int n;
    printf("1. Enqueue 2. Dequeue 3. Peek 4. Display \n");
    while(1)
    {
        printf("Enter your choice: ");
        scanf("%d",&n);
        switch(n)
        {
            case 1: enque();
            break;
            case 2: deque();
            break;
            case 3: peek();
            break;
            case 4: display();
            break;
            default : printf("Invalid choice");

        }
    }
}
