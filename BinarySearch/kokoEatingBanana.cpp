class Solution {
public:
    bool isEatingSpeedValid(vector<int>& piles, int speed, int h){
        long long hourSpent = 0;
        
        for(int i=0; i<piles.size(); i++){
            // hourSpent += piles[i]/speed; // piles can be consumed in 1 hr
            // if(piles[i] % speed != 0){ //not consumed in 1 hr
            //     hourSpent += 1;
            
            hourSpent += (piles[i] + speed - 1) / speed; // ceil division
            }
        }
        return hourSpent <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int st = 1; 
        int end = *max_element(piles.begin(), piles.end());
        int ans = -1;

        while(st <= end){
            int mid = st + (end - st)/2;
            if(isEatingSpeedValid(piles, mid, h)){
                ans = mid;
                end = mid - 1; // go for minimum value
            }else{
                st = mid + 1;
            }
        }
        return ans;
    }
};