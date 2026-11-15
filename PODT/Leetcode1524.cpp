#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int MOD = 1e9 + 7;
    int numOfSubarrays(vector<int>& arr) {
        int evenSumCnt = 1;
        int oddSumCnt = 0;

        int prefixSum = 0;
        int ans = 0;

        for(int x : arr) {
            prefixSum += x;

            if(prefixSum & 1) { //odd sum
                ans = (ans + evenSumCnt) % MOD;
                oddSumCnt++;
            } else {
                ans = (ans + oddSumCnt) % MOD;
                evenSumCnt++;
            }
        }

        return ans % MOD;
    }
};
