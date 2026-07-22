// moutain element means greatest number in array

// #include <iostream>
// #include <vector>
// using namespace std;

// int main() {
//     int arr[] = {1, 3, 5, 8, 2, 6, 4};
//     int n = sizeof(arr)/sizeof(int);

//     int mtn = arr[0];
//     for(int i =1; i<n; i++){
//         int curr = arr[i];
//         mtn = max(mtn,curr );
//     }
//     cout<< mtn; 

//     return 0;
// }
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int arr[] = {1, 3, 5, 8, 2, 6, 4};
    int n = sizeof(arr)/sizeof(int);

    int st = 0 , end = n-1;
    

    while(st <= end){
        int mid = st + (end-st)/2;
        if(arr[mid] <= arr[mid-1] && arr[mid] >= arr[mid+1]){
            cout << mid;
        }

        if (arr[mid] >= arr[mid-1]){ // left slope pe
            st = mid + 1;
        }

        if (arr[mid] >= arr[mid+1]){ // left slope pe
            end = mid - 1;
        }
    }

    return 0;
}






