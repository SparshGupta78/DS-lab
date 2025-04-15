//Q1 - Implement queue using array and perform enqueue, dequeue and display function.
//Q2 - Implement queue using link list and perform enqueue, dequeue and display function.
//Q3 - Implement circular queue using array and perform enquee dequeue and display operation.
//Q4 - Take a scenario of a clinic in which patients are in queue and as the doctor sees a node it become dequeue from the queue. Each node must include waiting list number which must update when dequeue happens.

#include <stdio.h>

int front = -1, rear = -1;

void display (int n, int queue[]) {
    printf("Displaying data :-\n\n");

    if (front == -1 && rear == -1) {
        printf("Underflow condition!!\n");
    } else {
        int i = front;

        while ((i % n) != rear) {
            printf("  %d", queue[i]);
            i = (i + 1) % n;
        }
        printf("  %d\n", queue[i]);
    }
}

void push (int n, int queue[]) {
    if (front == -1 && rear == -1) {
        front++;
        rear++;
        printf("Enter data : ");
        scanf("%d", &queue[rear]);
    }
    else if ((rear + 1) % n == front) {
        printf("Overflow condition!!\n");
    }
    else {
        printf("Enter data : ");
        scanf("%d", &queue[++rear]);
    }
}

void pop (int n, int queue[]) {
    if (front == -1 && rear == -1) {
        printf("Underflow condtion!!\n");
    }
    else if (front == rear) {
        printf("%d", queue[front]);
        front = -1;
        rear = -1;
    }
    else {
        printf("%d", queue[front]);
        front = (front + 1) % n;
    }
}

void main () {
    int n;
    printf("Enter the size of queue : ");
    scanf("%d", &n);

    int queue[n];

    int run = 1;
    while (run) {

        int choice;
        printf("\nEnter choice:-\n\n  1. Display\n  2. Push\n  3. Pop\n  9. Exit\n\n:  ");
        scanf("%d", &choice);
        printf("\n");

        if (choice == 1) {
            display(n, queue);
        }
        else if (choice == 2) {
            push(n, queue);
        }
        else if (choice == 3) {
            pop(n, queue);
        }
        else if (choice == 9) {
            run = 0;
        }
    }
}