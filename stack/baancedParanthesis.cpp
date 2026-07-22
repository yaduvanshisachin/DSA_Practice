#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(int i=0; i<s.size(); i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){ //opening
                st.push(s[i]);
            }else{ //closing
                if(st.size() == 0){ //closing > open..
                    return false;
                }
                if(st.top() == '(' && s[i]==')' || st.top() == '{' && s[i]=='}' ||
                st.top() == '[' && s[i]==']'){ //match found
                    st.pop();
                }else{ //No match found
                    return false;
                }
            }
        }
        return st.size() == 0;
    }
};


int main(){
    Solution sol;
    string s = "{[()]}]";
    bool result = sol.isValid(s);
    cout << (result ? "Valid" : "Invalid") << endl;
    return 0;
}