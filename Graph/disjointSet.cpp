#include<bits/stdc++.h>
using namespace std;

//this code works for both 0 and 1 based indexing

class DisjointSet{
public:
    vector<int> rank, parent, size;

    DisjointSet(int n){
        rank.resize(n+1, 0);
        parent.resize(n+1);
        size.resize(n+1, 1);

        for(int i=0; i<=n; i++){
            parent[i] = i;
        }
    }

    int find(int node){
        if(node == parent[node])
            return node;
        return parent[node] = find(parent[node]);
    }

    void unionByRank(int u, int v){
        int parent_u = find(u);
        int parent_v = find(v);

        if(parent_u == parent_v) return; //u & v are already in same component

        if(rank[parent_u] < rank[parent_v]){
            parent[parent_u] = parent_v;
        }else if(rank[parent_u] > rank[parent_v]){
            parent[parent_v] = parent_u;
        }else{
            parent[parent_v] = parent_u;
            rank[parent_u]++;
        }
    }

    void unionBySize(int u, int v){
        int parent_u = find(u);
        int parent_v = find(v); 

        if(parent_u == parent_v) return;

        if(size[parent_u] < size[parent_v]){
            parent[parent_u] = parent_v;
            size[parent_v] += size[parent_u];
        }else{
            parent[parent_v] = parent_u;
            size[parent_u] += size[parent_v];
        }
    }
};


// for CP , fast writing
class DisjointSet {
public:
    vector<int> parent, size;

    DisjointSet(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);

        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (x == parent[x]) return x;
        return parent[x] = find(parent[x]); // path compression
    }

    void unite(int u, int v) {
        int pu = find(u);
        int pv = find(v);

        if (pu == pv) return;

        // union by size
        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};