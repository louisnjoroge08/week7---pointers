
// ACTIVITY 3A: THE MEMORY LEAK
// Learning Outcome: Evaluate memory leak risks

#include <iostream>
using namespace std;

// A function that allocates memory but forgets to delete it
void fixLeak()  {
   // 'new int' allocates memory on the HEAP (dynamic memory) for one integer.
   // It returns the memory address, which we store in 'ptr'.
    int * ptr = new int(42); // Allocate memory and initialize it to 42

    cout << "Inside function. The value is: " << *ptr << endl; // Dereference to get the value
    cout << " Memory allocated at address:" << ptr << endl;

    // THE FIX: The delete operator frees the memory back to the OS.
    delete ptr; // Free the allocated memory

    // GOOD PRACTICE: Set the pointer to nullptr after deleting to avoid dangling pointers.
    ptr = nullptr; // Avoid dangling pointer

    cout << " Memory has been successfully freed." << endl;

}
  
int main() {

    cout << "--- Testing the Fix for Memory Leak ---" << endl;

    fixLeak(); // Call the function that fixes the memory leak

    // At this point, the memory allocated in fixLeak() is now properly freed.
    // In a real application, this would prevent memory leaks and improve performance.

    cout << "Function finished. The memory is now freed." << endl;
    
    // If we called fixLeak() multiple times, we would not leak any memory.
    // the program would consume a constant amount of RAM and not crash.

    return 0;

}
    