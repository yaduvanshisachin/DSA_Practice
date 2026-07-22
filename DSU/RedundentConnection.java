import java.util.*;

class Solution {

    public boolean dfs(List<Integer>[] adj, int u, int v, boolean[] visited) {
        if (u == v) return true;

        visited[u] = true;

        for (int ngbr : adj[u]) {
            if (!visited[ngbr] && dfs(adj, ngbr, v, visited)) {
                return true;
            }
        }
        return false;
    }

    public int[] findRedundantConnection(int[][] edges) {
        List<Integer>[] adj = new ArrayList[1001];

        // initialize adjacency list
        for (int i = 0; i < 1001; i++) {
            adj[i] = new ArrayList<>();
        }

        for (int[] edge : edges) {
            int u = edge[0], v = edge[1];

            boolean[] visited = new boolean[1001];

            // if path already exists, this edge is redundant
            if (!adj[u].isEmpty() && !adj[v].isEmpty() && dfs(adj, u, v, visited)) {
                return new int[]{u, v};
            }

            // add edge
            adj[u].add(v);
            adj[v].add(u);
        }

        return new int[]{};
    }
}