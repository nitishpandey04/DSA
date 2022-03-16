#include <vector>
#include <climits>

using namespace std;

class MaxPriorityQueue {

    vector<int> pq;

    public:

    bool empty() {

        return pq.size() == 0;
    }

    int size() {

        return pq.size();
    }

    int top() {

        if (pq.size() == 0) return INT_MIN;

        return pq[0];
    }

    void push(int x) {

        pq.push_back(x);
        
        int child = pq.size() - 1;
        
        int parent = (child - 1) / 2;
        
        while (child > 0 && pq[parent] < pq[child]) {
            
            swap(pq[parent], pq[child]);
            
            child = parent;
            
            parent = (child - 1) / 2;
        }
    }

    void pop() {

        if (pq.size() == 0) return;

        swap(pq[0], pq[pq.size() - 1]);
        
        pq.pop_back();
        
        int p = 0;

        while ((2 * p + 1 < pq.size() && pq[p] < pq[2 * p + 1]) || (2 * p + 2 < pq.size() && pq[p] < pq[2 * p + 2])) {

            int c = 2 * p + 1;

            if ((2 * p + 2 < pq.size()) && (pq[2 * p + 2] > pq[2 * p + 1])) c ++;

            swap(pq[p], pq[c]);

            p = c;
        }
    }
};
