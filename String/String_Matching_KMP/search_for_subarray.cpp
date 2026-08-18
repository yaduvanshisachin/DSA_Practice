//gfg podt- 14 May

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void kmp(vector<int> &arr, vector<int> &lps) {
        int n = arr.size();

        int i = 0, j = 1;

        while(j < n) {
            if(arr[i] == arr[j]) {
                lps[j] = i + 1;
                i++; j++;
            }
            else {
                if(i == 0) {
                    lps[j] = 0;
                    j++;
                } else {
                    i = lps[i - 1];
                }
            }
        }
    }

    vector<int> search(vector<int> &a, vector<int> &b) {
        int len = b.size();

        b.push_back(INT_MAX);
        for(int x : a) b.push_back(x);

        vector<int> lps(b.size(), 0);
        kmp(b, lps);

        vector<int> result;
        for(int i = 0; i < lps.size(); i++) {
            if(lps[i] == len)
                result.push_back(i - 2* len);
        }

        return result;
    }
};


/* 
    Intution

    needle + '#' + heystack  <-- here since it's arr we insert INF

    now generate LPS array 

    now get all the indices where lps[i] = length of your needle
*/