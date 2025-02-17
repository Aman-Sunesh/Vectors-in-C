#include <iostream>

template<typename T>
List<T>::List()
{
    head = nullptr;
}

template<typename T>
void List<T>::push_front(const T& x)
{
    Node<T>* temp = new Node<T>(x);
    temp->next = head;
    head = temp;
}


template<typename T>
void List<T>::pop_front()
{
    if (head != nullptr)
    {
        Node<T>* temp = head;
        head = head->next;
        delete temp;
    }
}


template<typename T>
int List<T>::size() const
{
    Node<T>* current = head;
    int count = 0;

    while (current != nullptr)
    {
        current = current->next;
        count++;
    }

    return count;
}


template<typename T>
void List<T>::print() const
{
    Node<T>* current = head;

    while (current != nullptr)
    {
        current->data.print();
        current = current->next;
    }
}


template<typename T>
List<T>::~List()
{
    while (head != nullptr)
    {
        pop_front();
    }
}