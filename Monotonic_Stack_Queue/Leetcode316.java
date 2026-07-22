package Monotonic_Stack_Queue;

class Solution {
    public String smallestSubsequence(String s) {
        
        int[] lastIndex = new int[26];
        for(int i = 0; i < s.length(); i++) {
            lastIndex[s.charAt(i) - 'a'] = i;
        }

        boolean[] vis = new boolean[26];

        StringBuilder st = new StringBuilder();

        for(int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);
            int size = st.length();

            while(size > 0 && ch < s.charAt(size - 1) 
                    && i < lastIndex[ch - 'a']) {
                        
                st.deleteCharAt(size - 1);
                vis[s.charAt(size - 1) - 'a'] = false;
            }

            st.append(ch);
            vis[ch - 'a'] = true;
        }

        return st.toString();
    }
}

public class Leetcode316 {
    public static void main(String[] args) {
        
    }
}
