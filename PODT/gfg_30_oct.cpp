#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    using T = vector<int>; //{cost, node, K}  K--> remaining moves

    int shortestPath(int n, vector<vector<int>>& edges, string s, int k) {
        vector<pair<int, int>> adj[n];

        for(auto &e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
        }

        vector<vector<int>> dist(n, vector<int>(k+1, 1e9));
        priority_queue<T, vector<T>, greater<T>> pq; //min-heap

        dist[0][1] = 0; 
        pq.push({0, 0, 1}); 
        
        while(!pq.empty()) {
            auto vec = pq.top();
            int d = vec[0], node = vec[1], count = vec[2];
            pq.pop();
 
            if(d > dist[node][count]) 
                continue;

            if(node == n-1)
                return d;

            for (auto& [v, wt] : adj[node]) {
                
                int newCount = (s[v] == s[node] ? count + 1 : 1);

                if(newCount > k) continue;

                if(d + wt < dist[v][newCount]) {
                    dist[v][newCount] = d + wt;
                    pq.push({dist[v][newCount], v, newCount});
                }
            }
        }

        return -1;
    }
};

// can move only k steps
