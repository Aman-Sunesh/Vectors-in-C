#pragma once

#include "payload.h"

template<typename T>
struct Vector
{
    int vec_size;  // Tracks the number of elements in the vector
    int vec_capacity;  // Maximum possible number of elements in the vector
    T *arr;  // Dynamically allocated array of payloads

    Vector();
    void push_back(const T& x);
    void pop_back();
    void push_front(const T& x);
    void pop_front();
    T& operator[](int i);
    int size() const;
    int capacity() const;
    void print() const;
    ~Vector();

    struct Iterator
    {
        T* ptr;

        Iterator(T* ptr)
        {
            this->ptr = ptr;
        }

        Iterator& operator ++()
        {
            ++ptr;
            return *this;
        }

        bool operator !=(const Iterator& ptr2)
        {
            if (this->ptr != ptr2.ptr)
            {
                return true;
            }

            else
            {
                return false;
            }
        }

        T& operator *()
        {
            return *ptr;
        }
        
    };

    Iterator begin()
    {
        return Iterator(arr);
    }

    Iterator end()
    {
        return Iterator(arr + vec_size);
    }
}; 

#include "myvector.inc"