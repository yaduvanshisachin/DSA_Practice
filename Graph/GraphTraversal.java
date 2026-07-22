package Graph;
import java.util.*;

public class GraphTraversal {

    // Prepare adjacency list from edges
    static void prepareAdjList(List<List<Integer>> adj, List<int[]> edges) {
        for (int[] edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj.get(u).add(v);
            adj.get(v).add(u); // undirected graph
        }
    }

    // DFS
    static void dfs(int node, List<List<Integer>> adj, boolean[] vis) {
        vis[node] = true;
        System.out.print(node + " ");

        for (int nbr : adj.get(node)) {
            if (!vis[nbr]) {
                dfs(nbr, adj, vis);
            }
        }
    }

    // BFS
    static void bfs(int node, List<List<Integer>> adj, boolean[] vis) {
        Queue<Integer> q = new LinkedList<>();

        q.add(node);
        vis[node] = true;

        while (!q.isEmpty()) {
            int frontNode = q.poll();
            System.out.print(frontNode + " ");

            for (int it : adj.get(frontNode)) {
                if (!vis[it]) {
                    q.add(it);
                    vis[it] = true;
                }
            }
        }
    }

    public static void main(String[] args) {

        List<int[]> edges = new ArrayList<>();
        edges.add(new int[]{1, 2});
        edges.add(new int[]{1, 3});
        edges.add(new int[]{2, 4});
        edges.add(new int[]{3, 5});
        edges.add(new int[]{6, 7});

        int n = 7;

        // adjacency list (1-based indexing)
        List<List<Integer>> adj = new ArrayList<>();
        for (int i = 0; i <= n; i++) {
            adj.add(new ArrayList<>());
        }

        prepareAdjList(adj, edges);

        // DFS for disconnected graph
        boolean[] vis = new boolean[n + 1];
        for (int i = 1; i <= n; i++) {
            if (!vis[i]) {
                dfs(i, adj, vis);
            }
        }

        System.out.println();

        // BFS for disconnected graph
        boolean[] vis2 = new boolean[n + 1];
        for (int i = 1; i <= n; i++) {
            if (!vis2[i]) {
                bfs(i, adj, vis2);
            }
        }
    }
}