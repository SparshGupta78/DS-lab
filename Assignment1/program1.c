#include <stdio.h>
int main(){
    int size;
    printf("Enter the size of array : ");
    scanf("%d", &size);
    printf("\n");

    int array[size + 10];
    for(int aa = 0; aa < size; aa++){
        printf("Enter %d element : ", (aa + 1));
        scanf("%d", &array[aa]);
    }
    printf("\n");

    printf("Entered array is-\n");
    for(int ab = 0; ab < size; ab++){
        printf("%d\t", array[ab]);
    }
    printf("\n\n");

    printf("Enter the number to perform one of the following operations:\n1. Insert an element\t2. Delete an element\t3. Search for an element\t4. Sort the Array\n");
    int choice;
    scanf("%d", &choice);
    printf("\n");

    if(choice == 1){
        printf("Insert element at:\n1. Beginning\t2. End\t3. At specific position\n");
        int choice_insert;
        scanf("%d", &choice_insert);

        if(choice_insert == 1){
            int insert_beginning;
            printf("Enter the element to add at beginning: ");
            scanf("%d", &insert_beginning);

            for(int ac = size; ac > 0; ac--){
                array[ac] = array[ac - 1];
            }

            array[0] = insert_beginning;

            size++;

            printf("New array is-\n");
            for(int ad = 0; ad < size; ad++){
                printf("%d\t", array[ad]);
            }
        }

        else if(choice_insert == 2){
            int insert_end;
            printf("Enter the element to add at end : ");
            scanf("%d", &insert_end);

            array[size] = insert_end;
            size++;

            printf("New array is-\n");
            for(int ae = 0; ae < size; ae++){
                printf("%d\t", array[ae]);
            }
        }

        else if(choice_insert == 3){
            int insert_position;
            printf("Enter the position to add element: ");
            scanf("%d", &insert_position);
            printf("\n");

            int insert_element;
            printf("Enter the element to add at position: ");
            scanf("%d", &insert_element);
            printf("\n");

            for(int af = size; af >= insert_position; af--){
                array[af] = array[af - 1];
            }

            array[insert_position - 1] = insert_element;
            size++;

            printf("New array is-\n");
            for(int ag = 0; ag < size; ag++){
                printf("%d\t", array[ag]);
            }
        }
        
        else{
            printf("Invalid Input.");
        }
    }

    else if(choice == 2){
        printf("Delete element at-\n1. Start\t2. End\t3. At specific position\n");
        int choice_delete;
        scanf("%d", &choice_delete);
        printf("\n");

        if(choice_delete == 1){
            for(int ah = 0; ah < size - 1; ah++){
                array[ah] = array[ah + 1];
            }
            array[size - 1] = '\0';
            size--;

            printf("New array is-\n");
            for(int ai = 0; ai < size; ai++){
                printf("%d\t", array[ai]);
            }
        }

        else if(choice_delete == 2){
            array[size - 1] = '\0';
            size--;

            printf("New array-\n");
            for(int aj = 0; aj < size; aj++){
                printf("%d\t", array[aj]);
            }
        }

        else if(choice_delete == 3){
            printf("Enter the position of element to delete: ");
            int delete_position;
            scanf("%d", &delete_position);

            for(int ak = delete_position - 1; ak < size - 1; ak++){
                array[ak] = array[ak + 1];
            }
            array[size - 1] = '\0';
            size--;

            printf("New array-\n");
            for(int al = 0; al < size; al++){
                printf("%d\t", array[al]);
            }
        }
    
        else{
            printf("Invalid Input.");
        }
    }

    else if(choice == 3){
        printf("Enter the element to search for: ");
        int search_element;
        scanf("%d", &search_element);

        int search_temp = 0;
        for(int am = 0; am < size; am++){
            if(search_element == array[am]){
                printf("Element found at index %d.", am);
            }
            else{
                search_temp++;
            }
        }
        if(search_temp == size){
            printf("No element found.");
        }
    }

    else if(choice == 4){
        printf("Enter your choice-\n1. Complete sort\t2. Sort at even places\t 3. Sort at odd places\t4. Sort for odd elements\n5. Sort for even elements\n");
        int sort_choice;
        scanf("%d", &sort_choice);
        if(sort_choice == 1){
            for(int an = 0; an < size - 1; an++){
                int sort_min = an;
                for(int ao = an + 1; ao < size; ao++){
                    if(array[ao] < array[sort_min]){
                        sort_min = ao;
                    }
                    if(sort_min != an){
                        int sort_temp = array[an];
                        array[an] = array[sort_min];
                        array[sort_min] = sort_temp;
                    }
                }
            }

            printf("New array-\n");
            for(int ap = 0; ap < size; ap++){
                printf("%d\t", array[ap]);
            }
        }

        else if(sort_choice == 2){
            for(int an = 0; an < size - 1; an++){
                int sort_min = an;
                for(int ao = an + 1; ao < size; ao++){
                    if(an % 2 != 0 && ao % 2 != 0){
                        if(array[ao] < array[sort_min]){
                        sort_min = ao;
                        }
                        if(sort_min != an){
                            int sort_temp = array[an];
                            array[an] = array[sort_min];
                            array[sort_min] = sort_temp;
                        }
                    }
                    
                }
            }

            printf("New array-\n");
            for(int ap = 0; ap < size; ap++){
                printf("%d\t", array[ap]);
            }
        }
        
        else if(sort_choice == 3){
            for(int an = 0; an < size - 1; an++){
                int sort_min = an;
                for(int ao = an + 1; ao < size; ao++){
                    if(an % 2 == 0 && ao % 2 == 0){
                        if(array[ao] < array[sort_min]){
                        sort_min = ao;
                        }
                        if(sort_min != an){
                            int sort_temp = array[an];
                            array[an] = array[sort_min];
                            array[sort_min] = sort_temp;
                        }
                    }
                    
                }
            }

            printf("New array-\n");
            for(int ap = 0; ap < size; ap++){
                printf("%d\t", array[ap]);
            }
        }

        else if(sort_choice == 4){
            for(int an = 0; an < size - 1; an++){
                int sort_min = an;
                for(int ao = an + 1; ao < size; ao++){
                    if(array[an] % 2 != 0 && array[ao] % 2 != 0){
                        if(array[ao] < array[sort_min]){
                        sort_min = ao;
                        }
                        if(sort_min != an){
                            int sort_temp = array[an];
                            array[an] = array[sort_min];
                            array[sort_min] = sort_temp;
                        }
                    }
                    
                }
            }

            printf("New array-\n");
            for(int ap = 0; ap < size; ap++){
                printf("%d\t", array[ap]);
            }
        }
        
        else if(sort_choice == 5){
            for(int an = 0; an < size - 1; an++){
                int sort_min = an;
                for(int ao = an + 1; ao < size; ao++){
                    if(array[an] % 2 == 0 && array[ao] % 2 == 0){
                        if(array[ao] < array[sort_min]){
                        sort_min = ao;
                        }
                        if(sort_min != an){
                            int sort_temp = array[an];
                            array[an] = array[sort_min];
                            array[sort_min] = sort_temp;
                        }
                    }
                    
                }
            }

            printf("New array-\n");
            for(int ap = 0; ap < size; ap++){
                printf("%d\t", array[ap]);
            }
        }

        else{
            printf("Invalid input");
        }
    }

    else{
        printf("Invalid Input.");
    }

    return 0;
}