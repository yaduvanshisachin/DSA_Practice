//In sorted array each element occuring with it's duplicate except one element


//using XOR Operator
// int singleElement(vector<int> &arr) {
//     int result = 0;
//     for(int x : arr){
//         result ^= x;
//     }
//     return result;
// }


#include <iostream>
#include <vector>
using namespace std;


int singleElement(vector<int> &arr){
    int st = 0, end = arr.size() - 1;

    while(st <= end){
        int mid = st + (end-st)/2;

        // Edge case: only one element
        if (arr.size() == 1) return arr[0];

        if(arr[mid] !=arr[mid-1] || arr[mid] != arr[mid+1]){ 
            return arr[mid];
        }

        if(mid % 2 != 0){  //mid ka idx odd, means both half consists enven no. of elements
            if(arr[mid] == arr[mid-1]){
                end = mid -1 ; //search in left half
            }else{
                st = mid + 1;
            }

        }else{    //mid ka idx even, means both half consists enven no. of elements
            if(arr[mid] == arr[mid-1]){
               st = mid + 1;
            }else{
                end = mid -1 ;
            }
        }
    }

    return -1; 
}

int main(){
    vector<int> arr = {1,1,3,3,4,6,6,7,7,9,9} ; 

    cout<< singleElement(arr) << endl;
    return 0;
}