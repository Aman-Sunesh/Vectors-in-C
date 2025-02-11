// Step 1: 

//myvector.h

#pragma once
#include "payload.h"

struct Vector {
    Payload *data;
    int size;          // Tracks the number of elements in the vector
    static const int CAPACITY = 4;  // Initial capacity of the vector

    Vector();          // Constructor to initialize the vector
    ~Vector();         // Destructor to release allocated memory
    void push_back(const Payload &p);  // Adds an element to the end
    void pop_back();         // Removes the last element
    int size() const;        // Returns the number of elements
    void print() const;      // Prints all the elements in the vector
};


// myvector.cpp

#include "myvector.h"
#include <iostream>

Vector::Vector() {
    data = new Payload[CAPACITY];  // Allocate memory for the initial capacity
    size = 0;
}

Vector::~Vector() {
    delete[] data;  // Clean up the allocated memory
}

void Vector::push_back(const Payload &p) {
    if (size >= CAPACITY) {
        std::cout << "Capacity reached, cannot add more elements.\n";
        return;
    }
    data[size++] = p;  // Add the element and increment size
}

void Vector::pop_back() {
    if (size > 0) {
        --size;  // Decrement size to remove the last element
    }
}

int Vector::size() const {
    return size;
}

void Vector::print() const {
    for (int i = 0; i < size; ++i) {
        data[i].print();
    }
}


// Step 2:

// myvector.h

struct Vector {
    Payload *data;
    int size;
    int capacity;  // Dynamic capacity of the vector

    Vector();            // Constructor to initialize the vector
    ~Vector();           // Destructor to release allocated memory
    void push_back(const Payload &p);  // Adds an element to the end
    void pop_back();     // Removes the last element
    int size() const;    // Returns the number of elements
    int capacity() const; // Returns the current capacity
    void print() const;  // Prints all the elements in the vector
    void resize();       // Resizes the array by doubling its capacity
};



// myvector.cpp

#include "myvector.h"
#include <iostream>

Vector::Vector() : size(0), capacity(1) {
    data = new Payload[capacity];  // Start with capacity of 1
}

Vector::~Vector() {
    delete[] data;  // Clean up the allocated memory
}

void Vector::push_back(const Payload &p) {
    if (size >= capacity) {
        resize();  // Resize the vector if needed
    }
    data[size++] = p;  // Add the element and increment size
}

void Vector::pop_back() {
    if (size > 0) {
        --size;  // Decrement size to remove the last element
    }
}

int Vector::size() const {
    return size;
}

int Vector::capacity() const {
    return capacity;
}

void Vector::resize() {
    capacity *= 2;  // Double the capacity
    Payload *new_data = new Payload[capacity];  // Create a new array
    for (int i = 0; i < size; ++i) {
        new_data[i] = data[i];  // Copy existing data to the new array
    }
    delete[] data;  // Release the old array
    data = new_data;  // Point to the new array
}

void Vector::print() const {
    for (int i = 0; i < size; ++i) {
        data[i].print();
    }
}


// user.cpp

#include <iostream>
#include "myvector.h"

int main() {
    auto showVector = [](const Vector &v) {
        std::cout << "Vector size/capacity: " << v.size() << '/' << v.capacity() << '\n';
        v.print();
        std::cout << '\n';
    };

    Vector v;
    v.push_back(Payload("apple"));
    v.push_back(Payload("pear"));
    showVector(v);
    v.push_back(Payload("banana"));
    showVector(v);
    v.pop_back();
    showVector(v);

    return 0;
}
