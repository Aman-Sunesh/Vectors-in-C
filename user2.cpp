#include <iostream> 
#include "myvector.h" 
 
using std::cout; 
 
int main() 
{ 
    Vector v; 

    v.push_back("apple"); 
    v.push_back("pear"); 
    v.push_back("banana"); 

    for (const auto &i : v) 
    {
        i.print();  
        cout << "\n";
    }
    
    cout << "\n";
    v.pop_back(); 

    for (const auto &i : v) 
    {
        i.print();  
        cout << "\n";
    }
} 