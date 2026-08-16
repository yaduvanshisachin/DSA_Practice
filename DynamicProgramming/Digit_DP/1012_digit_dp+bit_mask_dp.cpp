#include<bits/stdc++.h>
using namespace std;

// https://www.youtube.com/watch?v=G_7LSulEBew


class Solution {
public:
    int dp[11][2][2][2][1 << 10];

    int solve(int pos, int tight, bool repeated, bool leading, int mask, string &s) {
        
        if(pos == s.size()) return repeated;
            // return (!leading && repeated) ? 1 : 0;

        if(dp[pos][tight][repeated][leading][mask] != -1)
            return dp[pos][tight][repeated][leading][mask];

        int limit = tight ? s[pos]-'0' : 9;
        int ans = 0;

        for(int d = 0; d <= limit; d++) {
            int nTight = tight & (d == s[pos]-'0');

            if(leading && d == 0) {
                ans += solve(pos+1, nTight, false, true, mask, s);
            }
            else {
                bool isDigitUsed = mask & (1 << d);

                ans += solve(pos+1, nTight, (repeated || isDigitUsed), false,
                            (mask | (1 << d)), s);
            }

        }

        return dp[pos][tight][repeated][leading][mask] = ans;
    }

    int numDupDigitsAtMostN(int n) {
        string s = to_string(n);

        memset(dp, -1, sizeof(dp));
        return solve(0, 1, false, true, 0, s);
    }
};

int main() {
    Solution sol;

    cout << sol.numDupDigitsAtMostN(937632098) << "\n";
}

/*
    dekho digit dp toh lagega 
    we have to keep track of elements that have seen (HashSet)
    ab hashSet ko memoize krne ke liye ===>  BitMask dp

    Digit DP + BitMask DP

    once we have found any repeated digit --> don't need to check for 
    repetation for other digits... it will contribute +1 to answer

    if(idx == N) 
        return repeated ? 1 : 0;


    mask = [. . . . . . . . . . .] (10 positions {0...9})

    states
    dp[pos][tight][repeated][mask];

    -- do we need to check...leading zeros?
*/

