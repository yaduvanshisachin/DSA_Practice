//we have seen topological sort using bfs (Kahn's Algo) , this is toposort using dfs
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

//dfs
void topoSortDFS(int node, vector<int> &vis, stack<int> st, vector<vector<int>> &adj){
    vis[node] = 1;

    for(auto &v : adj[node]){
        if(!vis[v]){
            topoSortDFS(v, vis, st, adj);
        }
    }
    // after reaching to last vis node, push it on to the stack 
    st.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int V){
    
    vector<vector<int>> adj;
    for(auto &it : edges){
        adj[it[0]].push_back(it[1]);
    }

    vector<int> vis(V, 0);
    stack<int> st;
    for(int i=0; i<V; i++){
        if(!vis[i]){
            topoSortDFS(i, vis, st, adj);
        }
    }

    vector<int> ans;
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}


//Cycle Detection in DAG
bool dfs(int node, vector<vector<int>>& adj, vector<bool>& vis,
        vector<bool>& recStack, stack<int>& st) {

    vis[node] = true;
    recStack[node] = true;

    for (int ngbr : adj[node]) {
        if (!vis[ngbr]) {
            if (dfs(ngbr, adj, vis, recStack, st))
                return true;
        }
        else if (recStack[ngbr]) {
            // Cycle detected
            return true;
        }
    }

    recStack[node] = false;
    st.push(node);
    return false;
}

vector<int> topologicalSortDFS(int V, vector<vector<int>>& adj) {
    vector<bool> vis(V, false);
    vector<bool> recStack(V, false);
    stack<int> st;

    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            if (dfs(i, adj, vis, recStack, st)) {
                cout << "Graph contains a cycle!\n";
                return {};
            }
        }
    }

    vector<int> topoOrder;
    while (!st.empty()) {
        topoOrder.push_back(st.top());
        st.pop();
    }

    return topoOrder;
}