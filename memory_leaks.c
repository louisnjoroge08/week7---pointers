
// ACTIVITY 3: MEMORY LEAKS (C VERSION)
// Learning Outcome: Evaluate memory leak risks and fix them

// Include standard I/O library for printf
#include <stdio.h>

// Include standard library for malloc and free
#include <stdlib.h>

// A function that allocates memory but forgets to free it
void fixLeak() {
    // Allocate memory
int *ptr = (int*)malloc(sizeof(int));
*ptr = 42;

printf("Inside fixed function. Value: %d\n", *ptr);

// THE FIX: The free() function returns the memory to the OS.
// free() takes the pointer as an argument.
free(ptr);

// GOOD PRACTICE: Set the pointer to NULL after freeing.
// This prevents using a "dangling pointer".
ptr = NULL;

printf("Memory has been successfully freed.\n");
}

int main() {
printf("--- Testing the Fix ---\n");
fixLeak();
return 0;
}
