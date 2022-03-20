#include <iostream>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

int main() {
    
    int v, e;
    
    cin >> v >> e;
    
    vector<pair<int, int>> adj[v];
    
    for (int i = 0 ; i < e ; i ++) {
        
        int s, d, w;
        
        cin >> s >> d >> w;
        
        adj[s].push_back({d, w});
        
        adj[d].push_back({s, w});
    }
    
    int distance[v];
    
    bool visited[v];
    
    for (int i = 0 ; i < v ; i ++) {
        
        distance[i] = INT_MAX;
        
        visited[i] = false;
    }
    
    distance[0] = 0;
    
	priority_queue<pair<int, int>> q;
    
    q.push({0, 0});
    
    while (!q.empty()) {
        
        int a = q.top().second;
        
        q.pop();
        
        if (visited[a]) continue;
        
        visited[a] = true;
        
        for (auto adj_node : adj[a]) {
            
        	int b = adj_node.first, w = adj_node.second;
        	
            if (distance[a] + w < distance[b]) {
                
                distance[b] = distance[a] + w;
                
                q.push({-distance[b], b});
            }
        }
    }
    
    for (int i = 0 ; i < v ; i ++) {
        
        cout << i << " " << distance[i] << "\n";
    }
    
    return 0;
}