#include <bits/stdc++.h>

using namespace std;

#include "QueueUsingArray.h"

int main() {

    // dynamic array is used to implement queue

	Queue<int> q;

    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);

    cout << q.pop() << "\n";
    cout << q.pop() << "\n";
    cout << q.pop() << "\n";
    
    cout << q.getSize() << "\n";
    cout << q.isEmpty() << "\n";

    q.deallocate();
}
