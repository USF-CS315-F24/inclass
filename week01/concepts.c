// concepts.c - annotated C code

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

// The main() function returns an integer value. This value is
// returned back to the OS when the program returns from main().
// The two parameters defined for main() are:
//
// int argc
// The number of arguments passed on the command line to this program.
// The argv[0] parameter is always the path of the executable itself.
// The actual arguments start at argv[1].

// The main() function can be placed anywhere in the C file. Often you
// put main() either at the beginning of the file or at the end of the
// file. For large programs with lots of .c files, you main have a file
// with main() as the only function, like in main.c. There can be
// only one main function in a program. If main calls other functions,
// you either need to put these functions before main() or supply function
// prototypes for these function before main() and the function defintions
// (implementations) after main.

// This is the definition (implementation) of add2(). Since it is
// defined before main(), we don't need to provide a prototype for
// add2(). This is way some C programmers put main at the end of the
// file, so they don't need to supply prototypes.
int add2(int a, int b) {
    return a + b;
}

// This is the prototype for add3(). We need the prototype here because
// we have defined add3() after main().
int add3(int a, int b, int c);

// Variables defined outside of functions are global. They can
// be initialized and the space allocated for globals last the
// the lifetime of the program. That is, global variables cannot
// be deallocated. In this class, we will generally avoid global
// variables, and, instead, allocate all data on the stack.
int x_g = 99;

int main(int argc, char *argv[]) {
    // Memory for local variables is allocated on the stack
    // Note later, we learn assembly langauge, we will see that
    // in some cases the stack is not necessary, but it is useful
    // to think about local variables being allocated on the stack.
    // The nice thing about stack allocated variables, that is local
    // variables, is that the space for local variables is reclaimed
    // (deallocate) when a fuction returns.
    int x = 1;
    int y = 2;
    int r1, r2;

    r1 = add2(x, y);
    r2 = add3(x, y, x_g);

    printf("r1 = %d, r2 = %d\n", r1, r2);

    // Technically, since main() returns an int value, we need to return
    // a value here. Some C compilers allow return to be omitted if you
    // don't care about setting a return value. Some C compilers will
    // complain.
    return 0;
}

int add3(int a, int b, int c) {
    return a + b + c;
}
