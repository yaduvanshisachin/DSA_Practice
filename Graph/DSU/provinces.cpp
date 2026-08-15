#include<bits/stdc++.h>
using namespace std;

// DFS/BFS  --> O(n²) + O(V + E)

//DSU approach -- O(n² α(n))
class DSU {
    vector<int> parent, size;
public:
    DSU(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);

        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        if(x == parent[x]) return x;
        return parent[x] = find(parent[x]);
    }

    bool unite(int u, int v) {
        int pu = find(u);    
        int pv = find(v);

        if(pu == pv) return false;

        if(pu < pv)
            swap(pu, pv);

        parent[pv] = pu;
        size[pu] += size[pv];
        
        return true;
    }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        DSU dsu(n);
        int components = n;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(isConnected[i][j] && i != j) {
                    if(dsu.unite(i, j)) {
                        components--;
                    }
                }
            }
        }

        return components;
    }
};