// package DynamicProgramming;

class Solution {
    String s1, s2, s3;
    int m, n, N;
    Boolean[][] dp;

    private boolean solve(int i, int j) {
        if(i == m && j == n) {
            return true;
        }

        if(i+j >= N) // either s1 or s2 is empty
            return false;

        if(dp[i][j] != null)
            return dp[i][j];
        
        if(i < m && s1.charAt(i) == s3.charAt(i+j)) {
            if(solve(i+1, j) == true) {
                return dp[i][j] = true;
            }
        }

        if(j < n && s2.charAt(j) == s3.charAt(i+j)) {
            if(solve(i, j+1) == true) {
                return dp[i][j] = true;
            }
        }

        return dp[i][j] = false;
    }

    public boolean isInterleave(String s1, String s2, String s3) {
        this.s1 = s1; 
        this.s2 = s2; 
        this.s3 = s3;

        m = s1.length();
        n = s2.length(); 
        N = s3.length();

        if(m+n != N) return false;

        dp = new Boolean[m+1][n+1];
        return solve(0, 0);
    }
}

public class InterleavingString {
    public static void main(String[] args) {
        Solution sol = new Solution();

        System.out.println(sol.isInterleave("", "abc", "aadbbcbcac"));
    }
}