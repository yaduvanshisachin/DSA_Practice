#include<bits/stdc++.h>
using namespace std;

//Classic Partition DP

class Solution {
public:
    vector<int> A;
    vector<int> prefixSum;
    int n;
    
    vector<vector<int>> dp;

    int f(int l, int r) {
        if(l >= r) return 0;

        if(dp[l][r] != -1) return dp[l][r];
    
        int maxScore = 0;
        for(int i = l; i < n; i++) {
            int currScore = 0; //score for curr partitioning strategy

            int leftSum = prefixSum[i + 1] - prefixSum[l];
            int rightSum = prefixSum[r + 1] - prefixSum[i + 1];

            if(leftSum < rightSum) {
                currScore += leftSum + f(l, i);
            }
            else if(leftSum > rightSum) {
                currScore += rightSum + f(i+1, r);
            }
            else { //leftSum == rightSum
                currScore += leftSum + max(f(l, i), f(i+1, r));
            }

            maxScore = max(maxScore, currScore);
        }

        return dp[l][r] = maxScore;
    }

    int stoneGameV(vector<int>& stoneValue) {
        n = stoneValue.size();
        A = stoneValue;

        prefixSum.resize(n + 1);
        prefixSum[0] = 0;
        for(int i = 0; i < n; i++) {
            prefixSum[i + 1] = prefixSum[i] + A[i];
        }

        dp.assign(n+1, vector<int>(n+1, -1));

        return f(0, n-1);
    }
};

int main() {
    Solution sol;
    
    vector<int> arr = {6,2,3,4,5,5};
    // vector<int> arr = {7,7,7,7,7,7,7};
    // vector<int> arr = {4};

    cout << sol.stoneGameV(arr) << "\n";

    return 0;
}