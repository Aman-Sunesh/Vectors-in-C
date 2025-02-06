#pragma once

#include "payload.h"

using namespace std;

struct Vector
{
    int size;
    int capacity;
    Payload arr[4];

    Vector();
    void push_back(const Payload& x);
    void pop_back();
    int get_size() const;
    int get_capacity() const;
    void showVector();
    //~Vector();
}; 