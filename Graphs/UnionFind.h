class UnionFind {
    
    int n;  
    int *link;
    int *size;
    
    int find(int x) {

        while (x != link[x]) x = link[x];

        return x;
    }
    
    public:
    UnionFind(int n) {
        
        this -> n = n;
        
        link = new int[n];
        
        for (int i = 0 ; i < n ; i ++) {
            
            link[i] = i;
        }
        
        size = new int[n];
        
        for (int i = 0 ; i < n ; i ++) {
            
            size[i] = 1;
        }
    }
    
    ~UnionFind() {
        
        delete [] link;
        
        delete [] size;
    }
    
    bool same(int a, int b) {
    
        bool x = find(a) == find(b);

        return x;
    }
    
    void unite(int a, int b) {
    
        a = find(a);

        b = find(b);

        if (size[a] < size[b]) swap(a, b);

        size[a] += size[b];

        link[b] = a;
    }
};