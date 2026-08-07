#include <bits/stdc++.h>
using namespace std;

class NumArray {
public:
    int n;
    vector<int> tree; //segment tree (storing Range sum)
    vector<int> A;

    //range-sum SegmentTree
    void buildTree(int i, int l, int r) {
        if(l == r) {
            tree[i] = A[l];
            return;
        }      

        int mid = l + (r - l)/2;

        buildTree(2*i + 1, l, mid);
        buildTree(2*i + 2, mid + 1, r);

        tree[i] = tree[2*i + 1] + tree[2*i+2];
    }

    //point-update
    void point_update(int idx, int val, int i, int l, int r) {  
        if(l == r) {
            tree[i] = val;
            return;
        }

        int mid = l + (r - l) / 2;

        if(idx <= mid) // move
            point_update(idx, val, 2*i+1, l, mid);
        else
            point_update(idx, val, 2*i+2, mid+1, r);
        
        //segTree nodes are also getting updated
        tree[i] = tree[2*i+1] + tree[2*i+2];
    }

    int query(int start, int end, int i, int l, int r) {
        if(l > end || r < start) return 0;

        if(l >= start && r <= end) {
            return tree[i];
        }

        int mid = l + (r - l)/2;
        return query(start, end, 2*i+1, l, mid) + 
                query(start, end, 2*i+2, mid+1, r);
    }

    NumArray(vector<int>& arr) {
        A = arr;
        n = arr.size();
        tree.assign(4*n, 0);
    }
    
    void update(int index, int val) {
        point_update(index, val, 0, 0, n-1);  //point update
    }
    
    int sumRange(int left, int right) {
        return query(left, right, 0, 0, n-1);
    }
};



int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);


    return 0;
}