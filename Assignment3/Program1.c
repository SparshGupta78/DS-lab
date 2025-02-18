#include <stdio.h>

int binarySearch(int array[], int l, int h, int key){
    while(l <= h){
        int mid = (l + h) / 2;
        
        if(key == array[mid]){
            return mid;
        }
        else if(key < array[mid]){
            h = mid - 1;
            binarySearch(array, l, h, key);
        }
        else if(key > array[mid]){
            l = mid + 1;
            binarySearch(array, l, h, key);
        }
    }
    return -1;
}

void main(){

    printf("\nPerforming binary search\n[Reminder]: Enter sorted array to perform binary search\n\n");

    int size;
    printf("Enter the size of array-\n:");
    scanf("%d", &size);

    int array[size];
    printf("Enter the array-\n");
    for(int i = 0; i < size; i++){
        printf("[%d]: ", i);
        scanf("%d", &array[i]);
    }

    int key;
    printf("Enter the number to search-\n:");
    scanf("%d", &key);

    int position = binarySearch(array, 0, size - 1, key);

    if(position == -1){
        printf("Element not found");
    }
    else{
        printf("Element found at %d index", position);
    }
}