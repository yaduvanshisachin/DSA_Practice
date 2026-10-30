#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n;
    vector<int> tin, tout, eulerTour;
    int time;
    
    vector<int> segTree;

    vector<vector<int>> ancestorTable;
    vector<int> depth;
    int cols;


    void dfs(int node, int parent, int d, string& s, vector<int> adj[]) {
        depth[node] = d;
        ancestorTable[node][0] = parent;

        tin[node] = time;
        eulerTour[time] = (1 << (s[node] - 'a')); //"a" = 001, "b" = 0101 : Entering
        time++;

        for(int &child : adj[node]) {
            if(child == parent) {
                continue;
            }
            dfs(child, node, d+1, s, adj);
        }

        tout[node] = time;
        eulerTour[time] = (1 << (s[node] - 'a')); //Leaving
        time++;
    }

    // Segment Tree : Build (For XOR)
    void build(int i, int l, int r, vector<int>& nums) {
        if(l == r) {
            segTree[i] = nums[l];
            return;
        }

        int mid = l + (r-l)/2;
        build(2*i+1, l, mid, nums);
        build(2*i+2, mid+1, r, nums);
        segTree[i] = segTree[2*i+1] ^ segTree[2*i+2];
    }

    //Segment Tree : Point update (XOR)
    void update(int index, int val, int i, int l, int r) {
        if(l == r) {
            segTree[i] = val;
            return;
        }

        int mid = l + (r-l)/2;
        if(index <= mid) {
            update(index, val, 2*i+1, l, mid);
        } else {
            update(index, val, 2*i+2, mid+1, r);
        }

        segTree[i] = segTree[2*i+1] ^ segTree[2*i+2];
    }

    //Segment Tree : Search Query (Xor)
    int query(int ql, int qr, int i, int l, int r) {
        if(l > qr || r < ql) {
            return 0;
        }

        if(l >= ql && r <= qr) {
            return segTree[i];
        }

        int mid = l + (r-l)/2;
        return query(ql, qr, 2*i+1, l,    mid) ^
               query(ql, qr, 2*i+2, mid+1, r);
    }

    // Binary Lifting Code for building ancestorTable
    void buildAncestorTable() {
        for(int j = 1; j < cols; j++) {
            for(int node = 0; node < n; node++) {
                if(ancestorTable[node][j-1] != -1) {
                    ancestorTable[node][j] = ancestorTable[ ancestorTable[node][j-1] ][j-1];
                }
            }
        }
    }

    //get LCA using Binary Lifting
    int getLCA(int u, int v) {
        if(depth[u] < depth[v]) swap(u, v);

        int diff = depth[u] - depth[v];
        for(int j = 0; j < cols; j++) {
            if(diff & (1 << j)) {
                u = ancestorTable[u][j];
            }
        }

        if(u == v) 
            return u;

        for(int j = cols - 1; j >= 0; j--) {
            if(ancestorTable[u][j] != ancestorTable[v][j]) {
                u = ancestorTable[u][j];
                v = ancestorTable[v][j];
            }
        }

        return ancestorTable[u][0];
    }

    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        this->n = n;

        vector<int> adj[n];
        for(auto &e : edges) {
            int u = e[0], v = e[1];
              
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        tin.assign(n, 0);
        tout.assign(n, 0);
        depth.assign(n, 0);
        eulerTour.assign(2*n, 0); //Sees each node at inTime and outTime

        //root = 0
        time = 0;
        cols = log2(n) + 1;
        ancestorTable.assign(n, vector<int>(cols, -1));
        
        dfs(0, -1, 0, s, adj);


        //Build Segment Tree for the array - eulerTour -> size = 2*n
        int N = 2*n; //size of eulerTour array
        segTree.resize(4*N, 0);
        build(0, 0, N-1, eulerTour);
        
        buildAncestorTable();

        vector<bool> result;

        for (string &q : queries) {
            stringstream ss(q);  // String[] splits = q.split(" ")
            string type;
            ss >> type;

            if(type == "update") { //update ui c
                int node;
                char c;

                ss >> node >> c;

                int charValue = (1 << (c - 'a'));
                s[node] = c;
                update(tin[node], charValue, 0, 0, 2*n-1);
                update(tout[node], charValue, 0, 0, 2*n-1);
            } else { //query ui vi
                int u, v;

                ss >> u >> v;

                int lcaNode = getLCA(u, v);
                char ch = s[lcaNode];
                int charValue = (1 << (ch - 'a'));

                int mask = query(0, tin[u], 0, 0, 2*n-1) ^
                           query(0, tin[v], 0, 0, 2*n-1) ^
                           charValue;
                
                result.push_back((mask & (mask-1)) == 0);       
            }
        }
        return result;

    }
};