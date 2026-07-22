#include <iostream>
#include <vector>
using namespace std;


int solve(int n){
    if(n == 0){
        return 0;
    }
    int ans = n;
    for(int i = 1; i*i <= n; i++){
        ans = min(ans, 1 + solve(n - i*i));
    }
    return ans;
}

int solveMem(int n, vector<int> &dp){
    if(n == 0){
        return 0;
    }

    if(dp[n] != -1){
        return dp[n];
    }

    int ans = n;
    for(int i = 1; i*i <= n; i++){
        ans = min(ans, 1 + solve(n - i*i));
    }
    return dp[n] = ans;
    return dp[n];
}

int solveTab(int n, vector<int> &dp){
    dp[0] = 0;

    for

    if(dp[n] != -1){
        return dp[n];
    }

    int ans = n;
    for(int i = 1; i*i <= n; i++){
        ans = min(ans, 1 + solve(n - i*i));
    }
    return dp[n] = ans;
    return dp[n];
}



int main() {

    int n = 11;

    vector<int> dp(n+1, -1);
    int result = solveMem(n, dp);
    cout<< result;

    // int result = solveTabulation(arr);
    // cout<< result;


    return 0;
}