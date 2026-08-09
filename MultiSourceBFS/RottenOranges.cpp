#include <bits/stdc++.h>
using namespace std;

//multi-source BFS

class Solution {
public:
    using p = pair<int, int>;

    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int dirs[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};

        queue<p> q;
        
        int freshOranges = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 2) 
                    q.push({i, j});
                
                if(grid[i][j] == 1) 
                    freshOranges++;
            }
        }

        int time = -1;

        while(!q.empty()) {
            int sz = q.size();

            while(sz--) {
                auto [r, c] = q.front(); q.pop();

                for(auto &dir : dirs) {
                    int x = r + dir[0];
                    int y = c + dir[1];

                    if(x < 0 || x >= m || y < 0 || y >= n ) continue;
                    if(grid[x][y] == 0 || grid[x][y] == 2) continue;
                    
                    grid[x][y] = 2; //mark neighbour oranges Rotten
                    freshOranges--;
                    q.push({x, y});
                }
            }
            
            time++;
        }

        return freshOranges == 0 ? time : -1;
    }
};
