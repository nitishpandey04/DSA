#include "Node.cpp"

template <typename T>

class Stack {

    Node<T> *head;
    int size;

    public:

    Stack() {
        head = NULL;
        size = 0;
    }

    int getSize() {
        return size;
    }

    bool isEmpty() {
        return size == 0; 
    }

    void push(T value) {
        Node<T> *newNode = new Node<T>(value);
        newNode -> next = head;
        head = newNode;
        size ++;
    }

    T top() {
        if (size == 0) {
            cout << "stack is empty!\n";
            return 0;
        }
        return head -> data;
    }

    T pop() {
        if (size == 0) {
            cout << "stack is empty!\n";
            return 0;
        }
        Node<T> *temp = head;
        head = head -> next;
        temp -> next = NULL;
        T value = temp -> data;
        delete temp;
        size --;
        return value;
    }

    void deallocate() {
        while (head != NULL) {
            Node<T> *temp = head;
            head = head -> next;
            delete temp;
        }
    }
};
