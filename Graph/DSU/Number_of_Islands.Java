class DSU {
    private int[] parent, size;

    DSU(int n) {
        parent = new int[n + 1];
        size = new int[n + 1];
        Arrays.fill(size, 0);

        for(int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int x) {
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int u, int v) {
        int pu = find(u), pv = find(v);

        if(pu == pv) return;

        if(size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
}

class Solution {
    public int numIslands(char[][] grid) {
        int m = grid.length, n = grid[0].length;

        int[][] dirs = {{0,1}, {0,-1}, {1, 0}, {-1, 0}};

        DSU dsu = new DSU(m * n);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] == '0') continue;

                int node = i * n + j;

                for (int[] dir : dirs) {
                    int x = i + dir[0];
                    int y = j + dir[1];

                    if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == '0')
                        continue;

                    int ngbrNode = x * n + y;

                    dsu.unite(node, ngbrNode);
                }
            }
        }

        int comp = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] == '0') continue;

                int node = i * n + j;

                if (dsu.find(node) == node)
                    comp++;
            }
        }

        return comp;
        
    }
}