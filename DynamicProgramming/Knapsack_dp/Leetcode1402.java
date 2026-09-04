import java.util.Arrays;

class Solution {
    int[] A;
    int[][] dp;

    int solve(int idx, int timer) {
        if(idx == A.length) 
            return 0;

        if(dp[idx][timer] != -1)
            return dp[idx][timer];

        int take = (A[idx] * timer) + solve(idx+1, timer + 1);

        int skip = solve(idx + 1, timer);

        return dp[idx][timer] = Math.max(take, skip);
    }

    public int maxSatisfaction(int[] satisfaction) {
        A = satisfaction;
        Arrays.sort(A);
        
        dp = new int[A.length + 1][A.length + 2];
        for(int[] arr : dp) {
            Arrays.fill(arr, -1);
        }

        return solve(0, 1);
    }
}

public class Leetcode1402 {
    public static void main(String[] args) {
        Solution sol = new Solution();

        int[] satisfaction = {-1,-8,0,5,-9};
        System.out.println(sol.maxSatisfaction(satisfaction));
    }
}