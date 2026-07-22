#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int lis(vector<pair<int, int>> &arr){
        int n = arr.size();
        
        vector<int> dp(n); //intially har kisi ka maxScore = uska khud ka score
        int maxScore = 0;

        for(int i=0; i<n; i++){
            dp[i] = arr[i].second;

            for(int j=i-1; j>=0; j--){
                if(arr[i].second >= arr[j].second){
                    dp[i] = max(dp[i], dp[j] + arr[i].second);
                }
            }
            maxScore = max(maxScore, dp[i]);
        }

        return maxScore;
    }

    int bestTeamScore(vector<int>& scores, vector<int>& ages) {

        vector<pair<int,int>> players;

        for(int i=0; i<ages.size(); i++){
            players.push_back({ages[i], scores[i]});
        }

        sort(players.begin(), players.end(), [](auto &a, auto &b){
            if(a.first == b.first){
                return a.second < b.second;
            }
            return a.first < b.first;
        });

        return lis(players);
    }
};


int main(){
    Solution sol;
    
    // Test Case1
    // vector<int> scores = {1,3,5,10,15};
    // vector<int> ages = {1,2,3,4,5};

    // Test Case 2
    vector<int> scores = {4,5,6,5};
    vector<int> ages = {2,1,2,1};

    cout << sol.bestTeamScore(scores, ages);
}