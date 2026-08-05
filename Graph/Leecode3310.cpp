#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {

        vector<int> adj[n];
        for(auto &it : invocations) {
            adj[it[0]].push_back(it[1]);
        }

        //indegree
        vector<int> indegree(n, 0);
        for (int i = 0; i < n; i++) {
            for(int v : adj[i]) {
                indegree[v]++;
            }
        }

        // dfs/bfs starting from buggy node (i.e. k)
        queue<int> q;   
        q.push(k);

        vector<bool> infected(n, false);
        infected[k] = true;

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            for(int v : adj[node]) {
                indegree[v]--;

                if(!infected[v]) {
                    infected[v] = true;
                    q.push(v);
                } 
            }
        }

        vector<int> ans;
        bool cannotRemove = false;

        for(int i = 0; i < n; i++) {
            if(infected[i] && indegree[i] > 0) {
                cannotRemove = true;
                break;
            }
            
            if(!infected[i])
                ans.push_back(i);
        }

        if(cannotRemove) {
            vector<int> vec(n);
            // for(int i = 0; i < n; i++) vec[i] = i;
            iota(vec.begin(), vec.end(), 0);

            return vec;
        }

        return ans;
    }
};