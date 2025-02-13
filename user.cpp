#include <iostream>
#include "myvector.h"

using namespace std;

int main()
{
    auto showVector = [](const Vector & v)
    {
        cout << "Vector size/capacity: " << v.size() << '/' << v.capacity() << '\n';
        v.print();
        cout << '\n';
    };
    {
        cout << "=== Testing push_back() ===" << endl;
        Vector v;
        v.push_back("apple");
        v.push_back("banana");
        v.push_back("cherry");
        showVector(v);
        cout << "\n" << endl;
    
        cout << "=== Testing push_front() ===" << endl;
        v.push_front("orange");
        v.push_front("pear");
        showVector(v);
        cout << "\n" << endl;
    
        cout << "=== Testing pop_front() ===" << endl;
        v.pop_front();
        showVector(v);
        cout << "\n" << endl;
    
        cout << "=== Testing pop_back() ===" << endl;
        v.pop_back();
        showVector(v);
        cout << "\n" << endl;
    
        cout << "=== Testing operator[] ===" << endl;
        cout << "Accessing element at index 2:" << endl;
        v[2].print();
        cout << "\n" << endl;

        cout << "Setting element at index 1 to a different value:" << endl;
        v[1] = Payload("mango");
        showVector(v);
        cout << "\n" << endl;
    
        cout << "Attempting to set element at index 10:" << endl;
        // This will print an error message because the index is out of bounds
        v[10] = Payload("tomato");
        cout << "\n" << endl;
    }
}