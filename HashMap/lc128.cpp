class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;

        int longest = 1;
        unordered_set<int> s;

        for(int i=0; i<n; i++){
            s.insert(nums[i]);
        }

        for(auto it : s){
            if(s.find(it - 1) == s.end()){ //prev not exists --> means st. point
                int count = 1;
                int next = it + 1;

                while(s.find(next) != s.end()){  
                    count++;
                    next++;
                }
                longest = max(longest, count);
            }
        }
        return longest;
    }
};