// Leetcode 698
/*
    Backtraing Solution runs in O(k * n * 2^n)
    memoizing using bitmask
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> A;
    int N;
    vector<int> dp;
    int bucketTarget;

    bool solve(int target, int k, int mask) {

        if(k == 1) return true;

        //curr bucket completed
        if(target == 0)
            return solve(bucketTarget, k-1, mask);

        if(dp[mask] != -1) return dp[mask];

        for(int i = 0; i < N; i++) {
            //already used
            if((mask & (1 << i)) || target < A[i])
                continue;
            
            if(solve(target-A[i], k, mask | (1 << i)))
                return dp[mask] = true;
        }

        return dp[mask] = false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        A = nums;
        N = nums.size();
        
        int total = accumulate(A.begin(), A.end(), 0);

        if (total % k != 0) return false;
        bucketTarget = total / k;

        sort(A.rbegin(), A.rend());

        if (A[0] > bucketTarget) return false;

        dp.assign(1 << N, -1);
        return solve(bucketTarget, k, 0);
    }
};


// Time: O(n · 2^n)
// Space: O(2^n + n).