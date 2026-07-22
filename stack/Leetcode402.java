class Solution {
    public String removeKdigits(String num, int k) {
        
        // Stack<Integer> st = new Stack<>();

        StringBuilder st = new StringBuilder();

        for (char ch : num.toCharArray()) {
            
            while(st.length() > 0 && k > 0 && 
                ch - '0' < st.charAt(st.length() - 1) - '0') {
                    
                st.deleteCharAt(st.length() - 1);
                k--;
            }
            
            if(st.length() > 0 && ch == '0')
                continue;
            
            st.append(ch);
        }

        //already avoided leading zeros
        //no need to revese
        // what if k still not zero

        while(st.length() > 0 && k > 0) {
            st.deleteCharAt(st.length() - 1);
            k--;
        }

        return st.length() == 0 ? "0" : st.toString();
    }
}

public class Leetcode402 {
    public static void main(String[] args) {
        Solution sol = new Solution();
        
        String num = "1432219";
        System.out.println(sol.removeKdigits(num, 3));
    }
}