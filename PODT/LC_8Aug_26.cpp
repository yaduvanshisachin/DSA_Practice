#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int m = word2.length();
        int n = word1.length();

        vector<int> last(m, -1);
        int j = m - 1;

        for(int i = n-1; i >= 0; i--) {
            if(j >= 0 && word1[i] == word2[j]) {
                last[j] = i;
                j--;
            }
        }

        vector<int> ans;
        int skip = 0; //only one skip is allowed
        j = 0;
        for(int i = 0; i < n; i++) {
            if(j == m) break;

            if(word1[i] == word2[j] || 
                    (skip == 0 && (j == m-1 || i < last[j+1]))) {
                
                if(word1[i] != word2[j]) {
                    skip = 1;
                }
                ans.push_back(i);
                j++;
            }
        }

        if(j != m) return {};

        return ans;
    }
};

//greedy solution
//TC = O(m + n)
//SC = O(m)