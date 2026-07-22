#include <iostream>
#include <stack>   
#include <vector>
using namespace std;

vector<int> prevSmaller(const vector<int> &arr) {
    stack<int> s;
    vector<int> ans(arr.size(), 0);

    for(int i=0; i<arr.size(); i++){
        while(!s.empty() && arr[i] <= s.top()){
            s.pop();
        }
        if(s.empty()){
            ans[i]= -1;
        }else{
            ans[i] = s.top();
        }
        s.push(arr[i]);
    }
    return ans;
}

int main() {
    vector<int> arr = {1,2,6,4,4,7,5};

    vector<int> ans = prevSmaller(arr);
    for(int val : ans){
        cout << val << " ";
    }

    return 0;
}
