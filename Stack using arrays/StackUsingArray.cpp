#include <bits/stdc++.h>

class Stack {

    int* data;
    int index;
    int totalsize;

    public:
    Stack() {
        data = new int[5];
        totalsize = 5;
        index = 0;
    }

    int size() {
        return index;
    }

    bool isEmpty() {
        return index == 0;
    }

    int top() {
        if (isEmpty()) {
            cout << "Stack is empty!\n";
            return INT_MIN;
        }
        return data[index - 1];
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack is empty!\n";
            return INT_MIN;
        }
        index --;
        return data[index];
    }

    void push(int value) {
        if (index == totalsize) {
            int *newData = new int[totalsize * 2];
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
