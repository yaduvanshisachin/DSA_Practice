#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minTime(vector<int> &duration, vector<vector<int>> &dependencies) {
        int n = duration.size();
        
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);
        
        for (auto &e : dependencies) {
            int u = e[0], v = e[1];
            
            adj[u].push_back(v);
            indegree[v]++;
        }
        
        //process the nodes having indegree = 0
        queue<int> q;
        vector<int> finishTime(n);
        
        for (int i = 0; i < n; i++) {
            if(indegree[i] == 0) {
                q.push(i);
                finishTime[i] = duration[i];
            }
        }
        
        int completed = 0;
        int minTime = 0;
        
        while (!q.empty()) {
            int node = q.front(); 
            q.pop();
            
            completed++;
            minTime = max(minTime, finishTime[node]);
            
            for (auto v : adj[node]) {
                
                finishTime[v] = max(
                        finishTime[v],
                        finishTime[node] + duration[v]
                    );
                
                indegree[v]--;
                
                if (indegree[v] == 0) {
                    q.push(v);
                }
            }
        }
        
        // there is cyclic dependency
        if (completed != n)
            return -1;
            
        return minTime;
    }
};