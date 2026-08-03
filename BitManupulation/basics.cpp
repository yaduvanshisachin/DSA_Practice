#include <bits/stdc++.h>
using namespace std;

int main() {

    //powers of 2
    cout << (10 << 1) << endl; // 10 * 2^1
    cout << (10 << 2) << endl; // 10 * 2^2
    cout << (1 << 3) << endl; // 1 * 2^3
    cout << (1 << 4) << endl; // 1 * 2^4

    //powers of 2
    cout << (10 >> 1) << endl; // 10 * 2^-1
    cout << (10 >> 2) << endl; // 10 * 2^-2
    cout << (10 >> 3) << endl; // 10 * 2^-3
    cout << (10 >> 4) << endl; // 10 * 2^-4
    

    /* check even-odd -- if right-most or LSB is 1 ==> odd */
    // (t & 1) ? cout << "odd\n" : cout << "even\n";
    
    
    //check if a number is power of 2
    // (t & (t-1)) ? cout << "No\n" : cout << "Yes\n";
    
    //check if kth bit is set or not
    // int k = 5;
    // (t & (1 << k) != 0) ? cout << "Yes Set\n" : cout << "Not Set\n";
    
    //set kth bit
    // t = t | (1 << k)

    //clear kth bit
    // t = t & ~(1 << k);

    //flip kth bit
    // t = t ^ (1 << k);
    return 0;
}

