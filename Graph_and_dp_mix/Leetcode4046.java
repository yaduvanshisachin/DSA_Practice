package Graph_and_dp_mix;

import java.util.*;

class Solution {
    public int minCost(int[][] grid, int k) {
        int m = grid.length, n = grid[0].length;

        // dp[i][j][dir][turns]
        // dir: 0 = up, 1 = down, 2 = left, 3 = right
        int INF = Integer.MAX_VALUE;

        int[][][][] dp = new int[m][n][4][k + 1];

        //Initialize
        for(int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int d = 0; d < 4; d++) {
                    Arrays.fill(dp[i][j][d], INF);
                }
            }
        }

        int[] dr = {-1, 1, 0, 0};
        int[] dc = {0, 0, -1, 1};

        // First move from (0, 0)
        for(int dir = 0; dir < 4; dir++) {
            int ni = dr[dir];
            int nj = dc[dir];

            if(ni >= 0 && ni < m && nj >= 0 && nj < n) {
                dp[ni][nj][dir][0] =
                    grid[0][0] + grid[ni][nj];
            }
        }

        //Dijkstra
        PriorityQueue<State> pq = new PriorityQueue<>(
            Comparator.comparingInt(a -> a.cost)
        );

        // Add all first-move states
        for(int dir = 0; dir < 4; dir++) {
            int ni = dr[dir];
            int nj = dc[dir];

            if(ni >= 0 && ni < m && nj >= 0 && nj < n) {
                pq.offer(new State(
                    ni, nj, dir, 0,
                    grid[0][0] + grid[ni][nj]
                ));
            }
        }

        // case: start == destination
        if(m == 1 && n == 1) return grid[0][0];

        while(!pq.isEmpty()) {
            State cur = pq.poll();

            // Ignore outdated state
            if(cur.cost != dp[cur.r][cur.c][cur.dir][cur.turns])
                continue;

            // Reached destination
            if (cur.r == m - 1 && cur.c == n - 1)
                return cur.cost;

            for (int newDir = 0; newDir < 4; newDir++) {
                int nr = cur.r + dr[newDir];
                int nc = cur.c + dc[newDir];

                if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                    continue;

                int newTurns = cur.turns;

                if (newDir != cur.dir) {
                    newTurns++;
                }

                if (newTurns > k) {
                    continue;
                }

                int newCost = cur.cost + grid[nr][nc];

                if (newCost < dp[nr][nc][newDir][newTurns]) {
                    dp[nr][nc][newDir][newTurns] = newCost;

                    pq.offer(new State(
                        nr, nc, newDir,
                        newTurns, newCost
                    ));
                }
            }
        }

        return -1;
    }

    static class State {
        int r, c, dir, turns, cost;

        State(int r, int c, int dir, int turns, int cost) {
            this.r = r;
            this.c = c;
            this.dir = dir;
            this.turns = turns;
            this.cost = cost;
        }
    }
}