#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void kmp(string s, vector<int>& lps) {
        int i=0, j=1;
        while(j < s.size()) {
            if(s[i] == s[j]) {
                lps[j] = i + 1;
                i++; j++;
            }
            else {
                if(i==0) {
                    lps[j] = 0;
                    j++;
                } else { 
                    i = lps[i-1];
                }
            }
        }
    }

    string shortestPalindrome(string s) {
        string rev = s;
        reverse(rev.begin(), rev.end());

        string str = s + "#" + rev;
        
        vector<int> lps(str.size(), 0);
        kmp(str, lps);

        return rev.substr(0, s.size()-lps.back()) + s;
    }
};

int main() {
    Solution sol;
    cout << sol.shortestPalindrome("aacecaaa") << "\n";
}