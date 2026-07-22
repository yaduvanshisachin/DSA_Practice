#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
    vector<int> parent, size;

    DisjointSet(int n){
        parent.resize(n+1);
        size.resize(n+1, 1);

        for(int i=0; i<n; i++) parent[i] = i;
    }

    int find(int x){
        if(x == parent[x]) return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int u, int v){
        int pu = find(u);
        int pv = find(v);

        if(pu == pv) return;

        if(size[pu] < size[pv]){
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else{
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};