#include<bits/stdc++.h>
using namespace std;
//Leetcode 90

class Solution {
private:
    vector<vector<int>> result;
    vector<int> arr;
    int n;
    
    void findSubsetsRec(vector<int> &arr, int idx, vector<int> &subset){

        result.push_back(subset); // include current subset
        
        for (int i = idx; i < arr.size(); i++) {
            
            if (i > idx && arr[i] == arr[i - 1]) continue;  // Skip duplicates at the same recursion level
            
            subset.push_back(arr[i]);
            findSubsetsRec(arr, i + 1, subset);
            
            // backtrack
            subset.pop_back();
        }
    }

public:
    vector<vector<int>> findSubsets(vector<int> &arr){
        n = arr.size();
        this->arr = arr;

        // sort to handle duplicates
        sort(arr.begin(), arr.end());
        
        vector<int> subset;
        findSubsetsRec(arr, 0, subset);
        
        return result;
    }
};

int main() {
    Solution sol;

    vector<int> arr = {1, 2, 2};
    
    vector<vector<int>> result = sol.findSubsets(arr);

      for (int i = 0; i < result.size(); i++) {
        cout << "[";
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j];
            if (j != result[i].size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }

    return 0;
}