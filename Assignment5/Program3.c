#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *previous;
    struct node *next;
};

struct node *head = NULL, *tail = NULL;

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

    printf("Delete node at:-\n1. Start\n2. End\n3. At specfic position\n");
    int choice;
    scanf("%d", &choice);

    if (choice == 1) {
        struct node *temp2 = head;
        head = head->next;
        head->previous = NULL;
        free(temp2);
    }
    else if (choice == 2) {
        struct node *temp2 = tail;
        tail = tail->previous;
        tail->next = NULL;
        free(temp2);
    }
    else if (choice == 3) {
        int del_choice;
        printf("Enter number of node to delete : ");
        scanf("%d", &del_choice);
        struct node *temp2 = head;
        for (int b = 1; b < del_choice; b++) {
            temp2 = temp2->next;
        }
        temp2->previous->next = temp2->next;
        temp2->next->previous = temp2->previous;
        free(temp2);
    }

    struct node *temp = head;

    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
    
    return 0;
}