#include <stdio.h>
#include <stdlib.h>

int add3arr_c(int arr[]);
int add3arr_s(int arr[]);

int main(int argc, char *argv[]) {
    int r;
    int arr[3];
    arr[0] = atoi(argv[1]);
    arr[1] = atoi(argv[2]);
    arr[2] = atoi(argv[3]);

    r = add3arr_c(arr);
    printf("add3arr_c(%p) = %d\n", arr, r);

    r = add3arr_s(arr);
    printf("add3arr_s(%p) = %d\n", arr, r);

    return 0;
}
