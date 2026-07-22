#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:

    int sumOfMax(vector<int> &arr) {
        int n = arr.size();
        
        //for every element i need to find out ==> 
        //for how many subarrays this curr guy (arr[i]) is  hero
        //right tak jitne subaarys banega and left tak jitne subarrays banega 
        //dono ka multiplication * arr[i]  <-- ye hogya arr[i] ka contribution
        //aise hi saare arrays ka contribution 

        // vector<int> totalContributions(n, 0);
        
        stack<int> st;
        vector<int> nge(n), pge(n);
        
        //PGE
        for(int i=0; i<n; i++){
            while(!st.empty() && arr[i] >= arr[st.top()]){
                st.pop();
            }
            
            pge[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        
        //flush the stak so that same can be used for nge
        while(st.size()) st.pop();
        
        //NGE
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && arr[i] > arr[st.top()]){
                st.pop();
            }
            nge[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        
        
        int ans = 0;
        for(int i=0; i<n; i++){
            int left = i - pge[i];
            int right = nge[i] - i;
            
            ans += arr[i] * left * right;
        }
        
        return ans;
    }
};


int main(){
    Solution sol;
    vector<int> arr = {1, 3, 2};

    cout << sol.sumOfMax(arr);

    return 0;
}