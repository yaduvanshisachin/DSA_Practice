// Container with most water

#include <iostream>
using namespace std;
int main(){

    int height[] = {1,8,6,2,5,4,8,3,7};
    int n = sizeof(height)/sizeof(int);

    // Brute Force Approach
    // int maxWater = INT_MIN;
    // for(int lb=0; lb<n; lb++){
    //     for(int rb=lb+1; rb<n; rb++){
    //         int width = rb-lb;
    //         int ht = min(height[lb], height[rb]);
    //         int currWater = width*ht;  // this amt. of water can be stored
    //         maxWater = max(maxWater, currWater);
    //     }
    // } 

    int maxWater = INT_MIN;
    int lp=0, rp = n-1;
    while(lp<rp){
        int w = rp-lp;
        int ht = min( height[lp], height[rp]);
        int currWater = w*ht;

        maxWater = max( maxWater, currWater);
        height[lp] < height[rp] ? lp++ : rp--; //Ternary operator
    }
    cout<<"maximum water is = "<< maxWater;

    return 0;
}