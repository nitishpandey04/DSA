#include <tuple>
#include "EdgeList.h"
#include "UnionFind.h"

using namespace std;

int main() {
    
    int v, e;
    
    cin >> v >> e;
    
    EdgeList input(v, e); // Original Graph
    
    input.takeInput();
    
    input.sortbyWeight();
    
    EdgeList output(v, v - 1); // Minimum Spanning Tree
    
    UnionFind uf(v); // for cycle detection before inserting each minimum edge
    
    // Kruskal's Algorithm
    
    int i = 0;
    
    while (i < e && !output.full()) {
        
        tuple<int, int, int> t = input.get(i);
        
        int a = get<0>(t), b = get<1>(t);
        
        if (!uf.same(a, b)) {
            
            uf.unite(a, b);
            
            output.insert(t);
        }
        
        i ++;
    }
    
    output.print();
}
