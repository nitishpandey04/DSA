#include <iostream>
#include <climits>
#include <vector>
#include <queue>

using namespace std;

int main() {

    int N, m;

    cin >> N >> m;

    vector<pair<int, int>> adj[N];

    for (int i = 0 ; i < m ; i ++) {

        int s, d, w;

        cin >> s >> d >> w;

        adj[s].push_back({d, w});

        adj[d].push_back({s, w});
    }

    int parent[N];

    int key[N];

    bool mstSet[N];

    for (int i = 0 ; i < N ; i ++) {

        parent[i] = -1;

        key[i] = INT_MAX;

        mstSet[i] = false;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, 0});

    key[0] = 0;

    for (int i = 0 ; i < N - 1 ; i ++) {

        int node = pq.top().second;

        pq.pop();

        mstSet[node] = true;

        int numEdges = adj[node].size();

        for (int j = 0 ; j < numEdges ; j ++) {

            pair<int, int> adj_node = adj[node][j];

            if (mstSet[adj_node.first]) continue;

            if (adj_node.second < key[adj_node.first]) {

                key[adj_node.first] = adj_node.second;

                pq.push({key[adj_node.first], adj_node.first});

                parent[adj_node.first] = node;
            }
        }
    }

    for (int i = 1 ; i < N ; i ++) {

        cout << parent[i] << " " << i << "\n";
    }

    return 0;
}
