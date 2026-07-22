class Solution {
public:
    int minFlips(int a, int b, int c) {
        int flips = 0;

        while(a != 0 || b != 0 || c != 0){
            if((c&1) == 1){  // MSB of c is 1
                if((a&1) == 0 && (b&1) == 0){
                    flips++;
                }
            }else{ //MSB of c is 0
                // if((a&1) == 1 && (b&1) == 1){
                //     flips += 2; 
                // }else flips++; // {1 0} , {0, 1} --> 1 ko 0 krdo

                if((a & 1) == 1) flips ++;

                if((b & 1) == 1) flips ++;
            }
            a >>= 1;
            b >>= 1;
            c >>= 1;
        }
        return flips;
    }
};


// 2nd methode

