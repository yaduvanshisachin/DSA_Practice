//reerse stack using recursion
#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
  public:
    void insertAtEnd(stack<int> &st, int x){
        if(st.empty()){
            st.push(x);
            return;
        }
        
        int top = st.top();
        st.pop();
        insertAtEnd(st, x);
        
        st.push(top); 
    }
    
    void reverseStack(stack<int> &st) {
        if(st.empty()) return;
        int top = st.top();
        st.pop();
        reverseStack(st);
        
        insertAtEnd(st, top);
    }
};


//driver
int main(){
    Solution sol;
    stack<int> st;
    for(int i=1; i<=6; i++){
        st.push(i);
    }
    sol.reverseStack(st);

    int n = st.size();
    vector<int> arr(n);

    for(int i=1; !st.empty(); i++){
        arr[n-i] = st.top();
        st.pop();
    }

    for(int x : arr){
        cout << x <<" ";
    }
}