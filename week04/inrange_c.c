int inrange_c(int x, int a, int b) {
    int r;

    if (x >= a && x <= b) {
        r = 1;
    } else {
        r = 0;
    }

    return r;
}
