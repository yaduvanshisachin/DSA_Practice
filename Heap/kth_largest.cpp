#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,  vector<int>, greater<int>> pq; //min heap

        for(int num : nums){
            pq.push(num);

            if(pq.size() > k){
                pq.pop();
            }
        }
        return pq.top();
    }
};

int main(){
    Solution sol;
    vector<int> nums = {3,2,1,5,6,4};
    int k = 2;
    cout << sol.findKthLargest(nums, k) << endl; // Output: 5
    return 0;
}

// logic
// 1. first push k elements to queue, smallest will be on top
// 2. k+1 to n tak , push bhi karo aur pop krte jaao
