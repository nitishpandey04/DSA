#include <iostream>
#include <utility>

using namespace std;

/* 
If we insert all elements of our array into priority queue and pop them,
elements will be in sorted order, either increasing or decreasing,
depending upon the type of priority queue and this is called heap sort

But, if we make a separate priority queue, space complexity of heap sort is O(n)
To do heap sort in place, we use the following logic

We are using minHeap below so the elements will be sorted in decreasing order.
*/

void upHeapify(int arr[], int size) {
    int child = size - 1;
    int parent = (child - 1) / 2;
    while (child > 0 && arr[child] < arr[parent]) {
        swap(arr[child], arr[parent]);
        child = parent;
        parent = (child - 1) / 2;
    }
}

void downHeapify(int arr[], int size) {
    int p = 0;
    while ((2*p+1 < size && arr[2*p+1] < arr[p]) || (2*p+2 < size && arr[2*p+2] < arr[p])) {
        int c = 2*p+1;
        if (2*p+2 < size && arr[2*p+2] < arr[2*p+1]) c ++;
        swap(arr[p], arr[c]);
        p = c;
    }
}

void heapSort(int arr[], int n) {
    int size = 1;
    for (int i = 1 ; i < n ; i ++) {
        size ++;
        upHeapify(arr, size);
    }
    for (int i = 0 ; i < n ; i ++) {
        swap(arr[0], arr[size - 1]);
        size --;
        downHeapify(arr, size);
    }
}

int main() {

    int n;
    cin >> n;
    int arr[n];
    for (int i = 0 ; i < n ; i ++) {
        cin >> arr[i];
    }
    heapSort(arr, n);
    for (int i = 0 ; i < n ; i ++) {
        cout << arr[i] << " ";
    }
}