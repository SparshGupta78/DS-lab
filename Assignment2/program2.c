#include <stdio.h>
int main(){
    int n;
    printf("Enter the size of array : ");
    scanf("%d", &n);
    float arr[n];
    printf("Enter the array:\n");
    for(int i = 0; i < n; i++){
        scanf("%f", &arr[i]);
    }
    float window_size;
    printf("Enter the window size : ");
    scanf("%f", &window_size);

    float new_array[n];

    new_array[0] = arr[0];

    for(int aa = 1; aa < n; aa++){
        float alpha = 2/(1 + window_size);
        new_array[aa] = (arr[aa] * alpha) + (new_array[aa - 1] * (1 - alpha));
    }

    for(int zz = 0; zz < n; zz++){
        printf("%f\t", new_array[zz]);
    }

    return 0;
}