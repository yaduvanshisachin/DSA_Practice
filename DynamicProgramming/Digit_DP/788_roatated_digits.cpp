#include<bits/stdc++.h>
using namespace std;

// 788. Rotated Digits


class Solution {
public:
    int dp[5][2][2][2];

    int solve(int pos, int tight, int changed, int started, string &s) {
        if(pos == s.length())
            return (started && changed)? 1 : 0;

        if(dp[pos][tight][changed][started] != -1)
            return dp[pos][tight][changed][started];

        int limit = tight ? s[pos] - '0' : 9;
        int count = 0;

        for(int d = 0; d <= limit; d++) {

            int new_tight = tight & (d == s[pos] - '0');

            if(!started && d == 0) {
                count += solve(pos + 1, new_tight, false, false, s);
                continue;
            }

            //invalid rotation
            if(d == 3 || d == 4 || d == 7) {
                continue;
            } 
            
            // Number has started
            int new_started = 1;

            // 2,5,6,9 cause rotation to change
            int new_changed = changed;

            if (d == 2 || d == 5 || d == 6 || d == 9)
                new_changed = 1;

            count += solve(pos+1, new_tight, new_changed, new_started, s);
        }

        return dp[pos][tight][changed][started] = count;
    }

    int rotatedDigits(int n) {

        memset(dp, -1, sizeof(dp));
        string s = to_string(n);
        return solve(0, 1, 0, 0, s);
    }
};

int main() {
    Solution sol;
    cout << sol.rotatedDigits(10) << '\n';
}



/*
{0,1,8} → doesn't change
{2,5,6,9} → changes
{3,4,7} → invalid

at any position in X, if we found atleast one digit which changes after
rotation... we will get good number

You don't care what the rotated number actually is.

*/
