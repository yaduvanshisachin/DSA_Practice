#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int dp[11][2][2];
    string s;
    int digit;

    int solve(int pos, bool tight, bool started) {
        if(pos == s.length())
            return started ? 1 : 0;
        
        if(dp[pos][tight][started] != -1)
            return dp[pos][tight][started];

        int limit = tight ? s[pos] - '0' : 9;
        
        int count = 0;

        for(int d = 0; d <= limit; d++) {
            bool newTight = tight && (d == s[pos] - '0');

            if(!started && d == 0) {
                count += solve(pos + 1, newTight, started);
            }
            else if(d == digit) {
                continue;
            } else
                count += solve(pos + 1, newTight, true);
        }

        return dp[pos][tight][started] = count;
    }

public:
    int countWithout(int n, int digit) {
        this->s = to_string(n);
        this->digit = digit;

        memset(dp, -1, sizeof(dp));
        return solve(0, true, false);
    }
};

int main() {
    Solution sol;

    cout << sol.countWithout(123, 2) << '\n';

    return 0;
}

//we need to check the leading zeros
// constrained 1 <= n <= 10^9  ----> s.length() <= 10