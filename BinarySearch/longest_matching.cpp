// https://www.geeksforgeeks.org/problems/find-largest-word-in-dictionary2430/1
// [Google, Walmart]


#include <bits/stdc++.h>
using namespace std;

// Returns true if 'word' is a subsequence of string 's'
bool isSubsequence(const string &word, const vector<int> pos[]) {

    int prevIndex = -1;

    for(char ch : word) {

        // All positions where character 'ch' occurs in s
        const vector<int> &indices = pos[ch - 'a'];

        // Find first occurrence of ch after prevIndex
        auto it = upper_bound(indices.begin(), indices.end(), prevIndex);

        // No valid next position found
        if(it == indices.end())
            return false;

        // Update previously matched index
        prevIndex = *it;
    }

    return true;
}

string findLongestWord(string &s, vector<string> &d) {

    // Store positions of every lowercase character in s
    vector<int> pos[26];

    for(int i = 0; i < s.size(); i++) {
        pos[s[i] - 'a'].push_back(i);
    }

    string res = "";

    for(const string &word : d) {

        // Skip smaller words directly
        if(word.size() < res.size())
            continue;

        // Check whether word is subsequence of s
        if(isSubsequence(word, pos)) {

            // Prefer longer word
            // If same length, prefer lexicographically smaller word
            if(word.size() > res.size() || 
                (word.size() == res.size() && word < res)) {
                res = word;
            }
        }
    }

    return res;
}

// Driver 
int main() {
    string s = "abpcplea";
    vector<string> d = {"ale", "apple", "monkey", "plea"};

    cout << findLongestWord(s, d) << '\n';

    return 0;
}