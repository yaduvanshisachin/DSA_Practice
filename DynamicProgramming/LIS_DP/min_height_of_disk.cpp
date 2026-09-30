// https://www.geeksforgeeks.org/problems/stacking-up-discs1315/1

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int LIS(vector<int> &arr) {
        
        int ans = 0; //mx ht
        
        //dp[i] = max heigh till index i
        vector<int> dp(arr.size(), 0); 
        
        for(int i = 0; i < arr.size(); i++) {
            dp[i] = arr[i];
            
            for(int j = 0; j < i; j++) {
                
                if(arr[j] < arr[i]) {
                    dp[i] = max(dp[i], dp[j] + arr[i]);
                }
            }
            
            ans = max(ans, dp[i]);
        }
        
        return ans;
    }
  
    int maxStackHeight(vector<int> &r, vector<int> &h) {
        
        vector<pair<int, int>> disk;
        
        for(int i = 0; i < r.size(); i++) {
            disk.push_back({r[i], h[i]});
        }
        
        //sort increasing order of radius
        sort(disk.begin(), disk.end(), [](auto &a, auto &b) {
            if(a.first == b.first) //if radius same
                return a.second > b.second; //decresing order of heigh 
                
            return a.first < b.first; //increasing order of radius
        });
        
        vector<int> height;
        for(auto &x : disk) {
            height.push_back(x.second);
        }
        
        return LIS(height);
    }
};