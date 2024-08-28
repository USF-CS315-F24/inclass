/* hello.c annotated */

/* C comments can be like this. */
// C Comments can also be like this.
// Pick one comment form and stick with it.

// Anything prefixed with the "#" symbol is a "directive."
// Technically, these are called C Preprocessor Directives.
// The C compiler, first processes the entire file looking
// for directives to apply. The #include directive recursively
// retrieves the content of header files to include in the final
// file to send to the C compiler proper.

// The include files are used to let the C compiler know about
// the function prototypes and type definitions that are needed
// to make library calls, e.g., printf(). A prototype is the type
// signature of a function. For example here is a prototype:
//
// int foo(int a, int b);
//
// Note that prototypes must have a semicolon at the and of the
// signature.
 
#include <stdio.h>

// You can use C preprocessor directives to create macros.
// A macro value is substituted for every occurrance of the macro
// name found in the file following the macro definition.
// In the following case N will be replace by 10.

#define N 10

// You can see the result of running the C preprocessor by doing
// the following:
//
// $ gcc -E file.c > file.cpreproc
//
// Then view file.cpreproc

// All code in C must be contained in functions.
// main() is a regular function, but it also is the first function
// to be called when you run a C program.

int main(int argc, char *argv[]) {
    int x = N;
    printf("Hello, CS315!\n");
    printf("x = %d\n", x);
}
