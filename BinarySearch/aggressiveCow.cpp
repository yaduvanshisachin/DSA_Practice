#include <iostream>
#include <vector>
using namespace std;

bool isValid(vector<int> &arr, int n, int m, int maxAllowedDist){
    int cows = 1, dist=0;
    for(int i=0; i<n; i++){
        if(arr[i] > maxAllowedDist){
            return false;
        }

        if(dist + arr[i] <= maxAllowedDist){
            dist += arr[i];
        }else{
            cows ++;
            dist = arr[i];
        }
    }
    return cows > m ? false : true;
}

int allocateBooks(vector<int> &arr, int n, int m){

    if(m>n){   //cows are more than the stalls
        return -1;
    }

    end = max(arr) - min(arr); //max dist b/w two cows

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
    vector<int> arr = {2, 1, 3, 4} ; // dist of 4 books respectively 
    int n = 4 , m =2;

    cout<< allocateBooks(arr, n, m) << endl;
    return 0;
}



//incompleated