class Solution {
public:
    vector<vector<int>> res;

    void solve(TreeNode* root, int sum, vector<int> &temp, int targetSum){
        if(!root) return;

        sum += root->val;
        temp.push_back(root->val);

        if(!root->left && !root->right){
            if(sum == targetSum){
                res.push_back(temp);
            }
            temp.pop_back(); //backtrack
            return;
        }
        solve(root->left, sum, temp, targetSum);
        solve(root->right, sum, temp, targetSum);

        temp.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {

        int sum = 0;
        vector<int> temp;
        solve(root, sum, temp, targetSum);

        return res;
    }
};