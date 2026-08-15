#include<bits/stdc++.h>
using namespace std;

//Cycle Detection in Undirected Graph - Parent Tracking
class Solution {
  public:
  
    bool isCycleDSF(unordered_map<int, vector<int>> &adj, int u, vector<bool> &vis, int parent){
        
        vis[u] = true;
        
        for(int &v : adj[u]){
            if(v == parent) continue;
            
            if(vis[v] == true){
                return true;
            }
            
            if(isCycleDSF(adj, v, vis, u))
                return true;
        }
        
        return false;
    }
    
    bool isCyclic(int V, vector<vector<int>> &edges) {
        unordered_map<int, vector<int>> adj;
        
        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            
            adj[u].push_back(v);
            
            adj[v].push_back(u);
        }
        
        vector<bool> vis(V, false);
        
        for(int i=0; i<V; i++){
            if(!vis[i] && isCycleDSF(adj, i, vis, -1)){
                return true;
            }
        }
        
        return false;
        
    }
};



// BSF methode  

class Solution1 {
  public:
  
    bool isCycleBFS(unordered_map<int, vector<int>> &adj, int u, vector<bool> &vis) {
        queue<pair<int, int>> q;
        q.push({u, -1});
        vis[u] = true;

        while (!q.empty()) {
            auto [node, parent] = q.front();
            q.pop();

            for (int &neighbor : adj[node]) {
                if (!vis[neighbor]) {
                    vis[neighbor] = true;
                    q.push({neighbor, node});
                } else if (neighbor != parent) {
                    return true;  // Cycle detected
                }
            }
        }

        return false;
    }

    bool isCyclic(int V, vector<vector<int>> &edges) {
        unordered_map<int, vector<int>> adj;

        for (auto &e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);  // Undirected graph
        }

        vector<bool> vis(V, false);

        // Handle disconnected components
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (isCycleBFS(adj, i, vis)) {
                    return true;
                }
            }
        }

        return false;
    }
};
