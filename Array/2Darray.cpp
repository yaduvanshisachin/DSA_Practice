// leetcode #74 binary search on 2D matrix

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    bool searchInRow(vector<vector<int>>& matrix,int target, int row){
        int n = matrix[0].size();
        int st = 0 , end = n-1;
        while(st <= end){
            int mid = st + (end-st)/2;
            if(target == matrix[row][mid]){
                return true;
            }else if(target > matrix[row][mid]){
                st = mid + 1;
            }else{
                end = mid -1;
            }
        }
        return false;
    }


    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();

        int stRow = 0, endRow = m-1;
        while(stRow <= endRow){
            int midRow = stRow + (endRow - stRow)/2;
            if(target >= matrix[midRow][0] && target <= matrix[midRow][n-1]){
                return searchInRow(matrix, target, midRow);
            }else if (target >= matrix[midRow][n-1]){
                stRow = midRow + 1; // search in bottom half 
            }else {
                endRow = midRow - 1; // serch in top half
            }
        } 
        return false;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> matrix = {{1, 3, 5}, {7, 9, 11}, {13, 15, 17}};
    int target = 9;
    bool found = sol.searchMatrix(matrix, target);
    cout << (found ? "Found" : "Not Found") << endl;
    return 0;
}