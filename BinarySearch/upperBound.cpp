#include<bits/stdc++.h>
using namespace std;
//solve Leetcode 34

// lower_bound --> is the smallest index where "arr[idx] > target"

int main() {
    vector<int> arr = {1, 2, 3, 3, 5, 8, 8, 10, 10, 11};
    int target = 3; //at index=4  arr[4] = 5  (5 > target)

    int low = 0, high = arr.size() - 1;
    int ans = 10; //nth index

    while(low <= high) {
        int mid = low + (high - high) / 2;

        if(arr[mid] > target) {
            ans = mid;
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    
    // cout << ans << endl;
    
    //--- above peice of code can be replaced with C++ STL    int index = lower_bound(arr.begin(), arr.end(), target) - arr.begin();
    // cout << index << endl;

    int index = upper_bound(arr.begin(), arr.end(), target) - arr.begin();
    cout << index << endl;
    
    // int st = 3, end = 5;
    // int index = lower_bound(arr.begin() + st, arr.end() + end, target) - arr.begin();
    // cout << index << endl;

}

/*
    - if target is present repeatedly in arr, this method is used
    - Since we're not sure about it... we use this method
    - used to search target in any subarray
*/


//Leetcode 35- Search Index array