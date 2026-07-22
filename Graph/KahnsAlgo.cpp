//Topological sort implementation using BFS approach is also known as kanh's algo

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;


//Kahn's algorithm
vector<int> topologicalSort(vector<vector<int>> &edges, int V){
    unordered_map<int, vector<int>> adj;

    for(auto &it : edges){
        adj[it[0]].push_back(it[1]); 
    }

    // Step 1: Compute in-degrees
    vector<int> indegree(V, 0);

    for(int i=0; i<V; i++){
        for(auto it : adj[i]){
            indegree[it]++;
        }
    }

    // Step 2 : push nodes having indegree zero to queue
    queue<int> q;
    for(int i=0; i<V; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }

    // Step 3: Process queue (Do BSF) 
    vector<int> topoOrder;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        topoOrder.push_back(node);

        //neighbours indegree update
        for(int neighbour: adj[node]){
            indegree[neighbour]--;
            if(indegree[neighbour] == 0){
                q.push(neighbour);
            }
        }
    }
    return topoOrder; //

    // For Cycle detection
    // return topoOrder.size() == V;
}