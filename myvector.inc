#include <iostream>

using namespace std;

template<typename T>
Vector<T>::Vector()
{
    vec_size = 0;
    vec_capacity = 1;
    arr = new T[vec_capacity];
}

template<typename T>
void Vector<T>::push_back(const T& x)
{
    if (vec_size == vec_capacity)
    {
        int new_capacity = vec_capacity * 2;
        T* new_arr = new T[new_capacity];

        for (int i = 0; i < vec_size; i++)
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


template<typename T>
void Vector<T>::pop_back()
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


template<typename T>
void Vector<T>::push_front(const T& x)
{
    if (vec_size == vec_capacity)
    {
        vec_capacity *=2;
    }

    T* new_arr = new T[vec_capacity];

    for (int i = 0; i < vec_size; i++)
    {
        new_arr[i + 1] = arr[i];
    }

    delete[] arr;
    
    arr = new_arr;
    arr[0] = x;
    vec_size = vec_size + 1;
}


template<typename T>
void Vector<T>::pop_front()
{
    if (vec_size == 0)
    {
        cout << "Error: Vector is already empty!" << endl;
    }

    else
    {
        for (int i = 1; i < vec_size; i++)
        {
            arr[i-1] = arr[i];
        }

        vec_size = vec_size - 1;
    }
}


template<typename T>
T& Vector<T>::operator[](int i)
{
    if (i < 0 || i >= vec_size)
    {
        cout << "Error: Index out of range\n";
    }
    
    return arr[i];
}


template<typename T>
int Vector<T>::size() const
{
    return vec_size;
}


template<typename T>
int Vector<T>::capacity() const
{
    return vec_capacity;
}


template<typename T>
void Vector<T>::print() const
{
    for (int i = 0; i < vec_size; i++)
    {
        arr[i].print();
    }
}


template<typename T>
Vector<T>::~Vector()
{
    delete[] arr;
}