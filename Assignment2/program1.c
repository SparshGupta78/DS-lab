#include <stdio.h>
int main(){
    int n;
    printf("Enter the size of array : ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the array:\n");
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    int window_size;
    printf("Enter the window size : ");
    scanf("%d", &window_size);

    for(int aa = 0; aa < n; aa++){
        if((aa + 1 - window_size) < 0){
            int add = 0, count = 0;
            for(int ab = aa; ab >= 0; ab--){
                add += arr[ab];
                count++;
            }

            int average = add/count;
            printf("%d\t", average);
        }

        else{
            int add = 0;
            for(int ac = aa; ac >= (aa + 1 - window_size); ac--){
                add += arr[ac];
            }

            int average = add/window_size;
            printf("%d\t", average);
        }
    }

    return 0;
}