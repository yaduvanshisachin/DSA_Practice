#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minThrows(int n, vector<int>& lad, vector<int>& sn) {

        int N = n * n;

        unordered_map<int, int> ladders, snakes;

        for (int i = 0; i < lad.size(); i += 2)
            ladders[lad[i]] = lad[i + 1];

        for (int i = 0; i < sn.size(); i += 2)
            snakes[sn[i]] = sn[i + 1];

        vector<bool> visited(N + 1, false);

        queue<pair<int, int>> q;
        q.push({1, 0});
        visited[1] = true;

        while(!q.empty()) {

            auto [curr, steps] = q.front();
            q.pop();

            if (curr == N)
                return steps;

            for(int dice = 1; dice <= 6; dice++) {

                int next = curr + dice;

                if (next > N) continue;

                // Snake / ladder
                if (ladders.count(next))
                    next = ladders[next];
                else if (snakes.count(next))
                    next = snakes[next];

                if (!visited[next]) {
                    visited[next] = true;
                    q.push({next, steps + 1});
                }
            }
        }

        return -1;
    }
};