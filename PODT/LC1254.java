class Solution1254 {
    int m, n;
    int[][] dirs = {{0, 1}, {0,-1}, {1,0}, {-1, 0}};

    private boolean dfs(int i, int j, int[][] grid, 
        boolean[][] vis) {

        if(i < 0 || i >= m || j < 0 || j >= n)
            return false;

        if(grid[i][j] == 1 || vis[i][j])
            return true;

        vis[i][j] = true;

        boolean closed = !(i == 0 || i == m - 1 ||
                           j == 0 || j == n - 1);

        for (int[] dir : dirs) {
            int ni = i + dir[0];
            int nj = j + dir[1];

            if(!dfs(ni, nj, grid, vis))
                closed = false;
        }

        return closed;
    }

    public int closedIsland(int[][] grid) {
        m = grid.length;
        n = grid[0].length;

        boolean[][] vis = new boolean[m][n];
        int count = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1 || vis[i][j])
                    continue;

                if(dfs(i, j, grid, vis))
                    count++;
            }
        }
        return count;
    }
}

// idea is to use DFS to explore an entire island and check whether it touches the boundary. If it touches the boundary, it isn't closed.

// idea is to use DFS to explore an entire island and check whether it touches the boundary. If it touches the boundary, it isn't closed.