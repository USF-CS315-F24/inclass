#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int n = 1;
    int i = 1;
    char *str;
    bool header = false;

    // Process args using a simple loop to "consume" any command line
    // options. This approach makes it easy to support options in any
    // position on the command line.
    while (i < argc) {
        // Look for -r <n>
        // We can also write
        // if (!strncmp(argv[i], "-r", 3) {
        
        if (argv[i][0] == '-' && argv[i][1] == 'r'
            && argv[i][2] == '\0') {
            // Get <n>
            n = atoi(argv[i + 1]);
            // Skip argv[i] and argv[i+1] to get to the next arg
            i += 2;
        } else {
            // Get the string value to echo
            str = argv[i];
            // Skip to the next arg
            i += 1;
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%s\n", str);
    }
}
