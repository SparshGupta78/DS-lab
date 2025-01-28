#include <stdio.h>
int main(){
    int size;
    printf("Enter the size of matrix : ");
    scanf("%d", &size);
    
    int array[size][size];
    for(int aa = 0; aa < size; aa++){
        for(int ab = 0; ab < size; ab++){
            printf("Enter array[%d][%d] : ", aa, ab);
            scanf("%d", &array[aa][ab]);
        }
    }

    int filter_size = 3;

    int newArray[size][size];
    for(int zz = 0; zz < size; zz++){
        for(int zy = 0; zy < size; zy++){
            newArray[zz][zy] = 0;
        }
    }

    for(int ae = 0; ae < (size - filter_size + 1); ae++){

        for(int af = 0; af < (size - filter_size + 1); af++){
            int tempArray[filter_size * filter_size];
            int temp = 0;
            
            for(int ag = ae; ag <= (ae + filter_size - 1); ag++){
                for(int ah = af; ah <= (af + filter_size - 1); ah++){
                    tempArray[temp++] = array[ag][ah];
                }
            }

            for(int ai = 0; ai < (filter_size * filter_size) - 1; ai++){
                int sort_min = ai;
                for(int aj = ai + 1; aj < (filter_size * filter_size); aj++){
                    if(tempArray[aj] < tempArray[sort_min]){
                        sort_min = aj;
                    }
                    if(sort_min != ai){
                        int sort_temp = tempArray[ai];
                        tempArray[ai] = tempArray[sort_min];
                        tempArray[sort_min] = sort_temp;
                    }
                }
            }
            newArray[ae + 1][af + 1] = tempArray[4];
        }
    }

    for(int zw = 0; zw < size; zw++){
        for(int zx = 0; zx < size; zx++){
            printf("%d\t", newArray[zw][zx]);
        }
        printf("\n");
    }

    return 0;
}