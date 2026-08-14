#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {

        if(t.length() > s.length()) 
            return "";

        unordered_map<char, int> mp;

        for(char &ch : t){
            mp[ch]++;
        }   

        int countRequired = t.length();
        int i = 0 , j = 0;
        int minWindowSize = INT_MAX;
        int start_i = 0;

        while(j < s.length()){
            if(mp[s[j]] > 0){
                countRequired--;
            }
            mp[s[j]]--;

            while(countRequired == 0){ // once we found valid windows start shrinking
                int currWindowSize = j-i+1;
                if(minWindowSize > currWindowSize){
                    minWindowSize = currWindowSize;
                    start_i = i;
                }

                mp[s[i]]++;
                if(mp[s[i]] > 0){
                    countRequired++;
                }

                i++;
            }
            j++;
        }
        return minWindowSize == INT_MAX ? "" : s.substr(start_i, minWindowSize);
    }
};
