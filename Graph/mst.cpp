#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;

class Solution {
  public:
    typedef tuple<int,int,int> P;;
    int spanningTree(int V, vector<vector<int>>& edges) {
        
        unordered_map<int, vector<pair<int,int>> > adj;
        vector<int> vis(V, 0);
        int sum = 0;
        vector<vector<int>> mst; //edges in mst
        
        for(auto &it : edges){
            adj[it[0]].push_back({it[1], it[2]}); //{node, wt}
            adj[it[1]].push_back({it[0], it[2]}); 
        }
        
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, 0, -1}); //{wt, node, parent}
        
        while(!pq.empty()){
            auto [wt, node, parent] = pq.top();
            pq.pop();
            
            if(vis[node]) continue;
            vis[node] = 1;
            sum += wt;
            mst.push_back({node, parent}); 
            
            for(auto &v : adj[node]){
                auto [nextNode, edgeWt] = v;
                if(!vis[nextNode]){
                    pq.push({edgeWt, nextNode, node});
                }
            }
        }
        
        return sum;
    }
};




// typedef tuple<int,int,int> P;

// priority_queue<P, vector<P>, greater<P>> pq;
// pq.push({0, 0, -1});

// while(!pq.empty()){
//     auto [wt, node, parent] = pq.top();
//     pq.pop();

//     if(vis[node]) continue;

//     vis[node] = 1;
//     sum += wt;

//     if(parent != -1) {
//         mst.push_back({parent, node, wt});
//     }

//     for(auto &v : adj[node]){
//         auto [nextNode, edgeWt] = v;
//         if(!vis[nextNode]){
//             pq.push({edgeWt, nextNode, node});
//         }
//     }
// }