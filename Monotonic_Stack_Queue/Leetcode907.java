package Monotonic_Stack_Queue;

//Leetcode 907
import java.util.*;

class Solution {
    static final long MOD = (long)1e9 + 7;
    // static final long MOD = 1_000_000_007L;

    public int sumSubarrayMins(int[] arr) {
        int n = arr.length;

        int[] pse = new int[n]; 
        int[] nse = new int[n];
            
        Deque<Integer> st = new ArrayDeque<>();
            
        //Previous smaller element
        for(int i=0; i<n; i++){
            while(!st.isEmpty() && arr[i] < arr[st.peek()]) 
                st.pop();

            pse[i] = st.isEmpty() ? -1 : st.peek();
            st.push(i);
        }
        
        // while(!st.isEmpty()) st.pop();
        st.clear();

        //Next Smaller of Equal element
        for(int i=n-1; i>=0; i--){
            while(!st.isEmpty() && arr[i] <= arr[st.peek()]) 
                st.pop();

            nse[i] = st.isEmpty() ? n : st.peek();
            st.push(i);
        }
        
        long ans = 0;
        for(int i=0; i<n; i++){
            int left = i - pse[i];
            int right = nse[i] - i;

            ans = (ans + (long)arr[i] * left * right) % MOD;
        }

        return (int) ans;
    }
}

public class Leetcode907{
    public static void main(String[] args) {
        Solution sol = new Solution();

        int[] arr = {3,1,2,4};
        
        System.out.println(sol.sumSubarrayMins(arr) % Solution.MOD);
    }
}