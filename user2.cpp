#include <iostream> 
#include "mylist.h" 
#include "myvector.h"
#include "payload.h"
 
using namespace std;

#include <iostream>
#include "myvector.h"

using namespace std;

int main()
{
    auto showList = [](const List & s)
    {
        cout << "List size: " << s.size() << '\n';
        s.print();
        cout << '\n';
    };
    {
        cout << "=== Testing push_back() ===" << endl;
        List s;
        s.push_back("apple");
        s.push_back("banana");
        s.push_back("cherry");
        showList(s);
        cout << "\n" << endl;
    
        cout << "=== Testing push_front() ===" << endl;
        s.push_front("orange");
        s.push_front("pear");
        showList(s);
        cout << "\n" << endl;
    
        cout << "=== Testing pop_front() ===" << endl;
        s.pop_front();
        showList(s);
        cout << "\n" << endl;
    
        cout << "=== Testing pop_back() ===" << endl;
        s.pop_back();
        showList(s);
        cout << "\n" << endl;
    }
}