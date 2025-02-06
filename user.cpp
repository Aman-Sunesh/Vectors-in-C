#include <iostream> 
 
#include "myvector.h" 
 
using std::cout; 
 
int main() 
{ 
    auto showVector = [](const Vector & v) 
    { 
        cout << "Vector size: " << v.get_size() << '\n'; 
    }; 
 
    { 
        Vector v; 
        v.push_back("apple"); 
        v.push_back("pear"); 
        showVector(v); 
        v.pop_back(); 
        showVector(v); 
    } 
} 