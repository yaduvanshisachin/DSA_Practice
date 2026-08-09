#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()

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

    int query(int start, int end, int i, int l, int r) {
        if(l > end || r < start)
            return INT_MAX;

        if(l >= start && r <= end)
            return tree[i];

        int mid = l + (r - l) /2;

        return min(query(start, end, 2*i+1, l, mid), 
                    query(start, end, 2*i+2, mid+1, r) );
    }

public:
    SegmentTree(vector<int> &arr) {
        n = arr.size();
        tree.assign(4*n, 0);

        buidTree(0, 0, n-1, arr);
    }

    int query(int start, int end) {
        return query(start, end, 0, 0, n-1);
    }
};

class Solution {
  public:
    vector<int> rangeMinQuery(vector<int>& arr, vector<vector<int>>& queries) {
        SegmentTree t(arr);
        
        vector<int> result;
        for(auto &q : queries) {
            int start = q[0]-1;
            int end = q[1] - 1;

            result.push_back(t.query(start, end));
        }

        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}
