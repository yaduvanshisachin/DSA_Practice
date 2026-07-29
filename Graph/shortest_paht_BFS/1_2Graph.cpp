#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int shortestPath(int V, int src, int dest, vector<vector<int>> &edges) {
        
        unordered_map<int, vector<int>> adj;
        int newNodes = 0;
    
        for(auto e : edges) {
            int u = e[0], v = e[1], w = e[2];
            
            if(w == 1) {
               adj[u].push_back(v);
               adj[v].push_back(u);
            }
            else {
                int node = V + newNodes;  //arbitary node
                newNodes++;
                
                adj[u].push_back(node);
                adj[node].push_back(u);
                
                adj[node].push_back(v);
                adj[v].push_back(node); // undirected graph
            }   
        }
        
        /****** BFS for shortest Path (edge weight is uniform) ******/
        queue<int> q;
        q.push(src);
        
        vector<int> dist(V + newNodes, -1);
        dist[src] = 0;
        
        while(q.size()) {
            int node = q.front();
            q.pop();
            
            if(node == dest) 
                break;
                
            for(auto nxt : adj[node]) {
                if(dist[nxt] != -1) continue; //parent pe nhi jana hai
                
                dist[nxt] = dist[node] + 1;
                q.push(nxt);
            }
        }
        
        return dist[dest];
    }
};