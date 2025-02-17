#include <iostream>
#include <string>

using std::string;
using std::cout;

// Payload class from the original code
struct Payload {
    static int counter;
    int id;
    string name;

    // Constructor with default arguments
    Payload(string n = "") : id(++counter), name(n) { say_born(); }

    // Destructor
    ~Payload() { say_die(); }

    // Constructor taking a C-style string
    Payload(const char* n) : Payload(string(n)) {}

    // Copy Constructor
    Payload(const Payload& x) : id(++counter), name(x.name) { say_born(); }

    // Move Constructor
    Payload(Payload&& x) : id(++counter), name(x.name) { say_born(); }

    // Copy Assignment Operator
    void operator=(const Payload& x) { name = x.name; }

    // Member function to print a message when an object is born
    void say_born() const { if (REPORT) { print(); cout << " is born\n"; } }

    // Member function to print a message when an object dies
    void say_die() const { if (REPORT) { print(); cout << " dies\n"; } }

    // Method to print the object’s data
    void print() const { cout << '('; if (REPORT) cout << id << ':'; cout << name << ')'; }

    // Flag for reporting object creation/destruction
    const static bool REPORT = false;
};

int Payload::counter = 0;

// Node structure for the singly linked list
struct Node {
    Payload data;
    Node* next;

    // Constructor
    Node(const Payload& p) : data(p), next(nullptr) {}
};

// List structure that holds a singly linked list of Payload objects
struct List {
    Node* head;

    // Constructor
    List() : head(nullptr) {}

    // Destructor
    ~List() {
        while (head) {
            pop_front();
        }
    }

    // Method to add a new element at the front
    void push_front(const string& name) {
        Node* new_node = new Node(Payload(name));
        new_node->next = head;
        head = new_node;
    }

    // Method to remove the element at the front
    void pop_front() {
        if (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Method to get the size of the list by iterating through it
    size_t size() const {
        size_t count = 0;
        Node* current = head;
        while (current) {
            count++;
            current = current->next;
        }
        return count;
    }

    // Method to print all elements in the list
    void print() const {
        Node* current = head;
        while (current) {
            current->data.print();
            current = current->next;
        }
    }
};

// User code to test the implementation
int main() 
{ 
    auto showList = [](const List & s) 
    { 
        cout << "List size: " << s.size() << '\n'; 
        s.print(); cout << '\n';
    }; 
 
    { 
        List s; 
 
        s.push_front("apple"); 
        s.push_front("pear"); 
        s.push_front("banana"); 
 
        showList(s); 
        s.pop_front(); 
        showList(s); 
    }
} 

