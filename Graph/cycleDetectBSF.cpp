#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <list>
using namespace std;

//Kahn's algorithm   -- (DAG)

bool topologicalSort(int n, vector<pair<int, int>> &edges, int v){
    unordered_map<int, list<int>> adj;

    for(int i=0; i<edges.size(); i++){
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
    }

    //find all indegrees;
    vector<int> indegree(v);
    for(auto i : adj){
        for(auto j : i.second){
            indegree[j]++;
        }
    }

    //push nodes having indegree 0
    queue<int> q;
    for(int i=0; i<v; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }

    //Do BSF
    int count = 0;
    while(!q.empty()){
        int front = q.front();
        q.pop();
        
        count++; // inc count

        //neghbour indegree update
        for(int neighbour: adj[front]){
            indegree[neighbour]--;
            if(indegree[neighbour] == 0){
                q.push(neighbour);
            }
        }
    }
    return count == n ? false : true;
}