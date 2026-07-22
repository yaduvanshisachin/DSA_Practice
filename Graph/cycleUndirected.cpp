class Solution {
  public:
  
    bool isCycleDSF(unordered_map<int, vector<int>> &adj, int u, vector<bool> &visited, int parent){
        
        visited[u] = true;
        
        for(int &v : adj[u]){
            if(v == parent) continue;
            
            if(visited[v] == true){
                return true;
            }
            
            if(isCycleDSF(adj, v, visited, u))
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
        
        vector<bool> visited(V, false);
        
        for(int i=0; i<V; i++){
            if(!visited[i] && isCycleDSF(adj, i, visited, -1)){
                return true;
            }
        }
        
        return false;
        
    }
};







// BSF methode  


class Solution {
  public:
  
    bool isCycleBFS(unordered_map<int, vector<int>> &adj, int u, vector<bool> &visited) {
        queue<pair<int, int>> q;
        q.push({u, -1});
        visited[u] = true;

        while (!q.empty()) {
            auto [node, parent] = q.front();
            q.pop();

            for (int &neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
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

        // Build adjacency list
        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);  // Undirected graph
        }

        vector<bool> visited(V, false);

        // Handle disconnected components
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (isCycleBFS(adj, i, visited)) {
                    return true;
                }
            }
        }

        return false;
    }
};
