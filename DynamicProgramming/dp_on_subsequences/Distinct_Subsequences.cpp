#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    using ll = long long;

    // vector<vector<int>> dp;
    // int solve(int i, int j, string &s, string &t) {
    //     if(j == t.length()) return 1;
        
    //     if(i == s.length()) return 0;

    //     if(dp[i][j] != -1) return dp[i][j];

    //     int skip = solve(i+1, j, s, t);

    //     int take = 0;
    //     if(s[i] == t[j]) {
    //         take = solve(i+1, j+1, s, t);
    //     }

    //     return dp[i][j] = take + skip;
    // }

    int solveTab(string s, string t) {
        int m = s.length(), n = t.length();

        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

        for(int i = 0; i <= m; i++) dp[i][n] = 1;

        for(int i = m - 1; i >= 0; i--) {
            for(int j = n - 1; j >= 0; j--) {
                
                int skip = dp[i+1][j];

                int take = 0;
                if(s[i] == t[j])
                    take = dp[i+1][j+1];

                dp[i][j] = take + skip;
            }
        }

        return dp[0][0];
    }

    int solveOptimal(string s, string t) {
        int m = s.length(), n = t.length();

        vector<int> currRow(n + 1, 0);
        vector<int> prevRow(n + 1, 0);
        prevRow[n] = 1;

        for(int i = m - 1; i >= 0; i--) {
            currRow[n] = 1;

            for(int j = n - 1; j >= 0; j--) {
                
                int skip = prevRow[j];

                int take = 0;
                if(s[i] == t[j])
                    take = prevRow[j+1];

                currRow[j] = take + skip;
            }
            prevRow = currRow;
        }

        return prevRow[0];
    }
};


// means dp[0][0], the final answer, fits.

// It does not necessarily mean every intermediate dp[i][j] fits in int.