#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 

//building tree using inorder & preoder traversal
class Solution {
public:
    unordered_map<int,int> mp;

    TreeNode* build(vector<int>& preorder, int &preIdx, int left, int right){
        if(left > right){
            return NULL;
        }

        int rootVal = preorder[preIdx++];
        TreeNode* root = new TreeNode(rootVal);

        int inIdx = mp[rootVal];

        root->left = build(preorder, preIdx, left, inIdx-1);
        root->right = build(preorder, preIdx, inIdx+1, right);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0; i< inorder.size(); i++){
            mp[inorder[i]] = i;
        }
        
        int preIdx = 0;
        return build(preorder, preIdx, 0, inorder.size()-1);
    }
};

int main(){
    Solution sol;
    vector<int> preorder = {3,9,20,15,7};
    vector<int> inorder = {9,3,15,20,7};

    TreeNode* root = sol.buildTree(preorder, inorder);
    
    return 0;
}


