// Product of Array Except Self, leetCode 238
#include <iostream>
#include <vector>
using namespace std;
// class Solution{
//     public:
//         vector<int> productExceptSelf(vector<int>& nums){
//             int n = nums.size();
//             vector<int> ans(n,1); // initialize vector of n size, with 1 at each index

//             for(int i=0; i<n; i++){
//                 for(int j=0; j<n; j++){

//                     if(i!=j){
//                         ans[i] *= nums[j];
//                     }      
//                 }
//             }
//             return ans;
//         }
// };


// Optimize Approach
class Solution{
    public:
        vector<int> productExceptSelf(vector<int>& nums){
            int n = nums.size();
            vector<int> ans(n,1);
            vector<int> prefix(n,1);
            vector<int> suffix(n,1);

            // Prefix
            for(int i=0; i<n; i++){
                prefix[i] *= prefix[i-1]*nums[i-1];
            }

            // Suffix
            for(int i=n-2; i<n; i++){
                suffix[i] *= suffix[i+1]*nums[i+1];
            }

            for(int i=0; i<n; i++){
                ans[i] *= prefix[i] * suffix[i];
            }
        }
};


int main(){
    Solution sol;
    vector<int> nums = {1,2,3,4};
    vector<int> ans = sol.productExceptSelf(nums);

    for(int i=0; i<nums.size(); i++){
        cout<< ans[i] <<" ";
    }
    return 0;
}