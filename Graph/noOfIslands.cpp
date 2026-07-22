#include<iostrem>
#include<vector>
#include<list>
#include<queue>
using namespce std;

class Solution {
public:
    void bfs(int row, int col, vector<vector<int>> &visited, vector<vector<char>>& grid){
        int n = grid.size();
        int m = grid[0].size();

        visited[row][col] = 1;
        queue<pair<int, int>> q;
        q.push({row, col});

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;

            q.pop();

            //traverse in the neigbours and mark them if it's a land
            for(int delrow=-1; delrow<=1; delrow++){
                for(int delcol=-1; delcol<=1; delcol++){
                    int nrow = row + delrow;
                    int ncol = col + delcol;

                    //checking bound of neigbours, and if land exitst
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m
                    && grid[nrow][ncol] == '1' && !visited[nrow][ncol]){ 
                        visited[nrow][ncol] = 1;
                        q.push({nrow, ncol});
                    }
                }
            }
        }
    }

    //find no. of islands
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> visited(n, vector<int>(m, 0));
        int count = 0;
        for(int row=0; row<n; row++){
            for(int col=0; col<m; col++){
                if(!visited[row][col] && grid[row][col] == '1'){
                    count++;
                    bfs(row, col, visited, grid);
                }
            }
        }
        return count; 
    }
};