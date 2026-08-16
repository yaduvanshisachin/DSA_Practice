#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n, m;
    int dp[501][501];
    int solve(int i, int j, string &s1, string &s2){
        if(i == n){
            return m-j; //insertions in s1
        }
        if(j == m){
            return n-i; //deletions from s1
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        if(s1[i] == s2[j]){
            return dp[i][j] = 0 + solve(i+1, j+1, s1, s2);
        }else{
            int insert = 1 + solve(i, j+1, s1, s2);
            int deletion = 1 + solve(i+1, j, s1, s2);
            int replace = 1 + solve(i+1, j+1, s1, s2);

            return dp[i][j] = min({insert, deletion, replace});
        }
        return -1;      
    }

    int minDistance(string s1, string s2) {
        n = s1.length();
        m = s2.length();

        memset(dp, -1, sizeof(dp));
        return solve(0, 0,  s1, s2);
    }
};