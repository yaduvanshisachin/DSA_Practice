#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> mp;

        for (auto &seat : reservedSeats) {
            int row = seat[0];
            int col = seat[1];

            // Only seats 2 through 9 matter.
            if (col >= 2 && col <= 9) {
                mp[row] |= (1 << col);
            }
        }

        int res = (n - mp.size()) * 2;

        for (auto &[row, mask] : mp) {
            bool left  = (mask & ((1 << 2) | (1 << 3) | (1 << 4) | (1 << 5))) == 0;
            bool middle = (mask & ((1 << 4) | (1 << 5) | (1 << 6) | (1 << 7))) == 0;
            bool right = (mask & ((1 << 6) | (1 << 7) | (1 << 8) | (1 << 9))) == 0;

            if (left && right) {
                res += 2;
            } else if (left || middle || right) {
                res += 1;
            }
        }

        return res;
    }
};


//no need to take set .... just take mask...and save space