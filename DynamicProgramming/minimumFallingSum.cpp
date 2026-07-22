class Solution {
public:
    int t[101][101];
    bool vis[101][101];
    int n;
    int solve(vector<vector<int>>& matrix, int row, int col){
        if(row == n-1) 
            return matrix[row][col];
        
        if(vis[row][col]){
            return t[row][col];
        }

        vis[row][col] = true;

        int sum = matrix[row][col];
        int ans = INT_MAX;

        if(col-1 >= 0){
            ans = min(ans, sum + solve(matrix, row+1, col-1));
        }
        ans = min(ans, sum + solve(matrix, row+1, col));

        if(col+1 < n){
            ans = min(ans, sum + solve(matrix, row+1, col+1));
        }

        return t[row][col] = ans;
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        n = matrix.size();

        memset(vis, false, sizeof(vis));
        int minSum = INT_MAX;

        for(int col=0; col<n; col++){
            minSum = min(minSum, solve(matrix, 0, col));
        }

        return minSum;
    }
};