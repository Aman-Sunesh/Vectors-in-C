#include <iostream>
#include "myvector.h"

using namespace std;

Vector::Vector()
{
    vec_size = 0;
    vec_capacity = 1;
    arr = new Payload[vec_capacity];
}

void Vector::push_back(const Payload& x)
{
    if (vec_size == vec_capacity)
    {
        int new_capacity = vec_capacity * 2;
        Payload* new_arr = new Payload[new_capacity];

        for (int i = 0; i  < vec_size; i++)
        {
            new_arr[i] = arr[i];
        }

        delete[] arr;
        arr = new_arr;
        vec_capacity = new_capacity;
    }

    arr[vec_size] = x;
    vec_size = vec_size + 1;
}

void Vector::pop_back()
{
    if (vec_size == 0)
    {
        cout << "Error: Vector is already empty!" << endl;
    }

    else
    {
        vec_size = vec_size - 1;
    }
}

int Vector::size() const
{
    return vec_size;
}

int Vector::capacity() const
{
    return vec_capacity;
}


void Vector::print() const
{
    for (int i = 0; i < vec_size; i++)
    {
        arr[i].print();
    }
}


Vector::~Vector()
{
    delete[] arr;
}