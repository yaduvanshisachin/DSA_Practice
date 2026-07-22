#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

// Prepare adjacency list from a list of edges
void prepareAdjList(vector<int> adj[], vector<pair<int, int>> &edges) {
    // for(int i = 0; i < edges.size(); i++) {
    //     int u = edges[i].first;
    //     int v = edges[i].second;

    //     adj[u].push_back(v);
    //     adj[v].push_back(u);
    // }

    for(auto &it : edges){
        adj[it.first].push_back(it.second);
        adj[it.second].push_back(it.first); //undirected graph
    }
}


void dfs(int node, vector<int> adj[], vector<bool> &vis) {
    vis[node] = true;
    cout << node <<" ";

    for(int nbr : adj[node]){
        if(!vis[nbr]){
            dfs(nbr, adj, vis);
        }
    }
}


void bfs(int node, vector<int> adj[], vector<bool> &vis) {
    queue<int> q;

    q.push(node);
    vis[node] = true;

    while(!q.empty()) {
        int frontNode = q.front();
        q.pop();

        cout << frontNode << " ";

        for(int it: adj[frontNode]) {
            if(!vis[it]) {
                q.push(it);
                vis[it] = true;
            }
        }
    }
}

int main() {
    vector<pair<int, int>> edges = {{1, 2}, {1, 3}, {2, 4}, {3, 5}, {6, 7}};

    int n = 7;
    vector<int> adj[8]; //n+1 = 8

    prepareAdjList(adj, edges);

    // DFS for disconnected graph
    vector<bool> vis(n+1, 0); //n+1 --> 1 based indexing (1....n nodes)
    for(int i=1; i<=n; i++){
        if(!vis[i]){
            dfs(i, adj, vis);
        }
    }

    //BFS for disconnected graph
    vector<bool> vis2(n+1, false);
    for(int i=1; i<=n; i++){
        if(!vis2[i]){
            bfs(i, adj, vis2);
        }
    }

    return 0;
}
