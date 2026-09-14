package Graph.Shortest_Path_BFS;
import java.util.*;

class Solution1293 {
    public int shortestPath(int[][] grid, int k) {
        int m = grid.length;
        int n = grid[0].length;

        boolean[][][] vis = new boolean[m][n][k+1];

        Deque<int[]> q = new ArrayDeque<>();
        q.offer(new int[]{0, 0, k, 0});
        vis[0][0][k] = true;

        int[][] dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        while(!q.isEmpty()) {
            int[] state = q.poll();

            int i = state[0];
            int j = state[1];
            int r = state[2];
            int steps = state[3];

            if(i == m-1 && j == n-1)
                return steps;

            for(int[] dir : dirs) {
                int x = i + dir[0];
                int y = j + dir[1];

                if(x < 0 || x >= m || y < 0 || y >= n)
                    continue;

                int newR = r- grid[x][y];
                if(newR < 0) continue;

                if(vis[x][y][newR]) continue;

                vis[x][y][newR] = true;
                
                q.offer(new int[]{x, y, newR, steps+1});
            }
            
        }
        return -1;
    }
}

public class Leetcode1293 {
    public static void main(String[] args) {
        Solution1293 sol = new Solution1293();

        int[][] grid = {{0,0,0},{1,1,0},{0,0,0},{0,1,1},{0,0,0}};
        int k = 1;

        System.out.println(sol.shortestPath(grid, k));
    } 
}