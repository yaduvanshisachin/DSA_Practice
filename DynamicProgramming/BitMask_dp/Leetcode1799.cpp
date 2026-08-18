#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n;
    vector<int> A, dp;

    int f(int op, int mask) {
        if(mask == (1 << n) - 1) return 0;

        if(dp[mask] != -1) return dp[mask];

        //find first unused element
        for(int i = 0; i < n; i++) {
            if(mask & (1 << i)) continue;

            //find second unused element
            for(int j = i+1; j < n; j++) {
                if(mask & (1 << j)) continue;

                int newMask = mask | (1 << i) | (1 << j);
                int score = (op *__gcd(A[i], A[j])) + f(op+1, newMask);

                dp[mask] = max(dp[mask], score);
            }
        }

        return dp[mask];
    }

    int maxScore(vector<int>& nums) {
        A = nums; n = nums.size();

        dp.assign(1 << n, -1);
        return f(1, 0);
    }
};

int main() {
    Solution sol;
    vector<int> a = {171651,546244,880754,412358};

    cout << sol.maxScore(a) << '\n';
    return 0;
}