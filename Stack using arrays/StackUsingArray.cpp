#include <bits/stdc++.h>

template <typename T>

class Stack {

    T* data;
    int index;
    int totalsize;

    public:
    Stack() {
        data = new T[5];
        totalsize = 5;
        index = 0;
    }

    int size() {
        return index;
    }

    bool isEmpty() {
        return index == 0;
    }

    T top() {
        if (isEmpty()) {
            cout << "Stack is empty!\n";
            return 0;
        }
        return data[index - 1];
    }

    T pop() {
        if (isEmpty()) {
            cout << "Stack is empty!\n";
            return 0;
        }
        index --;
        return data[index];
    }

    void push(T value) {
        if (index == totalsize) {
            T *newData = new T[totalsize * 2];
            for (int i = 0 ; i < totalsize ; i ++) {
                newData[i] = data[i];
            }
            delete [] data;
            data = newData;
            totalsize *= 2;
        }
        data[index] = value;
        index ++;
    }

    void deallocate() {
        delete [] data;
    }
};
