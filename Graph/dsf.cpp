#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
using namespace std;

// Prepare adjacency list from a list of edges
void prepareAdjList(unordered_map<int, list<int>> &adjList, vector<pair<int, int>> &edges) {
    for(int i = 0; i < edges.size(); i++) {
        int u = edges[i].first;
        int v = edges[i].second;

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
}

// Recursive DFS Traversal
void dfs(int vertex, unordered_map<int, list<int>> &adjList, unordered_map<int, bool> &visited, vector<int> &ans) {
    visited[vertex] = true;  // Mark the current node as visited
    ans.push_back(vertex);   // Store the current node into the result vector

    // Recursively visit all unvisited neighbors of the current node
    for(auto i: adjList[vertex]) {
        if(!visited[i]) {
            dfs(i, adjList, visited, ans);
        }
    }
}

// Function to handle disconnected components
void dfsTraversal(unordered_map<int, list<int>> &adjList, int totalVertices) {
    unordered_map<int, bool> visited;
    vector<int> ans;

    // Perform DFS for each disconnected component
    for (int i = 1; i <= totalVertices; i++) {
        if (!visited[i]) {
            dfs(i, adjList, visited, ans);
        }
    }

    // Print the DFS traversal result
    for (int i : ans) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    vector<pair<int, int>> edges = {
        {1, 2},
        {1, 3},
        {2, 4},
        {3, 5},
        {6, 7}
    };

    unordered_map<int, list<int>> adjList;

    // Prepare the adjacency list
    prepareAdjList(adjList, edges);

    // Perform DFS traversal for disconnected graph with 7 vertices (in this case)
    dfsTraversal(adjList, 7);

    return 0;
}