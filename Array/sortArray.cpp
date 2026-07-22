#include <iostream>
#include <vector>
using namespace std;


int sortNums(vector<int> &arr){

    int count1 =0, count2=0, count3=0;
    for(int i=0; i< arr.size(); i++){
        if(arr[i] == 0){
            count1++;
        }
        else if(arr[i] == 0){
            count2++;
        }else
            count3++;
    }

    int idx = 0;
    for(int i=0; i<count1; i++){
        arr[idx] = arr[i];
        idx++;
    }
    for(int i=0; i<count2; i++){
        arr[idx] = arr[i];
        idx++;
    }
    for(int i=0; i<count3; i++){
        arr[idx] = arr[i];
        idx++;
    }
}

int main(){
    vector<int> arr = {2,0,2,1,1,0,1,2,0,0} ;

    return 0;
}