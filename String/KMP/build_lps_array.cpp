#include<bits/stdc++.h>
using namespace std;

//KMP builds longest prefix suffix (LPS) array 

vector<int> kmp(string s) {
    int n = s.size();

    vector<int> lps(n, 0);

    int i = 0, j = 1;
    while(j < n) {
        if(s[i] == s[j]) {
            lps[j] = i + 1;
            i++; j++;
        } 
        else {
            if(i == 0) {
                lps[j] = 0;
                j++;
            } else {
                i = lps[i-1];
            }
        }
    }

    return lps;
}
