#include <iostream>
#include <vector>
using namespace std;

bool isValid(vector<int> &arr, int n, int m, int maxAllowedPages){
    int students = 1, pages=0;
    for(int i=0; i<n; i++){
        if(arr[i] > maxAllowedPages){
            return false;
        }

        if(pages + arr[i] <= maxAllowedPages){
            pages += arr[i];
        }else{
            students ++;
            pages = arr[i];
        }
    }
    return students > m ? false : true;
}

int allocateBooks(vector<int> &arr, int n, int m){

    if(m>n){
        return -1;
    }
    int sum = 0;
    for(int i =0 ; i<n; i++){
        sum += arr[i];
    }

    int st = 0, end = sum; //range of possible ans
    int ans = -1;
    while(st <= end){
        int mid = st + (end-st)/2;
        if(isValid(arr, n, m, mid)){  // if ans is valid go to left and look for smaller valid ans
            ans = mid;
            end = mid - 1;
        }else{  //right
            st = mid + 1;
        }
    }

    return ans;
}

int main(){
    vector<int> arr = {2, 1, 3, 4} ; // pages of 4 books respectively 
    int n = 4 , m =2;

    cout<< allocateBooks(arr, n, m) << endl;
    return 0;
}