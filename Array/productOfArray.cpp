//product except itself
// #include <iostream>
// #include <vector>
// using namespace std;
// int main(){

//     int arr[] = {5,3,6,2};
//     int n = sizeof(arr)/sizeof(int);
//     vector <int> ans;

//     for(int i=0; i<n; i++){
//         int product =1;
//         for(int j=0; j<n; j++){
//             if(j!=i){
//                 product *= arr[j];
//             }
//         }     
//         ans.push_back(product);
//     }

//     for(int i : ans){
//         cout<<i<<" ";
//     }

//     return 0;
// }


//optimization
// #include <iostream>
// #include <vector>
// using namespace std;

// int main() {
//     int arr[] = {1, 3, 6, 2};
//     int n = sizeof(arr)/sizeof(int);
    
//     int vector<int> ans(n,1);
//     int vector<int> prefix(n,1);
//     int vector<int> suffix(n,1);

//     //Prefix
//     for(int i=0; i<n;  i++){
//         prefix[i] *= arr[i-1];
//     }

//     //suffix
//     for(int i=n-2; i>0;  i--){
//         suffix[i] *= arr[i+1];
//     }

//     //ans 
//     for(int i=0; i<n; i++){
//         ans[i] = prefix[i]* suffix[i];
//     }

//     return 0;
// }



#include <iostream>
#include <vector>
using namespace std;

int main() {
    int arr[] = {1, 3, 6, 2};
    int n = sizeof(arr)/sizeof(int);
    
    int vector<int> ans(n,1);


    //prefix => ans
    for(int i=i; i<n; i++){
        ans[i] = ans[i-1] * nums[i-1];
    }

    int suffix = 1;
    for(int i=n-2; i>=0; i--){
        suffix *= nums[i+1];
        ans[i] *= suffix;
    }

    return 0;
}



