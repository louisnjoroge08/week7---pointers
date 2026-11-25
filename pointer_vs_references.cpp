
// ACTIVITY 2: POINTERS VS REFERENCES
// Learning Outcome: Analyse code mixing pointers and references

#include <iostream>
using namespace std;

int  main() {
    // 1. A normal integer variable
    int originalValue = 100;

    // 2. A REFERENCE variable.
    // The '&' after 'int' means 'refValue' is an alias (another name) for originalValue.
    // It MUST be initialised when declared, and it cannot be changed to refer to another variable later.
    int & refValue = originalValue;

    // 3. A POINTER variable.
    // The '*'  means 'ptrValue' holds a memory address of an integer.
    // We use the '&' operator to get the address of originalValue and assign it to ptrValue.
    // We use '&' (address-of operator) to get the memory address of originalValue.
    int * ptrValue = &originalValue;

    cout << "--- Initial State ---" << endl;
    cout << "Original value: " << originalValue << endl;
    cout << "refValue: " << refValue << endl;
    cout << "ptrValue points to: " << *ptrValue << endl; // *dereferences to get the value

    // --- MODIFICATION 1 ---
    // Changing the reference changes the original variable.
    refValue = 200; // This changes originalValue to 200

    cout << "\n--- After setting refValue = 200 ---" << endl;
    cout << "Original value: " << originalValue << endl; // Expected 200
    cout << "refValue: " << refValue << endl; // Expected 200
    cout << "ptrValue points to: " << *ptrValue << endl;

    // --- MODIFICATION 2 ---
    // Changing the value via the pointer also changes the original variable.
    *ptrValue = 300; // *ptrValue means "the value AT the address"

    cout << "\n--- After setting *ptrValue = 300 ---" << endl;
    cout << "Original value: " << originalValue << endl; // Expected 300
    cout << "refValue: " << refValue << endl; // Expected 300
    cout << "ptrValue points to: " << *ptrValue << endl; // Expected 300

    // --- MODIFICATION 3 ---
    // We can change what the pointer points to:
    int anotherValue = 500;

    ptrValue = &anotherValue; // Now ptrValue points to anotherValue

    cout << "\n--- After changing what ptrValue points to ---" << endl;
    cout << "Original value: " << originalValue << endl; // Expected 300
    cout << "refValue: " << refValue << endl; // Expected 300
    cout << "ptrValue points to: " << *ptrValue << endl; // Expected 500

    // NOTE: We CANNOT do this with the reference!
    // refValue = anotherValue; would just copy the value 500 into originalValue.

    return 0;
}