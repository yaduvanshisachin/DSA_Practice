#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int N;
    vector<int> dp;

    int solve(int pos, int bitmask) {
        if(pos == 0) return 1;

        if(dp[bitmask] != -1) 
            return dp[bitmask];

        int ans = 0;

        for(int i = 0; i < N; i++) {
            if(!(bitmask & (1 << i)) && 
                ((i + 1) % pos == 0 || pos % (i + 1) == 0)) {
                
                ans += solve(pos - 1, bitmask | (1 << i));
            }
        }

        return dp[bitmask] = ans;
    }

    int countArrangement(int n) {
        N = n;

        // memset(dp, -1, sizeof(1 << N));
        dp.assign(1<<N, -1);
        return solve(N, 0);
    }
};

int main() {

    Solution sol;

    cout << sol.countArrangement(12) << "\n";

    return 0;
}