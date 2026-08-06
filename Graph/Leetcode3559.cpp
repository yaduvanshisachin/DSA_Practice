#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int MOD = 1e9 + 7;
    int n, cols;
    vector<vector<int>> ancestorTable;
    vector<int> depth;

    void dfs(int root, int parent,vector<int> adj[]) {
        ancestorTable[root][0] = parent;

        for(int &v : adj[root]) {
            if(v == parent) continue;

            depth[v] = depth[root] + 1;

            dfs(v, root, adj);
        }
    }
 
    void buildAncestorTable() {
        for (int j = 1; j < cols; j++) {
            for (int node = 0; node < n; node++) {
                int par = ancestorTable[node][j-1];
                
                if (par != -1)
                    ancestorTable[node][j] = ancestorTable[par][j-1];
            }
        }
    }

    int findLCA(int u, int v) {
        if(depth[u] < depth[v]) swap(u, v);

        int k = depth[u] - depth[v];  //jumps

        for(int j = 0; j < cols; j++) {
            if(k & (1 << j)) {  //if jth bit is set --> i can make jump
                u = ancestorTable[u][j];
            }
        }

        if(u == v) return u;  //both were in the same path

        //Try bigger jumps first
        for(int j = cols - 1; j >= 0; j--) {
            if(ancestorTable[u][j] == -1) continue;

            //if currJump of u != currJump v...keep jumping
            
            if(ancestorTable[u][j] != ancestorTable[v][j]) {
                u = ancestorTable[u][j];
                v = ancestorTable[v][j];
            }
        }

        return ancestorTable[u][0];
    }

    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        n = edges.size() + 1;
        cols = log2(n) + 1;
        
        vector<int> adj[n];
        for(auto &e : edges) {
            int u = e[0] - 1, v = e[1] -1;  //converting to 0 based indexing..

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        depth.assign(n, 0);
        ancestorTable.assign(n, vector<int>(cols, -1));

        dfs(0, -1, adj); 

        buildAncestorTable();

        //precompute power of 2
        vector<int> pow2(n + 1);
        pow2[0] = 1;

        for(int i = 1; i < n; i++) {
            pow2[i] = (2LL * pow2[i - 1]) % MOD;
        }
         
        vector<int> result;
        for(auto &q : queries) {
            int u = q[0]-1, v = q[1]-1;
            
            int lca  = findLCA(u, v);

            int d = depth[u] + depth[v] - 2 * depth[lca];

            if(d == 0) {
                result.push_back(0);
            }else
                result.push_back(pow2[d -1]);
        }

        return result;
    }
};