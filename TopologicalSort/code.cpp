#include<bits/stdc++.h>
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