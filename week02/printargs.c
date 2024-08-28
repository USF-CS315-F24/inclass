#include <stdio.h>

int main(int argc, char *argv[]) {

    // Print all the available command line arguments.
    // argv[0] is the path to this executable.
    
    for (int i = 0; i < argc; i++) {
        printf("argv[%d] = %s\n", i, argv[i]);
    }

    // The last valid argv[] entry is NULL 0.
    // In this way you can also write the loop above as this:

    for (int i = 0; argv[i] != 0; i++) {
        printf("argv[%d] = %s\n", i, argv[i]);
    }
}
