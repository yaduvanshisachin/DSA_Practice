#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& arr) {
        int n = arr.size();
        int idx = -1;

        bool increasing = true;
        bool decreasing = true;

        for (int i = 0; i < n; i++) {
            int next = arr[(i + 1) % n];

            if ((arr[i] + 1) % n != next)
                increasing = false;

            if ((arr[i] - 1 + n) % n != next)
                decreasing = false;

            if (arr[i] == 0)
                idx = i;
        }

        if (increasing)
            return min(idx , n - idx + 2 );

        if (decreasing)
            return min(n - idx, idx + 2);

        return -1;
    }
};