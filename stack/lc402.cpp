#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;

        for(int i=0; i<num.length(); i++){
            while(!st.empty() && k>0 && num[i]-'0' < st.top()-'0'){
                st.pop();
                k--;
            }
            st.push(num[i]);
        }

        while(k > 0){
            st.pop();
            k--;
        }

        string ans="";
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }

        // Remove leading zeros (currently at back)
        while(!ans.empty() && ans.back() == '0'){
            ans.pop_back();
        }

        reverse(ans.begin(), ans.end());

        return ans.empty() ? "0" : ans;
    }
};

int main(){
    Solution sol;

    cout<< sol.removeKdigits("1432219", 5);
}