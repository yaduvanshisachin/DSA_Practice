#include<bits/stdc++.h>
using namespace std;

class TrieNode {
public:
    // vector<TrieNode*> child(26, nullptr);
    TrieNode* child[26];
    bool isEnd;
    string word;
};

class Solution {
public:
    TrieNode* root = new TrieNode();
    vector<string> result;

    void insert(string s) {
        TrieNode* node = root;

        for(char ch : s) {
            if(!node->child[ch - 'a']) {
                node->child[ch - 'a'] = new TrieNode();
            }

            node = node->child[ch - 'a'];
        }
        node->isEnd = true;
        node->word = s;
    }
    
    int dirs[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
    int m, n;

    void dfs(int i, int j, TrieNode* node, vector<vector<char>>& grid){
        if(i < 0 || i >= m || j < 0 || j >= n ) return;

        char ch = grid[i][j];

        if(ch == '$' || !node->child[ch - 'a'])
            return;
        
        node = node->child[ch - 'a'];
        
        if(node->isEnd) {
            result.push_back(node->word);
            node->isEnd = false;
        } 

        grid[i][j] = '$'; //visited

        for(auto &d : dirs) {
            int x = i + d[0];
            int y = j + d[1];

            dfs(x, y, node, grid);
        }

        grid[i][j] = ch;
    }

    vector<string> findWords(vector<vector<char>>& grid, vector<string>& words) {
        m = grid.size();
        n = grid[0].size();

        for (auto &word : words) {
            insert(word);
        }

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                char ch = grid[i][j];

                //check if any word is starting from this character
                if(root->child[ch - 'a']){
                    dfs(i, j, root, grid);
                }
            }
        }
        return result;
    }
};