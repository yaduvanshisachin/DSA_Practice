#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    using ll = long long;
    ll MOD = 1e9 + 7;
    int n;

    vector<ll> sqrSumSegTree, sumSegTree, lazyTree;

    void lazyAddition(int i, int l, int r, int val) {
        int len = (r-l+1);

        sqrSumSegTree[i] += 2*val*sumSegTree[i] + len * val * val;
        sumSegTree[i] += (len * val);
    }

    void updateRange(int ql, int qr, int i, int l, int r, int val) {
        if(lazyTree[i] != 0) {
            lazyAddition(i, l, r, lazyTree[i]);

            if(l != r) {
                lazyTree[2*i + 1] += lazyTree[i];
                lazyTree[2*i + 2] += lazyTree[i];
            }
            lazyTree[i] = 0;
        }
        //out of range
        if(l > qr || r < ql || l > r) {
            return;
        }

        //completely within range
        if(l >= ql && r <= qr) {
            lazyAddition(i, l, r, val);

            if(l != r) {
                lazyTree[2*i+1] += val;
                lazyTree[2*i+2] += val;
            }
            return;
        }

        int mid = l + (r - l)/2;
        updateRange(ql, qr, 2*i+1, l, mid, val);
        updateRange(ql, qr, 2*i+2, mid+1, r, val);

        sumSegTree[i] = sumSegTree[2*i+1] + sumSegTree[2*i + 2];
        sqrSumSegTree[i] = sqrSumSegTree[2*i+1] + sqrSumSegTree[2*i+2];
    }

    int sumCounts(vector<int>& nums) {
        n = nums.size();

        sqrSumSegTree.assign(4*n, 0);
        sumSegTree.assign(4*n , 0);
        lazyTree.assign(4*n, 0);

        vector<int> lastSeenIdx(100001, -1);
        ll result = 0;

        for(int i = 0; i < n; i++) {
            int ql = lastSeenIdx[nums[i]] + 1;
            int qr = i;

            updateRange(ql, qr, 0, 0, n-1, 1);

            result = (result + sqrSumSegTree[0]) % MOD;
            lastSeenIdx[nums[i]] = i;
        }

        return result;
    }
};