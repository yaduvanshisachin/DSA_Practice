#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findTheLongestSubstring(string s) {
        unordered_map<int, int> mp; // {xor, idx}
        mp[0] = -1;

        int currXor = 0; //mask of 5 bits
        int longest = 0;

        for(int i = 0; i < s.length(); i++) {
            
            //same char appears even times ... unset the bit (XOR cancel out)
            if (s[i] == 'a') currXor ^= (1 << 0); //toggle the bit.. 
            if (s[i] == 'e') currXor ^= (1 << 1);
            if (s[i] == 'i') currXor ^= (1 << 2);
            if (s[i] == 'o') currXor ^= (1 << 3);
            if (s[i] == 'u') currXor ^= (1 << 4);

            if(mp.find(currXor) != mp.end()) {
                int len = i - mp[currXor];
                longest = max(longest, len);
            } else
                mp[currXor] = i;
        }
        
        return longest;
    }
};