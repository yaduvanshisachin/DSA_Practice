import java.util.*;

class Solution {
    private Map<Integer, Integer> sn = new HashMap<>();
    private Map<Integer, Integer> ld = new HashMap<>();
    int N;

    private int[] dp;

    public int solve(int i) {
        if(i == N*N) return 0;

        if(dp[i] != -1) return dp[i];
        
        int ans = Integer.MAX_VALUE;

        for(int j = 1; j <= 6; j++) {
            int next = i + j;

            if (next > N * N) continue;
            
            if (ld.containsKey(next)) {
                next = ld.get(next);
            } else if (sn.containsKey(next)) {
                next = sn.get(next);
            }

            ans = Math.min(ans,  1 + solve(next));
        } 
        
        return dp[i] = ans;
    }

    public int minThrows(int n, int[] ladder, int[] snake) {
        N = n;

        for(int i = 0; i < ladder.length; i = i+2) {
            ld.put(ladder[i], ladder[i + 1]);
        }

        for(int i = 0; i < snake.length; i = i+2) {
            ld.put(snake[i], snake[i+1]);
        }

        dp = new int[N*N + 1];
        Arrays.fill(dp, -1);

        return solve(1);
    }
}

public class SnakeAndLadder {
    public static void main(String[] args) {
        Solution sol = new Solution();
        int n = 6;
        int lad[] = {3, 22, 5, 8, 11, 35, 20, 32};
        int sn[] = {17, 4, 19, 7, 34, 1, 21, 9};

        System.out.println(sol.minThrows(n, lad, sn));
    }
}   



// class Solution {
//  public:
//     int minThrows(int n, vector<int>& lad, vector<int>& sn) {
        
//         unordered_map<int, int> snakes, ladders;
//         for(int i = 0; i < sn.size(); i = i + 2)
//             snakes[sn[i]] = sn[i+1];
        
//         for(int i = 0; i < lad.size(); i = i + 2)
//             ladders[lad[i]] = lad[i+1];
        
//         vector<int> dp(n*n + 1, INT_MAX);
//         dp[n*n] = 0;  //Base case
         
//         for(int i = n*n - 1; i >= 1; i--) {
            
//             for(int j = 1; j <= 6; j++) {
                
//                 int next = i + j;
//                 if(next > n*n) continue;
                
//                 if(ladders.find(next) != ladders.end() ) {
//                     next = ladders[next];
//                 }
//                 else if(snakes.find(next) != snakes.end() ) {
//                     next = snakes[next];
//                 }
                
//                 if (dp[next] != INT_MAX) {
//                     dp[i] = min(dp[i],  1 + dp[next]);
//                 }
//             }
//         }
        
//         return dp[1];
//     }
// };