#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();

        int low = 0, high = n - 1;
        int lb = n;

        while(low <= high) {
            int mid = low + (high - low)/2;

            if(nums[mid] >= target) {
                lb = mid;
                high = mid -1;
            }else
                low = mid + 1;
        }

        if(lb == n || nums[lb] != target) //target not found
            return {-1, -1}; 

        //upper bound
        low = 0, high = n - 1;
        int ub = n;

        while(low <= high) {
            int mid = low + (high - low)/2;

            if(nums[mid] > target) {
                ub = mid;
                high = mid -1;
            }else
                low = mid + 1;
        }

        return {lb, ub - 1};
    }


    vector<int> searchRange_using_stl(vector<int>& nums, int target) {

        auto lb = lower_bound(nums.begin(), nums.end(), target);
        auto ub = upper_bound(nums.begin(), nums.end(), target);

        if(lb == nums.end() || *lb != target)
            return {-1, -1};

        return { int(lb - nums.begin()), int(ub - nums.begin()-1) };
    }
};

