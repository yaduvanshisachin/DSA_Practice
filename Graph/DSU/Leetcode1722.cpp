#include<bits/stdc++.h>
using namespace std;

class DisjointSet {
public:
    vector<int> parent, size;

    DisjointSet(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);

        for (int i = 0; i <= n; i++) { //initially everyOne is their own parent
            parent[i] = i;
        }
	  //iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        if (x == parent[x]) return x; 
        return parent[x] = find(parent[x]); // path compression
    }

    void unite(int u, int v) {
        int pu = find(u);
        int pv = find(v);


        if (pu == pv) return;


        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};


class Solution {
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        DisjointSet dsu(n);

        for(auto &pair : allowedSwaps){
            dsu.unite(pair[0], pair[1]);
        }

        //within group each element maintains it's freq    element --> freq
        unordered_map<int, unordered_map<int, int>> groups;

        //iterate on source
        for(int i=0; i<n; i++){
            int group_id = dsu.find(i);  // ultimate parent of group
            groups[group_id][source[i]]++;
        }
        
        //iterate on target
        int dist = 0;
        for(int i=0; i<n; i++){
            auto& freq = groups[dsu.find(i)];

            if(freq.count(target[i]) && freq[target[i]] > 0)
                freq[target[i]]--;  //decreasing freq (match found)
            else
                dist++;
        }       

        return dist;
    }
};

int main(){
    Solution sol;
    vector<int> source = {5,1,2,4,3};
    vector<int> target = {1,5,4,2,3};
    vector<vector<int>> allowed_swaps = {{0,4}, {4,2},{1,3},{1,4}};

    int ans = sol.minimumHammingDistance(source, target, allowed_swaps);

    cout<< ans << endl;
}