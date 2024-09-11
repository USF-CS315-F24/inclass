#include <stdio.h>

int arr_get_c(int arr[], int i);
void arr_set_c(int arr[], int i, int v);

int arr_get_s(int arr[], int i);
void arr_set_s(int arr[], int i, int v);

int main(int argc, char *argv[]) {
    int x;
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {1, 2, 3, 4, 5};

    
    x = arr_get_c(arr1, 2);
    printf("arr_get_c(arr1, 2) = %d\n", x);
    arr_set_c(arr1, 2, 99);
    printf("arr_set_c(arr1, 2, 99)\n");
    x = arr_get_c(arr1, 2);
    printf("arr_get_c(arr1, 2) = %d\n", x);

    x = arr_get_s(arr2, 2);
    printf("arr_get_s(arr2, 2) = %d\n", x);
    arr_set_s(arr2, 2, 99);
    printf("arr_set_s(arr2, 2, 99)\n");
    x = arr_get_s(arr2, 2);
    printf("arr_get_s(arr2, 2) = %d\n", x);

    return 0;
}
