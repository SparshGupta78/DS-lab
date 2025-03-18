#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head, *head1 = NULL, *head2 = NULL, *temp1, *temp2;

int main () {

    printf("Enter the number of nodes in first circular linked list : ");
    int size1;
    scanf("%d", &size1);

    for (int a = 1; a <= size1; a++) {

        struct node *nnode = (struct node *) malloc (sizeof(struct node));
        
        printf("Enter data : ");
        scanf("%d", &nnode->data);

        if (head1 == NULL) {
            head1 = nnode;
            temp1 = nnode;
            nnode->next = nnode;
        } else {
            nnode->next = temp1->next;
            temp1->next = nnode;
            temp1 = temp1->next;
        }

    }

    printf("Enter the number of nodes in second circular linked list : ");
    int size2;
    scanf("%d", &size2);

    for (int a = 1; a <= size2; a++) {

        struct node *nnode = (struct node *) malloc (sizeof(struct node));
        
        printf("Enter data : ");
        scanf("%d", &nnode->data);

        if (head2 == NULL) {
            head2 = nnode;
            temp2 = nnode;
            nnode->next = nnode;
        } else {
            nnode->next = temp2->next;
            temp2->next = nnode;
            temp2 = temp2->next;
        }

    }

    temp1->next = head2;
    temp2->next = head1;

    head = head1;

    temp1 = head;

    while (temp1->next != head) {
        printf("%d", temp1->data);
        temp1 = temp1->next;
    }
    printf("%d\n", temp1->data);

    return 0;
}