class Solution {
public:
    set<vector<int>> s;

    void getAllCombinations(vector<int>& arr, int tar, int idx, vector<vector<int>>&ans, vector<int> &comb){
        if(idx == arr.size() || tar < 0){
            return;
        }
        if(tar == 0){
            if(s.find(comb) == s.end()){
                ans.push_back({comb});
                s.insert(comb);
            }
            return;
        }
        
        comb.push_back(arr[idx]); 
        getAllCombinations(arr, tar-arr[idx], idx+1, ans, comb); //include once

        getAllCombinations(arr, tar -arr[idx], idx, ans, comb); // include multiple times

        comb.pop_back();  //backtrack
        getAllCombinations(arr, tar, idx+1, ans, comb); //exclude

    }
    vector<vector<int>> combinationSum(vector<int>& arr, int tar) {
        vector<vector<int>> ans;
        vector<int> comb;
        getAllCombinations(arr, tar, 0, ans, comb);
        
        return ans;
    }
};