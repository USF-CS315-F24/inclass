#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int n = 1;
    int i = 1;
    char *str;
    bool header = false;


    /* Process args */
    while (i < argc) {
        if (argv[i][0] == '-' && argv[i][1] == 'r'
            && argv[i][2] == '\0') {
            n = atoi(argv[i + 1]);
            i += 2;
        } else if (argv[i][0] == '-' && argv[i][1] == 'h'
            && argv[i][2] == '\0') {
            header = true;
            i += 1;
        } else {
            str = argv[i];
            i += 1;
        }
    }

    if (header) {
        printf("---\n");
    }
    for (int i = 0; i < n; i++) {
        printf("%s\n", str);
    }
}
