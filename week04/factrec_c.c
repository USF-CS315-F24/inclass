int factrec_c(int n) {
    int r;

    if (n == 0) {
        r = 1;
    } else {
        r = factrec_c(n - 1) * n;
    }

    return r;
}

int factrec_ret_c(int n) {
    int r;

    if (n == 0) {
        return 1;
    } else {
        return factrec_ret_c(n - 1) * n;
    }
}
