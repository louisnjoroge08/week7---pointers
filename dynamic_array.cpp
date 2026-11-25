
// ACTIVITY 4: DYNAMIC ARRAY WRAPPER (MINI VECTOR)
// Learning Outcome: Create a dynamic array that resizes

#include <iostream>
using namespace std;

// We define a class to group the pointer, size, and capacity together
class DynamicArray {
 private:
    int* data; // Pointer to the dynamic array
    int size; // Current number of elements
    int capacity; // Current allocated capacity

public:
    // Constructor to initialize the dynamic array
    DynamicArray(int initialCapacity) {
        capacity = initialCapacity;
        size = 0;
        // Allocate the initial raw array on the heap
        data = new int[capacity]; // Allocate memory for the array
    }

    // Destructor to free the allocated memory
    ~DynamicArray() {
        // Clean up the dynamic memory to prevent memory leaks
        delete[] data; // Free the allocated memory for the array
        }

        // Method to add a new element to the end
    void push_back(int value) {
        // 1. Check if we have run out of space
        if (size >= capacity) {
            // We need to resize!
            // a. Double the capacity
            int newCapacity = capacity * 2;

            // b. Allocate a new array with the new capacity
            int* newData = new int[newCapacity];

            // c. Copy the old data to the new array
            for (int i = 0; i < size; ++i) {
                newData[i] = data[i];

        }
            // d. Delete the old smaller array and free memory
            delete[] data;

            // e. Update the pointer and capacity
            data = newData;
            capacity = newCapacity;

            cout << "Resized array to new capacity: " << capacity << endl;
        }

        // 2. Add the new value to the end of the array
        data[size] = value;
        size++; // Increment the size to reflect the new element
}

    // Method to print the array contents
    void display() {
        cout << " Array (Size: " << size << ", Capacity: " << capacity << "): ";
        for (int i = 0; i < size; ++i) {
            cout << data[i] << " "; 
        }
        cout << endl;
    }

};

int main() {
    // Create a dynamic array with an initial capacity of 2
    DynamicArray myArray(2);
    cout << "Created dynamic array with capacity 2." << endl;

    // Add elements to the dynamic array and watch it resize when needed
    myArray.push_back(10);
    myArray.push_back(20);
    myArray.display(); // Should display: 10 20

    // This push_back will trigger a resize since the capacity is 2
    myArray.push_back(30);
    myArray.display(); // Should display: 10 20 30

    // Add more elements to see further resizing
    myArray.push_back(40);
    myArray.push_back(50);
    myArray.display(); // Should display: 10 20 30 40 50

    // When main() ends, the destructor of DynamicArray will be called, freeing the allocated memory and preventing memory leaks.
    cout << "Main function ending. Destructor will be called." << endl;
    return 0;
}
