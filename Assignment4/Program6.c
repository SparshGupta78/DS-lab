//Q6 - Implement bubble sort in singly linked list.

#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

int main(){
    int size;
    printf("Enter the number of node : ");
    scanf("%d", &size);

    struct node *head = NULL, *temp;

    for(int i = 1; i <= size; i++){
        struct node *nnode = (struct node *) malloc (sizeof(struct node));

        if(nnode == NULL){
            printf("Memory allocation failed!");
            return 1;
        }

        printf("Enter data : ");
        scanf("%d", &nnode->data);
        nnode->next = NULL;

        if (head == NULL){
            head = nnode;
            temp = nnode;
        } else {
            temp->next = nnode;
            temp = nnode;
        }
    }
    
    for(int i = 0; i < (size - 1); i++){
        struct node *temp1 = head, *temp2 = head->next;
        for(int j = 0; j < (size - i - 1); j++){
            if(temp1->data > temp2->data){
                int dataTemp = temp1->data;
                temp1->data = temp2->data;
                temp2->data = dataTemp;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
    }

    printf("\nSorted linked list :\n");
    temp = head;
    while(temp != NULL){
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}