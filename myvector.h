#pragma once

#include "payload.h"

struct Vector
{
    int vec_size;  // Tracks the number of elements in the vector
    int vec_capacity;  // Maximum possible number of elements in the vector
    Payload *arr;  // Dynamically allocated array of payloads

    Vector();
    void push_back(const Payload& x);
    void pop_back();
    int size() const;
    int capacity() const;
    void print() const;
    ~Vector();
}; 