template <typename T>

class Queue {

    T* data;
    int fI;
    int nI;
    int size;
    int capacity;

    public:

    Queue() {    
        data = new T[5];
        fI = -1;
        nI = 0;
        size = 0;
        capacity = 5;
    }

    int getSize() {
        return size;
    }

    bool isEmpty() {
        return size == 0;
    }

    void push(T value) {
        if (size == capacity) {
            T* newData = new T[capacity * 2];
            int j = 0;
            for (int i = fI ; i < capacity ; i ++) {
                newData[j] = data[i];
                j ++;
            }
            for (int i = 0 ; i < fI ; i ++) {
                newData[j] = data[i];
                j ++;
            }
            delete [] data;
            data = newData;
            nI = capacity;
            capacity *= 2;
            fI = 0;
        }
        if (fI == -1) {
            fI = 0;
        }
        data[nI] = value;
        nI ++;
        size ++;
        if (nI == capacity) nI = 0;
    }

    T pop() {
        if (size == 0) {
            cout << "Queue is empty!\n";
            return 0;
        }
        T ans = data[fI];
        fI ++;
        if (fI == capacity) fI = 0;
        size --;
        return ans;
    }

    T front() {
        if (size == 0) {
            cout << "Queue is empty!\n";
            return 0;
        }
        return data[fI];
    }

    void deallocate() {
        delete [] data;
    }
};
