//GFG - Sum of Query-2

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void buildTree(int i, int l, int r, vector<int> &tree, int arr[]) {
        if(l == r) {//leaf nodes
            tree[i] = arr[l];
            return;
        }
        
        int mid = l + (r - l)/2;
        
        buildTree(2*i+1, l, mid, tree, arr);
        buildTree(2*i+2, mid + 1, r, tree, arr);

        tree[i] = tree[2*i + 1] + tree[2*i + 2];
    }

    int query(int start, int end, int i, int l, int r, vector<int> &tree) {
        if(l > end || r < start)
            return 0;
        
        if(l >= start && r <= end)
            return tree[i];
        
        int mid = l + (r - l)/2;

        return query(start, end, 2*i+1, l, mid, tree) +
                query(start, end, 2*i+2, mid+1, r, tree);
    }

public:
    vector<int> querySum(int n, int arr[], int q, int queries[]) {
        vector<int> tree(4 * n, 0);
        buildTree(0, 0, n-1, tree, arr);
        
        vector<int> ans;
        for(int i = 0; i < 2*q; i += 2) {
            int start = queries[i] - 1;
            int end = queries[i + 1] - 1;

            ans.push_back(query(start, end, 0, 0, n-1, tree));
        }
        
        return ans;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];
    
    int q; cin >> q;
    int queries[q];
    for(int i = 0; i < q; i++) cin >> queries[i];

    Solution sol;
    
    for(int x : sol.querySum(n, arr, q, queries) ) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}

//Test Case 
// 5
// 26 30 48 29 8
// 2
// 4 4 2 3