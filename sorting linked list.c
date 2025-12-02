#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};
struct node *head = NULL;

void createList(int n) {
    struct node *newnode, *temp;
    int data, i;

    if (n <= 0) {
        printf("Number of nodes should be greater than zero.\n");
        return;
    }

    head = NULL;
    for (i = 1; i <= n; i++) {
        newnode = (struct node*)malloc(sizeof(struct node));
        if (newnode == NULL) {
            printf("Memory allocation failed\n");
            return;
        }

        printf("Enter data for node %d: ", i);
        scanf("%d", &data);
        newnode->data = data;
        newnode->next = NULL;

        if (head == NULL) {
            head = temp = newnode;
        } else {
            temp->next = newnode;
            temp = newnode;
        }
    }
}

void sorting() {
    int tempData;
    struct node *i, *j;
    for (i = head; i != NULL && i->next != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                tempData = i->data;
                i->data = j->data;
                j->data = tempData;
            }
        }
    }
    printf("List sorted.\n");
}

struct node* reverseList(struct node *head) {
    struct node *prev = NULL, *curr = head, *next = NULL;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    printf("Linked list reversed.\n");
    return prev;
}

struct node* concate(struct node *head1, struct node *head2) {
    if (head1 == NULL) return head2;
    struct node *temp = head1;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = head2;
    printf("Lists concatenated.\n");
    return head1;
}

void display(struct node *head) {
    struct node *temp = head;
    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, n;
    struct node *head2 = NULL;

    printf(" 1.Create List\n 2.Sort\n 3.Reverse\n 4.Concatenate\n 5.Display\n 6.Exit\n");

    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter number of nodes: ");
                scanf("%d", &n);
                createList(n);
                break;
            case 2:
                sorting();
                break;
            case 3:
                head = reverseList(head);
                break;
            case 4:
                printf("Enter number of nodes for second list: ");
                scanf("%d", &n);
                head2 = NULL;
                {
                    struct node *newnode, *temp;
                    int data, i;
                    for (i = 1; i <= n; i++) {
                        newnode = (struct node*)malloc(sizeof(struct node));
                        printf("Enter data for node %d: ", i);
                        scanf("%d", &data);
                        newnode->data = data;
                        newnode->next = NULL;
                        if (head2 == NULL) {
                            head2 = temp = newnode;
                        } else {
                            temp->next = newnode;
                            temp = newnode;
                        }
                    }
                }
                head = concate(head, head2);
                break;
            case 5:
                display(head);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}
