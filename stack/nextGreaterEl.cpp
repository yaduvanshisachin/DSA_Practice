#include <iostream>
#include <stack>   
#include <vector>
using namespace std;

vector<int> nextGreater(const vector<int> &arr) {
    stack<int> s;
    vector<int> ans(arr.size(), 0);

    for(int i = arr.size() - 1; i >= 0; i--) {
        while(!s.empty() && s.top() <= arr[i]) {
            s.pop();
        }
        if(s.empty()) {
            ans[i] = -1;
        } else {
            ans[i] = s.top();
        }
        s.push(arr[i]);
    }
    return ans;
}

int main() {
    vector<int> arr = {3, 5, 8, 6, 0, 4};

    vector<int> ans = nextGreater(arr);
    for(int val : ans){
        cout << val << " ";
    }

    return 0;
}
