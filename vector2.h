#pragma once

#include "payload.h"
#include <iostream>

struct Vector
{
    int _size;
    int _capacity;
    Payload* arr;

    Vector();
    void push_back(const Payload& x);
    void pop_back();
    int size() const;
    int capacity() const;
    void print() const;
    ~Vector();
};