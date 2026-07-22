// leetcode # 78. Subsets

// #include <vector>
// using namespace std;

// void printSubsets(vector<int>& arr, vector<int> ans, int i){
//     if(i == arr.size()){
//         for(int val : ans){
//             cout << val << " ";
//         }
//         cout << endl;
//         return;
//     }

//     // Include the current element
//     ans.push_back(arr[i]);
//     printSubsets(arr, ans, i + 1);

//     // Exclude the current element
//     ans.pop_back(); // Backtrack
//     printSubsets(arr, ans, i + 1);
// }

// int main() {
//     vector<int> arr = {1, 2, 3};
//     vector<int> ans;
//     printSubsets(arr, ans, 0);
//     return 0;
// }



// leetcode # 90. Subsets avoid duplicates
class Solution {
public:
    void getAllSubsets(vector<int>& nums,vector<int> ans, int i, vector<vector<int>> &allSubsets){
        if(i == nums.size()){
            allSubsets.push_back(ans);
            return;
        }

        ans.push_back(nums[i]);
        getAllSubsets(nums, ans, i+1, allSubsets);

        ans.pop_back();

        int idx = i+1;
        while(idx < nums.size() && nums[idx] == nums[idx-1]) idx++;
        getAllSubsets(nums, ans, idx, allSubsets);

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> allSubsets;
        vector<int> ans;
        getAllSubsets(nums,ans, 0, allSubsets);

        return allSubsets;
    }
};