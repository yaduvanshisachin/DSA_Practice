#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[100001];

    int solve(int n) {
        if(n == 0) return 0;

        if(dp[n] != -1) return dp[n];

        for(int i = 1; i*i <= n; i++) {
            int val = solve(n - i*i);

            if(val == 0)
                return dp[n] = 1;
        }

        return dp[n] = 0;
    }

    bool winnerSquareGame(int n) {

        memset(dp, -1, sizeof(dp));
        return solve(n);
    }
};

int main() {
    int n; cin >> n;

    Solution sol;
    sol.winnerSquareGame(n) ? cout << " Alice winds" : cout << "Alice lost";
}


//for example: 1 --> first-move always wins
            // 2 --> second move always wins
            //4 --> first-move always wins (if he takes 4 stones)
            // 4-->  he lose if takes 1 stone no need to check further