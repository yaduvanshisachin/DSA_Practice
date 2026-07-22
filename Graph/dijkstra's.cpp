#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> p; // {dist, node}

void dijkstra(int V, unordered_map<int, vector<p>> &adj, int source) {
    
    vector<int> dist(V, 1e9);
    priority_queue<p, vector<p>, greater<p>> pq;

    dist[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        auto [currDist, node] = pq.top();
        pq.pop();

        // Skip if we already found a better path
        if (currDist > dist[node]) continue;

        for (auto &edge : adj[node]) {
            int v = edge.first;
            int weight = edge.second;

            if (dist[node] + weight < dist[v]) {
                dist[v] = dist[node] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    // Print shortest distances
    cout << "Vertex\tDistance from Source\n";
    for (int i = 0; i < V; i++) {
        cout << i << "\t" << dist[i] << "\n";
    }
}

int main() {
    int V = 5; // Number of vertices
    unordered_map<int, vector<p>> adj; // Adjacency list: node -> list of {neighbor, weight}

    // Example graph (u -> v, weight)
    adj[0].push_back({1, 10});
    adj[0].push_back({4, 5});
    adj[1].push_back({2, 1});
    adj[1].push_back({4, 2});
    adj[2].push_back({3, 4});
    adj[3].push_back({0, 7});
    adj[3].push_back({2, 6});
    adj[4].push_back({1, 3});
    adj[4].push_back({2, 9});
    adj[4].push_back({3, 2});

    int source = 0;
    dijkstra(V, adj, source);

    return 0;
}