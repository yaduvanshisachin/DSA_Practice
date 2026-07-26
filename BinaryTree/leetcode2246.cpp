#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxLen = 0;

    int dfs(int curr, int parent, vector<int> adj[], string s) {
        int longest = 0;
        int second_longest = 0;

        for(auto &child : adj[curr]) {
            if(child == parent) continue;
            
            int child_longest_length = dfs(child, curr, adj, s);

            if(s[child] == s[curr]) continue;
            
            if(child_longest_length > second_longest) 
                second_longest = child_longest_length;
            
            if(second_longest > longest)
                swap(longest, second_longest);
        }

        int anyone_best = max(longest, second_longest) + 1;
        int only_root_best = 1;
        int tempAns = 1 + longest + second_longest;

        maxLen = max(maxLen, max({anyone_best, only_root_best, tempAns}));

        return max(anyone_best, only_root_best);
    }

    int longestPath(vector<int>& parent, string s) {

        vector<int> adj[parent.size()];
        // vector<vector<int>> adj(parent.size());

        for(int i = 1; i < parent.size(); i++) {
            adj[i].push_back(parent[i]);
            adj[parent[i]].push_back(i);
        }

        dfs(0, -1, adj, s);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}