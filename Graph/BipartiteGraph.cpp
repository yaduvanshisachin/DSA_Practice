#include<bits/stdc++.h>
using namespace std;

bool isBipartite(vector<vector<int>> &adj) {
    
    int V = adj.size();
    vector<int> color(V, -1); //intially everyone is uncolored

    for(int node = 0; node < V; node++) {

        //already colored
        if(color[node] != -1) continue;

        queue<int> q;
        q.push(node);
        color[node] = 0;

        while(!q.empty()) {
            int u = q.front(); q.pop();

            for(int v : adj[u]) {
                // if neighbour is not colored
                if(color[v] == -1) {
                    color[v] = 1 - color[u];
                    q.push(v);
                }
                else if(color[v] == color[u]) 
                    return false; 
            }
        }

        return true;
    }   
}

// assign colors  0 and 1  
// color[neighbourNode] =  1 - color[currNode];