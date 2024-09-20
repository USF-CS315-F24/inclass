void strcpy_c(char *dst, char *src) {
    int i;

    for (i = 0; src[i] != '\0'; i++) {
        dst[i] = src[i];
    }

    dst[i] = '\0';
}
