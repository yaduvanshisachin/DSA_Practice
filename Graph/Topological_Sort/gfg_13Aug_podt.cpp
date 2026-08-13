#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> maxDistance(int V, int src, vector<vector<int>> &edges) {

        vector<pair<int, int>> adj[V];
        for(auto &e : edges) adj[e[0]].push_back({e[1], e[2]});

        vector<int> indegree(V, 0);

        for(int i = 0; i < V; i++) {
            for(auto &[v, w] : adj[i]) indegree[v]++;
        }

        queue<int> q;
        for(int i = 0; i < V; i++) {
            if(indegree[i] == 0) q.push(i);
        }

        vector<int> topoSort;
        while(!q.empty()) {
            int node = q.front(); q.pop();
            
            topoSort.push_back(node);

            for(auto &[v, w] : adj[node]) {
                indegree[v]--;

                if(indegree[v] == 0) q.push(v);
            }
        }

        vector<int> dist(V, INT_MIN);
        dist[src] = 0;

        for(int u : topoSort) {
            if(dist[u] == INT_MIN) continue;

            for(auto &[v, w] : adj[u]) {
                dist[v] = max(dist[v], dist[u] + w);
            }
        }

        return dist;
    }
};