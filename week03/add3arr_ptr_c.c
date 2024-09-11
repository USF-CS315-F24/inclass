int add3arr_c(int arr[]) {
    return arr[0] + arr[1] + arr[2];
}


int add3arr_ptr_c(int *arr) {
    int sum;
    sum = *arr;
    arr = arr + 1;
    sum = sum + *arr;
    arr = arr + 1;
    sum = sum + *arr;

    return sum;
}
