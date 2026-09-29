#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  using p = pair<int, int>;

  int minStepToReachTarget(vector<int> &knightPos, vector<int> &targetPos, int n) {
    queue<p> q;
    vector<vector<int>> vis(n, vector<int>(n, 0));

    q.push({knightPos[0] - 1, knightPos[1] - 1});
    vis[knightPos[0] - 1][knightPos[1] - 1] = 1;

    int dx[8] = {2, 2, -2, -2, 1, 1, -1, -1};
    int dy[8] = {1, -1, 1, -1, 2, -2, 2, -2};

    int steps = 0;
    while(!q.empty()) {

      int sz = q.size();

      while(sz--) {
        auto [x, y] = q.front();
        q.pop();

        if(x == targetPos[0] - 1 && y == targetPos[1] - 1)
          return steps;

        for(int i = 0; i < 8; i++) {
          int nx = x + dx[i];
          int ny = y + dy[i];

          if(nx < 0 || nx >= n || ny < 0 || ny >= n)
            continue;

          if(vis[nx][ny])
            continue;

          vis[nx][ny] = 1;
          q.push({nx, ny});
        }
      }

      steps++;
    }

    return -1;
  }
};