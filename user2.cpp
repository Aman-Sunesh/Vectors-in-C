#include <iostream> 
#include "mylist2.h" 
#include "myvector2.h"
#include "payload.h"
 
using namespace std;

int main() 
{ 
    // Using List
    List<Payload> s;
    s.push_front(Payload("apple"));
    s.push_front(Payload("pear"));
    s.push_front(Payload("banana"));

    cout << "\n";

    for (const auto &i : s) 
    {
        i.print();  
        cout << "\n";
    }

    s.pop_front();
    cout << "\n";

    for (const auto &i : s) 
    {
        i.print();  
        cout << "\n";
    }

    cout << "\n";
    cout << "\n";

    // Using Vector 
    Vector<Payload> v;
    v.push_back(Payload("tomato"));
    v.push_back(Payload("carrot"));
    v.push_back(Payload("cucumber"));
    
    cout << "\n";

    for (const auto &i : v) 
    {
        i.print();  
        cout << "\n";
    }

    v.pop_back();
    cout << "\n";

    for (const auto &i : v) 
    {
        i.print();  
        cout << "\n";
    }

    return 0;
} 