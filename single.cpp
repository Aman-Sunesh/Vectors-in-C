#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

// ==================== Payload ====================

struct Payload
{
    static int counter;
    int id;
    string name;
    
    // Constructor with default arguments
    Payload(string n = "") : id(++counter), name(n) { say_born(); }
    
    // Destructor
    ~Payload() { say_die(); }
    
    // Constructor taking a C-style string
    Payload(const char * n) : Payload(string(n)) {}
    
    // Copy Constructor
    Payload(const Payload & x) : id(++counter), name(x.name) { say_born(); }
    
    // Move Constructor
    Payload(Payload && x) : id(++counter), name(x.name) { say_born(); }
    
    // Copy Assignment Operator
    void operator=(const Payload & x) { name = x.name; }
    
    // Member function to print a message when an object is born
    void say_born() const;
    
    // Member function to print a message when an object dies
    void say_die() const;
    
    // Method to print the object’s data
    void print() const;
};

int Payload::counter = 0;
const bool REPORT = false;

void Payload::say_born() const
{
    if (REPORT)
    { 
        print(); 
        cout << " is born" << endl; 
    }
}

void Payload::say_die() const
{
    if (REPORT)
    { 
        print(); 
        cout << " dies" << endl; 
    }
}

void Payload::print() const
{
    cout << '(';
    if (REPORT)
        cout << id << ':';
    cout << name << ')';
}

// ==================== Vector ====================

// NOTE: In the original code the member variables were named "size" and "capacity" 
// and function names were also "size()" and "capacity()". To compile in one file 
// without altering the functions’ logic, the data members have been renamed to _size 
// and _capacity.

struct Vector {
    Payload *data;
    int _size;      // current number of elements (originally "size")
    int _capacity;  // dynamic capacity of the vector (originally "capacity")

    Vector();            // Constructor to initialize the vector
    ~Vector();           // Destructor to release allocated memory
    void push_back(const Payload &p);  // Adds an element to the end
    void pop_back();     // Removes the last element
    int size() const;    // Returns the number of elements
    int capacity() const; // Returns the current capacity
    void print() const;  // Prints all the elements in the vector
    void resize();       // Resizes the array by doubling its capacity
};

Vector::Vector() : _size(0), _capacity(1)
{
    data = new Payload[_capacity];  // Start with capacity of 1
}

Vector::~Vector() {
    delete[] data;  // Clean up the allocated memory
}

void Vector::push_back(const Payload &p) {
    if (_size >= _capacity) {
        resize();  // Resize the vector if needed
    }
    data[_size++] = p;  // Add the element and increment _size
}

void Vector::pop_back() {
    if (_size > 0)
    {
        _size--;
        // Explicitly call the destructor of the removed element.
        data[_size].~Payload();
    }
}

int Vector::size() const {
    return _size;
}

int Vector::capacity() const {
    return _capacity;
}

void Vector::resize() {
    _capacity *= 2;  // Double the capacity
    Payload *new_data = new Payload[_capacity];  // Create a new array
    for (int i = 0; i < _size; ++i) {
        new_data[i] = data[i];  // Copy existing data to the new array
    }
    delete[] data;  // Release the old array
    data = new_data;  // Point to the new array
}

void Vector::print() const {
    for (int i = 0; i < _size; ++i) {
        data[i].print();
    }
}

// ==================== Main ====================

int main() 
{
    auto showVector = [](const Vector & v)
    {
        cout << "Vector size/capacity: " << v.size() << '/' << v.capacity() << '\n';
        v.print();
        cout << '\n';
    };
    
    {
        Vector v;
        v.push_back("apple");
        showVector(v);
        v.push_back("pear");
        v.push_back("banana");
        showVector(v);
        v.pop_back();
        showVector(v);
    }
}


