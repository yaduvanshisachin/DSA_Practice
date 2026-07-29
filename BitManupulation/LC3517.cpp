#include<bits/stdc++.h>
using namespace std;
    
string smallestPalindrome(string s) {
    int n = s.size(), j = 0;
    vector<int> freq(26, 0);
    
    for (int i = 0; i < n >> 1; i++) 
        freq[(s[i] & 31) - 1]++;

    for (int i = 0; i < 26; i++) {
        while(freq[i]--) {
            s[j] = 'a' + i;   //1st half
            s[n - 1 - j++] = 'a' + i; //2nd half (right to left)
        }
    }
    return s;
}

int main() {
    cout << smallestPalindrome("daccad") << endl;
}





// 'A' & 31 == 1
// 'a' & 31 == 1

// 'B' & 31 == 2
// 'b' & 31 == 2

// ...
// 'Z' & 31 == 26
// 'z' & 31 == 26