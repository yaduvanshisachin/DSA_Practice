#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:

    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        vector<ll> prefixSum(n);
        prefixSum[0] = nums[0];
        for(int i = 1; i < n; i++) {
            prefixSum[i] = nums[i] + prefixSum[i-1];
        }

        //Range Sum
        auto rangeSum = [&](int l, int r) -> ll {
            if(l > r)
                return 0;

            return prefixSum[r] - ((l > 0) ? prefixSum[l-1] : 0);
        };

        //i to m-1 segment
        //NGR[i] = n
        vector<int> NGR(n, n);
        stack<int> st;
        for(int i = 0; i < n; i++) {
            while(!st.empty() && nums[st.top()] < nums[i]) {
                NGR[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        //operations[i] = total operns to make [i...n-1] non-decreasing
        vector<ll> operations(n+1, 0);
        for(int i = n-1; i >= 0; i--) {
            int m = NGR[i];

            ll segmentOprns = (1LL * nums[i] * (m-i)) - rangeSum(i, m-1);
            operations[i] = segmentOprns + operations[m];
        }


        //Sliding Window Maximum
        deque<int> dq;
        ll result = 0;
        int i = 0;

        for(int j = 0; j < n; j++) {

            while(!dq.empty() && nums[dq.back()] < nums[j]) { //decreasing order
                dq.pop_back();
            }

            dq.push_back(j);

            //Shrink if required
            while(i <= j) {
                int m = dq.front(); //fayda hai sliding window maximum

                //i...j
                ll opCount = (operations[i] - operations[m]) + 
                        (1LL * nums[m] * (j-m+1)) - rangeSum(m, j);

                if(opCount <= k)
                    break;
                
                i++;
                if(dq.front() < i) {
                    dq.pop_front();
                }
            }

            result += (j-i+1);
        }

        return result;
    }
};


//Approach (Sliding Window with Monotonic deque + NGR + Cumulative Sum)
//T.C : O(n)
//S.C : O(n)