import java.util.*;

class Solution2267 {
    int m, n;
    int[][][] dp;

    private boolean solve(int i, int j, int count, char[][] grid) {
        if(count < 0) return false;

        if(i == m-1 && j == n-1)
            return count == 0;

        if(dp[i][j][count] != -1)
            return dp[i][j][count] == 1;
        
        boolean down = false;
        if(i + 1 < m){
            if(grid[i+1][j] == '(')
                down = solve(i+1, j, count+1, grid);
            else
                down = solve(i+1, j, count-1, grid);

            if(down) {
                dp[i][j][count] = 1;
                return true;
            }
        }

        boolean right = false;
        if(j + 1 < n) {
            if(grid[i][j+1] == '(')
                right = solve(i, j+1, count+1, grid);
            else
                right = solve(i, j+1, count-1, grid);

            if(right) {
                dp[i][j][count] = 1;
                return true;
            }
        }

        dp[i][j][count] = (right || down) ? 1 : 0;
        return right || down;
    }

    public boolean hasValidPath(char[][] grid) {
        m = grid.length;
        n = grid[0].length;

        dp = new int[m+1][n+1][m+n+1];
        for(var arr2d : dp) {
            for(int[] arr1d : arr2d) {
                Arrays.fill(arr1d, -1);
            }
        }

        int count = grid[0][0] == '(' ? 1 : -1;

        return solve(0, 0, count, grid);
    }
}