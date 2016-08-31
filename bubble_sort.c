#include <stdlib.h>
#include <stdio.h>

void swap(int* arr, int i){
    int tmp = arr[i];
    arr[i] = arr[i-1];
    arr[i-1] = tmp;
}

void bubble_sort(int* arr, int len_arr){
    int swapped = 1;
    while(swapped == 1){
        swapped = 0;
        for(int i = 1; i < len_arr; i++){
            if(arr[i-1] > arr[i]){
                swap(arr, i); //swap the elements and mark ti as swapped
                swapped = 1;
            }
        }
    }
}

void print_arr(int* arr, int len_arr){
    printf("[ ");
    for(int i = 0; i < len_arr; i++){
        printf("%d ", arr[i]);
    }
    printf("]\n");
}


int main(){
    //run using the following commands
    //gcc bubble_sort.c -o bubble_sort_program
    //cat tmp.txt |  ./bubble_sort_program
    
    int n = 0;
    int len_arr = 20;
    int arr[len_arr];
    while(n < len_arr){
        scanf("%d", &arr[n]);
        n++;
    }
    //print_arr(iarr, 20);
    
    //int len_arr = 7;
    //int arr[7] = {184, 70, 42, 152, 116, 84, 99};
    printf("Unsorted Array: ");
    print_arr(arr, len_arr);
    bubble_sort(arr, len_arr);
    printf("Sorted Array: ");
    print_arr(arr, len_arr);
    
    
    return 1;
}