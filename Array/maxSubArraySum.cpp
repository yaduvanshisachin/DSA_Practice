#include <iostream>
using namespace std;
int main(){

    int arr[] = {1,3,4,6,7,2,5};
    int size = sizeof(arr)/sizeof(int);

    // All possible subArrays
    // for(int st=0; st<size; st++){
    //     for(int end=0; end<size; end++){
    //         for(int i=st; i<end; i++){
    //             cout<<arr[i];
    //         }
    //         cout<<" ";
    //     }
    //     cout<<endl;
    // }


    // Brute Force Approach
    // int maxSum = INT_MIN;
    // for(int st=0; st<size; st++){
    //     int currSum = 0;
    //     for(int end=st; end<size; end++){
    //         currSum += arr[end];
    //         maxSum = max(maxSum, currSum);
    //     }
    // }
    // cout<<"max subArray Sum = "<< maxSum << endl;


    //Kadane's Algorithm (Dynamic Programming Algorithm)
    int currSum =0, maxSum = INT_MIN;
    for(int i=0; i<size; i++){
        currSum += arr[i];
        maxSum = max(currSum , maxSum);

        if(currSum < 0){
            currSum = 0;
        }
    }
    cout<<"max subArray Sum = "<< maxSum << endl;

    return 0;
}