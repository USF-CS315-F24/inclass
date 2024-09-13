#include <stdio.h>
#include <stdlib.h>

int factrec_c(int n);
int factrec_s(int n);

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: fact_rec n\n");
        exit(-1);
    }

    int n = atoi(argv[1]);

    int c_result = factrec_c(n);
    printf("C: %d\n", c_result);

    int s_result = factrec_s(n);
    printf("Asm: %d\n", s_result);

    return 0;
}
