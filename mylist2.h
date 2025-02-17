#pragma once

#include "payload.h"


template<typename T>
struct Node
{
    T data;
    Node* next;

    Node(const T& data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

template<typename T>
struct List
{
    Node<T>* head;

    List();
    void push_front(const T& x);
    void pop_front();
    int size() const;
    void print() const;
    ~List();

    struct Iterator
    {
        Node<T>* node;

        Iterator(Node<T>* node)
        {
            this->node = node;
        }

        Iterator& operator ++()
        {
            if (node != nullptr)
            {
                node = node->next;
            }
            
            return *this;
        }

        bool operator !=(const Iterator& node2) const
        {
            if (this->node != node2.node)
            {
                return true;
            }

            else
            {
                return false;
            }
        }

        T& operator *()
        {
            return node->data;
        }
        
    };

    Iterator begin()
    {
        return Iterator(head);
    }

    Iterator end()
    {
        return Iterator(nullptr);
    }
}; 

#include "mylist.inc"