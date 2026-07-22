#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int>& arr, int target, int st, int end) {
    int mid = (st + end) / 2;
    if(arr[mid] == target) {
        return mid; // Target found
    }
    if(arr[mid] < target){
        binarySearch(arr,target, mid + 1, end); // Search in the right half
    }
    else {
        binarySearch(arr,target, st, mid - 1); // Search in the left half
    }
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int n = arr.size();
    
    if (binarySearch(arr, n)) {
        cout << "The array is sorted." << endl;
    } else {
        cout << "The array is not sorted." << endl;
    }
    
    return 0;
}