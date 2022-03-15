#include <iostream>
#include <algorithm>
#include <tuple>

using namespace std;

bool comp(tuple<int, int, int> t1, tuple<int, int, int> t2) {
    
    bool x = (get<2>(t1) < get<2>(t2));

    return x;
}

class EdgeList {
  	
    int v;
    int e;
    int index;
    tuple<int, int, int> *edges;    
    
    public:
    EdgeList(int v, int e) {
        
        this -> v = v;
        
        this -> e = e;
        
        index = 0;
        
        edges = new tuple<int, int, int>[e];
    }
    
    ~EdgeList() {
        
        delete [] edges;
    }
    
    void takeInput() {
        
        for (int i = 0 ; i < e ; i ++) {
            
            int v1, v2, w;
            
            cin >> v1 >> v2 >> w;
            
            edges[i] = tuple<int, int, int>(v1, v2, w);
        }
        
        index = e;
    }
    
    tuple<int, int, int> get(int i) {
        
        tuple<int, int, int> t = edges[i];
        
        return t;
    }
    
    void insert(tuple<int, int, int> t) {
        
        if (index == e) return;
        
        edges[index] = t;
        
        index ++;
    }
    
    bool full() {
        
        return index == e;
    }
    
    void sortbyWeight() {
        
        sort(edges, edges + e, comp);
    }
    
    void print() {
        
        for (int i = 0 ; i < e ; i ++) {
            
            tuple<int, int, int> t = get(i);
            
            int v1 = std::get<0>(t), v2 = std::get<1>(t), w = std::get<2>(t);
            
            if (v1 > v2) swap(v1, v2);
            
            cout << v1 << " " << v2 << " " << w << "\n";
        }
    }
};