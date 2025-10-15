#include<stdio.h>
#define N 2
int stack[N];
int top=-1;
void push()
{
    int x;
    printf("Enter data: ");
    scanf("%d",&x);
    if (top==N-1)
    {
        printf("Stack overflow \n");
    }
    else
    {
        top++;
        stack[top]=x;
    }
}
void pop()
{
    int item;
    if (top==-1)
    {
        printf("Stack overflow \n");
    }
    else
    {
        item=stack[top];
        top--;
        printf("Item deleted is %d \n",item);
    }
}
void peek()
{
    if(top==-1)
    {
        printf("Stack underflow \n");
    }
    else
    {
        printf("Item on top is %d \n",stack[top]);
    }
}
void display()
{
    int i;
    printf("Elements in stack are; \n");
    for(i=0;i<=top;i++)
    {
        printf("%d",stack[i]);
    }
    if(top==-1)
    {
        printf("No element");
    }
}
void main()
{
    int y;
    while(1)
    {
    printf("1 push 2 pop 3 peek 4 display \n");
    printf("Enter your choice; \n");
    scanf("%d",&y);
    switch(y)
    {
        case 1 : push();
        break;
        case 2: pop();
        break;
        case 3: peek();
        break;
        case 4: display();
        break;
        default:printf("Invald choice \n");
    }
}

}
