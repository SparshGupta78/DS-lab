#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

int main(){
    int size;
    printf("Enter the size of linked list : ");
    scanf("%d", &size);

    int array[size];
    struct node *head = 0, *temp;
    for(int i = 0; i < size; i++){
        struct node *nnode = (struct node *)malloc(sizeof(struct node));
        if(nnode == 0){
            printf("Memory allocation falied!");
            return 1;
        }

        printf("Enter data : ");
        scanf("%d", &nnode->data);
        array[i] = nnode->data;
        nnode->next = 0;

        if(head == 0){
            head = nnode;
            temp = nnode;
        } else {
            temp->next = nnode;
            temp = nnode;
        }
    }

    int pos = size - 1;
    temp = head;
    while(temp != 0){
        if(pos%2 != 0){
            temp->data = array[pos];
        }
        pos--;
        temp = temp->next;
    }

    temp = head;
    while(temp != 0){
        printf("%d\t", temp->data);
        temp = temp->next;
    }
}