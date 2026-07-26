#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    
    //if right-most or LSB is 1 ==> odd
    // (t & 1) ? cout << "odd\n" : cout << "even\n";
    
    
    //check if a number is power of 2
    // (t & (t-1)) ? cout << "No\n" : cout << "Yes\n";
    
    //check if kth bit is set or not
    int k = 5;
    (t & (t << k) != 0) ? cout << "Yes Set\n" : cout << "Not Set\n";

    return 0;
}

