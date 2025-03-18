#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *previous;
    struct node *next;
};

struct node *head = NULL, *tail = NULL, *temp;

int main () {

    printf("Enter size of doubly linked list : ");
    int size;
    scanf("%d", &size);

    for (int a = 1; a <= size; a++) {
        struct node *nnode = (struct node *) malloc (sizeof(struct node));

        if (nnode == NULL) {
            printf("Memory allocation failed!");
            return -1;
        }

        printf("Enter data : ");
        scanf("%d", &nnode->data);

        nnode->previous = NULL;
        nnode->next = NULL;

        if (head == NULL) {
            head = nnode;
            tail = nnode;
        } else {
            tail->next = nnode;
            nnode->previous = tail;
            tail = nnode;
        }
    }

    printf("Insert node at:-\n1. Start\n2. End\n3. At specfic position\n");
    int choice;
    scanf("%d", &choice);

    struct node *nnode = (struct node *) malloc (sizeof(struct node));
    printf("Enter data : ");
    scanf("%d", &nnode->data);
    nnode->previous = NULL;
    nnode->next = NULL;

    if (choice == 1) {
        nnode->next = head;
        head->previous = nnode;
        head = nnode;
    }
    else if (choice == 2) {
        tail->next = nnode;
        nnode->previous = tail;
        tail = nnode;
    }
    else if (choice == 3) {
        int specific_choice;
        printf("Enter the node number : ");
        scanf("%d", &specific_choice);

        temp = head;
        for (int b = 1; b < specific_choice; b++) {
            temp = temp->next;
        }

        nnode->next = temp->next;
        nnode->previous = temp;

        temp->next->previous = nnode;

        temp->next = nnode;
    }

    temp = head;

    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
    
    return 0;
}