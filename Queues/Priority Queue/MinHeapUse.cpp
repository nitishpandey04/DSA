#include <iostream>
#include "MinPriorityQueue.h"

using namespace std;

int main() {

    MinPriorityQueue pq;

    pq.push(4);
    pq.push(2);
    pq.push(8);
    pq.push(6);
    pq.push(5);
    pq.push(1);
    pq.push(9);
    pq.push(10);
    pq.push(3);
    pq.push(7);
    
    while (!pq.empty()) {

        int e = pq.top();

        pq.pop();

        cout << e << " ";
    }
}