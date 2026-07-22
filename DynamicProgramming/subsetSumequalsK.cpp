#include<iostream>
#include<vector>
using namespace std;

bool solve(vector<int>& arr, int idx, int target){
    if(target == 0) return true;
    if(idx == 0) return (target == arr[idx]);

    bool skip = solve(arr, idx -1, target);
    bool take = false;
    if(target >= arr[idx]){
        take = solve(arr, idx-1, target-arr[idx]);
    }

    return take | skip;
}

//Recursion + memoization
bool subsetSumToK(int n, int k, vector<int> &arr){
    vector<vector<bool>> dp(n, vector<bool>(k+1, -1));

    int n = arr.size();
    solve(arr, n-1, k);
}

//Bottom up approach
bool subsetSumToK(int n, int k, vector<int> &arr){
    vector<vector<bool>> dp(n, vector<bool>(k+1, -1));

    for(int i=0; i<n; i++) dp[i][0] = true;
    dp[0][arr[0]] = true;

    for(int idx = 1; idx < n; idx++){
        for(int target=1; target<n; target++){
            bool skip = dp[idx-1][target];
            bool take = false;
            if(target >= arr[idx]){
                take = dp[idx-1][target-arr[idx]];
            }

            dp[idx][target] = take | skip;
        }
    }

    return dp[n-1][k];
    
}