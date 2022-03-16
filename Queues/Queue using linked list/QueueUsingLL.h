#include <cstddef>

#include "Node.cpp"

template <typename T>

class Queue {

    Node<T>* head;
    Node<T>* tail;
    int size;

    public:

    Queue() {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    int getSize() {
        return size;
    }

    bool isEmpty() {
        return size == 0;
    }

    void push(T value) {
        Node<T>* newNode = new Node<T>(value);
        if (size == 0) {
            head = newNode;
            tail = newNode;
        } else {
            tail -> next = newNode;
            tail = tail -> next;
        }
        size ++;
    }

    T pop() {
        if (size == 0) {
            cout << "Queue is empty!\n";
            return 0;
        }
        T value = head -> data;
        Node<T> *temp = head;
        head = head -> next;
        delete temp;
        size --;
        return value;
    }

    T front() {
        if (size == 0) {
            cout << "Queue is empty!\n";
            return 0;
        }
        return head -> data;
    }

    void deallocate() {
        while (head != NULL) {
            Node<T>* temp = head;
            head = head -> next;
            delete temp;
        }
    }
};
