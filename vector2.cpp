#include "vector2.h"
#include <iostream>

using namespace std;

Vector::Vector()
{
    _size = 0;
    _capacity = 1;
    arr = new Payload[_capacity];
}

void Vector::push_back(const Payload& x)
{
    if (_size == _capacity)
    {
        int new_capacity = _capacity * 2;
        Payload* new_arr = new Payload[new_capacity];

        for (int i = 0; i < _size; i++)
        {
            new_arr[i] = arr[i];
        }

        arr = new_arr;
        _capacity = new_capacity;
    }

    arr[_size] = x;
    _size = _size + 1;
}

void Vector::pop_back()
{
    if (_size == 0)
    {
        cout << "Error!";
    }

    else
    {
        _size -=1;
    }
}

int Vector::size() const{
    return _size;
}

int Vector::capacity() const{
    return _capacity;
}

void Vector::print() const{
    for (int i = 0; i < _size; i++)
    {
        arr[i].print() ;
        cout << "\n";
    }
}

Vector::~Vector()
{
    delete[] arr;
}