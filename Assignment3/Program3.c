#include <stdio.h>

void swap(int *a, int*b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int array[], int l, int h){
    int pivot = array[l], si = l, ei = h;

    while(si < ei){
        while(array[si] <= pivot){
            si++;
        }
        while(array[ei] > pivot){
            ei--;
        }
        if(si < ei){
            swap(&array[si], &array[ei]);
        }
    }
    swap(&array[l], &array[ei]);
    return ei;
}

void quickSort(int array[], int l, int h){
    if(l < h){
        int position = partition(array, l, h);
        quickSort(array, l, position - 1);
    }
}

void main(){
    int size;
    printf("Enter the size : ");
    scanf("%d", &size);

    int array[size];
    for(int i = 0; i < size; i++){
        printf("Enter %d element : ", i+1);
        scanf("%d", &array[i]);
    }

    int choice;
    printf("Enter the number of smallest elements : ");
    scanf("%d", &choice);

    int small[choice];
    for(int i = 0; i < choice; i++){
        quickSort(array, 0, size - 1);
        small[i] = array[0];
        for(int i = 0; i < size - 1; i++){
            array[i] = array[i + 1];
        }
        array[size - 1] = '\0';
        size--;
    }

    for(int i = 0; i < choice; i++){
        printf("%d\t", small[i]);
    }
}