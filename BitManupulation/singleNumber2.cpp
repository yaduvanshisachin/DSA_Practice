//#LC137- Single Number2

// Approach 1
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> m;

        for(int i=0; i<nums.size(); i++){
            if(m.find(nums[i]) == m.end()){
                m[nums[i]] = 1;
            }else{
                m[nums[i]]++;
            }
        }
    }
};

//Approach 2 -- sort the array


//Approach 3 -- (bit manupulation)