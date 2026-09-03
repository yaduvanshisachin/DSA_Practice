#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxDiffSum(vector<int>& arr) {
        int n = arr.size();
        
        vector<vector<int>> dp(n, vector<int>(2, 0));
        dp[0][0] = 0;
        dp[0][1] = 0;
        
        for(int i = 1; i < n; i++) {
            // Keep arr[i]
            dp[i][0] = max(
                dp[i - 1][0] + abs(arr[i] - arr[i - 1]),
                dp[i - 1][1] + abs(arr[i] - 1)
            );
            
            // Replace arr[i] with 1
            dp[i][1] = max(
                dp[i - 1][0] + abs(1 - arr[i - 1]),
                dp[i - 1][1] + abs(1 - 1)
            );

        }
        
        return max(dp[n-1][0], dp[n-1][1]);
    }
};

//dp[i][keep] = sum up to index i for keep
//dp[i][replace] --> sum up to index i when A[i] is replaced