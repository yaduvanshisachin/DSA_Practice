#include<bits/stdc++.h>
using namespace std;

int minSquares(int n, int m) {
    int ans = 0;
    while(n > 0 && m > 0) {
        ans += n / m;
        n %= m;
        
        //swap
        int temp = n;
        n = m;
        m = temp;
    }    
    return ans;
}

int main() {
    cout << minSquares(4, 5) << '\n';

    return 0;
}