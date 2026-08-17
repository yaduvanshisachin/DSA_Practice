#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[32][2][2];

    int f(int pos, int tight, int prev, string &s) {
        if(pos == s.length()) return 1;

        if(dp[pos][tight][prev] != -1)
            return dp[pos][tight][prev];

        int limit = tight ? s[pos]-'0' : 1;
        
        int count = 0;
        for(int d = 0; d <= limit; d++) {
            
            if(prev == 1 && d == 1) continue;

            count += f(pos + 1, tight & (d == s[pos]-'0'), d, s);
        }
        
        // count += f(pos + 1, tight & 0, 0, s);  //take 0

        // if(prev != 1) {   //take 0
        //     count += f(pos + 1, tight & 1, 0, s);
        // }  

        return dp[pos][tight][prev] = count;
    }

    int findIntegers(int n) {
        string s = bitset<32>(n).to_string();

        int idx_of_leftmost_set_bit = s.find('1');

        s = s.substr(idx_of_leftmost_set_bit);
    
        memset(dp, -1, sizeof(dp));
        return f(0, 1, 0, s);
    }
};


int main() {
    Solution sol;

    int n; cin >> n;
    cout << sol.findIntegers(n) << "\n";

    return 0;
}

//don't concern about leading zeros
// start with prev = 0