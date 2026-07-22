#include <iostream>
#include <vector>
using namespace std;

bool isValid(vector<int> &arr, int n, int m, int maxAllowedTime){
    int painters = 1, time=0;
    for(int i=0; i<n; i++){
        if(arr[i] > maxAllowedTime){  //arr[i] => means time
            return false;
        }

        if(time + arr[i] <= maxAllowedTime){
            time += arr[i];
        }else{
            painters ++;
            time = arr[i];
        }
    }
    return painters > m ? false : true;  // more painters are needed than allowed painters(i.e. m) then false
}

int allocateBoard(vector<int> &arr, int n, int m){

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
        if(isValid(arr, n, m, mid)){  // if ans is valid go to left and look for aur small valid ans
            ans = mid;
            end = mid - 1;
        }else{  //right
            st = mid + 1;
        }
    }

    return ans;
}

int main(){
    vector<int> arr = {40,30,10,20} ; // time of 4 books respectively 
    int n = 4 , m =2;

    cout<< allocateBoard(arr, n, m) << endl;
    return 0;
}