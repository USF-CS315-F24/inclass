#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a maximum string length
// This should be used in all functions that copy or scan
// strings.
#define MAX_STR_LEN 128

// We can use a struct to package up the parsed config options
struct config_st {
    char str[MAX_STR_LEN];
    int count;
    bool header;
    bool footer;
};

// We pass a address to a config struct so we can initialize it
void config_init(struct config_st *cp) {
    // Make str a valid empty string
    cp->str[0] = '\0';
    // Default repeat count of 1
    cp->count = 1;
    cp->header = false;
    cp->footer = false;
}

void usage(void) {
    printf("echorepeat-cfg [-r count] [-h] [-f] <str>\n");
}

void parse_args(int argc, char *argv[], struct config_st *cp) {
    int i = 1;

    if (argc == 1) {
        usage();
        exit(0);
    }
    
    /* Process args */
    while (i < argc) {
        if (argv[i][0] == '-' && argv[i][1] == 'r'
            && argv[i][2] == '\0') {
            cp->count = atoi(argv[i + 1]);
            i += 2;
        } else if (argv[i][0] == '-' && argv[i][1] == 'h'
            && argv[i][2] == '\0') {
            cp->header = true;
            i += 1;
        } else if (argv[i][0] == '-' && argv[i][1] == 'f'
            && argv[i][2] == '\0') {
            cp->footer = true;
            i += 1;
        } else {
            strncpy(cp->str, argv[i], MAX_STR_LEN);
            i += 1;
        }
    }
}

void echorepeat(struct config_st *cp) {    
    if (cp->header) {
        printf("---\n");
    }

    for (int i = 0; i < cp->count; i++) {
        printf("%s\n", cp->str);
    }

    if (cp->footer) {
        printf("---\n");
    }
}

int main(int argc, char *argv[]) {
    struct config_st config;

    // See how we can use the config struct to connect
    // the different steps of the program. This keeps
    // main() clean and compact. It is easy to follow
    // each step.
    
    config_init(&config);
    parse_args(argc, argv, &config);
    echorepeat(&config);
}
