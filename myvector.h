#pragma once

#include "payload.h"

using namespace std;

struct Vector
{
    int vec_size;  // Tracks the number of elements in the vector
    int vec_capacity;  // Maximum possible number of elements in the vector (For task 1, capacity = 4 (constant))
    Payload *arr;  // Dynamically allocated array of payloads

    Vector();
    void push_back(const Payload& x);
    void pop_back();
    int size() const;
    int capacity() const;
    void print() const;
    ~Vector();
}; 