#include <bits/stdc++.h>
using namespace std;

#define ll long long

class SegmentTree {
private:
    vector<int> tree;
    int n;
    
    //Range-Min segmentTree
    void buidTree(int i, int l, int r, vector<int> &arr) {
        if(l == r) {
            tree[i] = arr[l];
            return;
        }

        int mid = l + (r - l)/2;

        buidTree(2*i+1, l, mid, arr);
        buidTree(2*i+2, mid + 1, r, arr);

        tree[i] = min(tree[2*i + 1], tree[2*i + 2]);
    }

    int query(int i, int ql, int qr, int l, int r) {
        if(l > qr || r < ql)
            return INT_MAX;

        if(l >= ql && r <= qr)
            return tree[i];

        int mid = l + (r - l) /2;

        return min(query(2*i+1, ql, qr, l, mid), 
                    query(2*i+2, ql, qr, mid+1, r) );
    }

public:
    SegmentTree(vector<int> &arr) {
        n = arr.size();
        tree.assign(4*n, 0);

        buidTree(0, 0, n-1, arr);
    }

    int query(int ql, int qr) {
        return query(0, ql, qr, 0, n-1);
    }
};

class Solution {
  public:
    vector<int> rangeMinQuery(vector<int>& arr, vector<vector<int>>& queries) {
        SegmentTree t(arr);
        
        vector<int> result;
        for(auto &q : queries) {
            int ql = q[0]-1;
            int qr = q[1] - 1;
            
            result.push_back(t.query(ql, qr));
        }

        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}
