#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        int r, rev = 0, temp = x;
        if ((x%10 == 0 && x!=0)|| x<0){
            return false;
        }
        while(x!=0){
            r = x%10;
            rev = rev*10 + r;
            x /=10;
        }
        if (rev == temp){
            return true;
        }else{
            return false;
        }
    }
};


int main(){
    Solution sol;
    cout << sol.isPalindrome(1234321);
    return 0;
}
