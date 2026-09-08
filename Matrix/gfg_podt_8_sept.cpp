class Solution {
  public:
    vector<vector<char>> grid;
    int dirs[8][2] = {{0,1}, {0,-1}, {1, 0}, {-1,0}, 
                    {1, 1},{-1, 1}, {1, -1}, {-1, -1}};
                    
    int m,n;
                    
    bool check(int i, int j, int dx, int dy, string &word) {
        
        for(int idx = 0; idx < word.length(); idx++) {
            int x = i + idx * dx;
            int y = j + idx * dy;
            
            if(x < 0 || x >= m || y < 0 || y >= n)
                return false;
                
            if(grid[x][y] != word[idx])
                return false;
            
        }
        
        return true;
    }
  
    vector<vector<int>> searchWord(vector<vector<char>> &mat, string &word) {
        m = mat.size();
        n = mat[0].size();
        grid = mat;
        

        vector<vector<int>> ans;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                
                if(mat[i][j] != word[0]) continue;
                
                for(auto &dir : dirs) {
                    if(check(i, j, dir[0], dir[1], word)) {
                        ans.push_back({i, j});
                        break;
                    }
                }
            }
        }
        
        return ans;
    }
};



//jis direction me aage badh gaye... ab ussi me aage jaao.. until you
//get true or false;

// TC = (m * n * k)

// k = max(m, n); //can be diaginaly longest array