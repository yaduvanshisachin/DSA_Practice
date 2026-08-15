#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        vector<vector<int>> indegree(m, vector<int>(n, 0));
        vector<vector<int>> dirs = {{0,1}, {0,-1}, {1, 0}, {-1,0}};

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                
                for(auto &dir : dirs){
                    int nr = i + dir[0];
                    int nc = j + dir[1];

                    if(nr >= 0 && nr < m && nc >= 0 && nc < n &&
                        grid[i][j] > grid[nr][nc]){
                        indegree[i][j]++;
                    }
                }
            }
        }

        queue<pair<int,int>> q;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(indegree[i][j] == 0){
                    q.push({i,j});
                }
            }
        }
    
        int path = 0;
        while(!q.empty()){
            int size = q.size();
            path++;

            while(size--){
                auto [r, c] = q.front();
                q.pop();

                for(auto &dir : dirs){
                    int nr = r + dir[0];
                    int nc = c + dir[1];

                    if(nr >= 0 && nr < m && nc >= 0 && nc < n &&
                        grid[r][c] < grid[nr][nc]){
                        indegree[nr][nc]--;

                        if(indegree[nr][nc] == 0){
                            q.push({nr,nc});
                        }
                    }
                }
            }
        }
        return path;
    }
};