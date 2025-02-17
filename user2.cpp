#include <iostream> 
#include "mylist2.h" 
 
using std::cout; 
 
int main() 
{ 
    List s; 

    s.push_front("apple"); 
    s.push_front("pear"); 
    s.push_front("banana"); 

    for (const auto &i : s) 
    {
        i.print();  
        cout << "\n";
    }
    
    cout << "\n";
    s.pop_front(); 

    for (const auto &i : s) 
    {
        i.print();  
        cout << "\n";
    }
} 