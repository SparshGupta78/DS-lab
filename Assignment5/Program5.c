#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL, *temp;

int main () {

    printf("Enter the number of nodes in circular linked list : ");
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

        if (head == NULL) {
            head = nnode;
            temp = nnode;
            head->next = head;
        } else {
            nnode->next = temp->next;
            temp->next = nnode;
            temp = temp->next;
        }
    }

    printf("Enter place of node to insert : ");
    int place;
    scanf("%d", &place);

    temp = head;
    for (int b = 1; b < place - 1; b++) {
        temp = temp->next;
    }
    
    struct node *nnode = (struct node *) malloc (sizeof(struct node));

    if (nnode == NULL) {
        printf("Memory allocation failed!");
        return -1;
    }

    printf("Enter data : ");
    scanf("%d", &nnode->data);

    nnode->next = temp->next;
    temp->next = nnode;
    

    temp = head;

    while (temp->next != head) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
    printf("%d", temp->data);

    return 0;
}