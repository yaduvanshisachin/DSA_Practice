#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();

        // min subarry len till index i
        vector<int> best(n, INT_MAX);

        int bestMinLen = INT_MAX;
        int result = INT_MAX;

        int i = 0, currSum = 0;

        for(int j = 0; j < n; j++) {
            currSum += arr[j];

            while(i < j && currSum > target) {
                currSum -= arr[i++];
            }

            if(currSum == target) {
                int len = j - i + 1;

                if(i > 0 && best[i-1] != INT_MAX) {
                    result = min(result, len + best[i-1]);
                }

                bestMinLen = min(bestMinLen, len);
            }

            best[j] = bestMinLen;
        }

        return result == INT_MAX ? -1 : result;
    }
};
