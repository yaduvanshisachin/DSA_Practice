#include<bits/stdc++.h>
using namespace std;

class DSU {
    vector<int> parent, size;
public:
    DSU(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 0);
        
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
        
        if(size[pu] < size[pv])
            swap(pu, pv);
        
        parent[pv] = pu;
        size[pu] += size[pv];
        
        return true;
    }
};


class Solution {
  public:
    int minEdgesReq(int n, vector<vector<int>>& edges) {
        int m = edges.size();
        
        if(m < n - 1) return -1;
        
        DSU dsu(n);
        
        int components = n;
        for(auto &e : edges) {
            if(dsu.unite(e[0], e[1]))
                components--;
        }
        
        return components - 1;
    }
};

// we need to calculate 
// 1.  total number of components
// 2.  total number of extra edges
        
/*
    k component requires k-1 edges to connect
    
    if(total extra edges >= k - 1) ==> k - 1 operations required
*/