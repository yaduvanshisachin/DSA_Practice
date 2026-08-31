class Solution {
    public String removeOccurrences(String s, String part) {
        int k = part.length();

        StringBuilder result = new StringBuilder();

        for(char ch : s.toCharArray()) {
            result.append(ch);

            int len = result.length();

            if(len >= k &&  
                result.substring(len - k, len).equals(part)) {
                
                result.delete(len - k, len);
            }
        }

        return result.toString();
    }
}

public class LC_1910 {
    public static void main(String[] args) {
        Solution sol = new Solution();

        System.out.println(sol.removeOccurrences("sachinsacin", "in"));
    }
}