#include<iostream>
#include<vector>
#include<queue>
#include<pair>
using namespace std;

//Brute Force Solution -- standard technique of heap (similar to find kth largest )
class Solution {
public:
    typedef pair<int, pair<int, int>> P;

    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<P, vector<P>> pq; //max heap
        int n = nums1.size(), m = nums2.size();

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                sum = nums1[i] + nums2[j];

                if(pq.size() < k){
                    pq.push({sum, {i, j}});
                }else if(pq.top().first > sum){
                    pq.pop();
                    pq.push({sum, {i, j}});
                }else{  // pq.top().first < sum -- means currSum bigger hai aage jaane pe aur bhi bigger milega
                    break;
                }

                // pq.push({sum, {i, j}});
                // if(pq.size() > k){
                //     pq.pop();
                // }
                
            }
        }
        vector<vector<int>> result;

        while(!pq.empty()){
            auto temp = pq.top();
            pq.pop();

            int i = temp.second.first;
            int j = temp.second.second;

            result.push_back({nums1[i], nums2[j]});
        }
        return result;
    }
};


//optimal approach 
class Solution {
public:
    typedef pair<int, pair<int, int>> P;

    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<P, vector<P>> pq; //max heap
        int n = nums1.size(), m = nums2.size();

        int sum = nums1[0] + nums2[0];
        
        set<pair<int, int>> visited;
        
        pq.push({sum, {0,0}});
        visited.insert({0,0});

        vector<vector<int>> result;

        while(k-- & !pq.empty()){
            auto temp = pq.top();
            pq.pop();

            int i = temp.second.first;
            int j = temp.second.second;

            result.push_back({nums1[i], nums2[j]});

            // (i, j)--> check bound & if visited
            if(j+1 < m && visited.find({i, j+1}) == visited.end()){
                pq.push({nums1[i] + nums2[j+1] , {i, j+1}});
                visited.insert({i, j});
            }

            if(i+1 < n && visited.find({i+1, j}) == visited.end()){
                pq.push({nums1[i] + nums2[j+1] , {i+1, j}});
                visited.insert({i, j});
            }
        }
        return result;
    }
};

// time complexity

jo while loop ko control karega
O(k * log(m * n))  ya fir O(k * log(k))