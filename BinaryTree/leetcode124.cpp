//Asked in Google, Microsoft, Meta, Amazon, Walmart

#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int maxSum = 0;
    int postOrderDFS(TreeNode* root) {
        if(root == nullptr) return 0;

        int leftSum = postOrderDFS(root->left);
        int rightSum = postOrderDFS(root->right);

        int tempAns = root->val + leftSum + rightSum;
        
        //both subtree gives +ve answer (consider bigger one)
        int one_best = root->val + max(leftSum, rightSum);
        
        //both subtree gives -ve answer (return only root's value)
        int only_root_best = root->val;

        maxSum = max(maxSum, max({tempAns, one_best, only_root_best}));

        return max(one_best, only_root_best);

    }

    int maxPathSum(TreeNode* root) {
        postOrderDFS(root);
        return maxSum;
    }
};

TreeNode* buildTree(int i, vector<int> &arr) {
    if(i >= arr.size())
        return nullptr;
    
    TreeNode* root = new TreeNode(arr[i]);
    root->left = buildTree(2*i + 1, arr);
    root->right = buildTree(2*i + 2, arr);

    return root;
}

int main() {
    Solution sol;

    // Array represents Level Order Traversal (most common)
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    TreeNode* root = buildTree(0, arr); 

    sol.maxPathSum(root);
    return 0;
}