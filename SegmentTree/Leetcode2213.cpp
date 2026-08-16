// 2213. Longest Substring of One Repeating Character

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct Node {
        char leftChar, rightChar;
        int prefix, suffix, best, len;

        Node() {
            leftChar = rightChar = '#';
            prefix = suffix = best = len = 0;
        }

        Node(char c) {
            leftChar = rightChar = c;
            prefix = suffix = best = len = 1;
        }
    };

    vector<Node> tree;

    Node merge(const Node& L, const Node& R) {
        if (L.len == 0) return R;
        if (R.len == 0) return L;

        Node res;

        res.len = L.len + R.len;
        res.leftChar = L.leftChar;
        res.rightChar = R.rightChar;

        // Initially
        res.prefix = L.prefix;
        res.suffix = R.suffix;
        res.best = max(L.best, R.best);

        // If the middle characters are equal,
        // a repeating segment can cross the boundary.
        if (L.rightChar == R.leftChar) {
            res.best = max(res.best, L.suffix + R.prefix);

            // Entire left segment is same character
            if (L.prefix == L.len) {
                res.prefix = L.len + R.prefix;
            }

            // Entire right segment is same character
            if (R.suffix == R.len) {
                res.suffix = R.len + L.suffix;
            }
        }

        return res;
    }

    void build(int node, int l, int r, const string& s) {
        if (l == r) {
            tree[node] = Node(s[l]);
            return;
        }

        int mid = l + (r - l) / 2;

        build(2 * node, l, mid, s);
        build(2 * node + 1, mid + 1, r, s);

        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    void update(int node, int l, int r, int idx, char c) {
        if (l == r) {
            tree[node] = Node(c);
            return;
        }

        int mid = l + (r - l) / 2;

        if (idx <= mid) {
            update(2 * node, l, mid, idx, c);
        } else {
            update(2 * node + 1, mid + 1, r, idx, c);
        }

        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        int n = s.size();
        int q = queryIndices.size();

        tree.assign(4 * n, Node());

        build(1, 0, n - 1, s);

        vector<int> ans;
        ans.reserve(q);

        for (int i = 0; i < q; i++) {
            int idx = queryIndices[i];  // fixed typo
            char c = queryCharacters[i];

            update(1, 0, n - 1, idx, c);

            ans.push_back(tree[1].best); // root is node 1
        }

        return ans;
    }
};