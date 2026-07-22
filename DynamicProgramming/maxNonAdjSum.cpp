#include <iostream>
#include <vector>
using namespace std;


int solve(vector<int> &nums, int n){
    if(n<0) return 0;
    if(n==0) return nums[0];

    int incl = nums[n] + solve(nums, n-2);
    int excl = 0 + solve(nums, n-1);

    return max(incl, excl);
}

int solveMem(vector<int> &nums, int n, vector<int> &dp){
    if(n<0) return 0;
    if(n==0) return nums[0];
    if(dp[n] != -1){
        return dp[n];
    }

    int incl = nums[n] + solveMem(nums, n-2, dp);
    int excl = 0 + solveMem(nums, n-1, dp);


    dp[n] = max(incl, excl);
    return dp[n];
}


int solveTabulation(vector<int> &nums){
    int n = nums.size();
    vector<int> dp(n, -1);

    dp[0] = nums[0];

    for(int i=1; i<n; i++){
        int incl = nums[i] + dp[i-2];
        int excl = 0 + dp[i-1];

        dp[i] = max(incl, excl);
    }
    
    return dp[n-1];
}


int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int n = arr.size();
    // int result = solve(arr, n-1);
    // cout<< result;


    // vector<int> dp(n, -1);
    // int result = solveMem(arr, n-1, dp);
    // cout<< result;

    int result = solveTabulation(arr);
    cout<< result;


    return 0;
}