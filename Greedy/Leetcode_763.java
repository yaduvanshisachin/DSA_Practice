import java.util.*;

class Solution763 {
    public List<Integer> partitionLabels(String s) {
        int[] lastSeen = new int[26];

        for(int i = 0; i < s.length(); i++) {
            lastSeen[s.charAt(i) - 'a'] = i;
        }
        
        List<Integer> result = new ArrayList<>();
        int farthest = 0;
        int prev = 0;

        for(int i = 0; i < s.length(); i++) {
            farthest = Math.max(farthest, lastSeen[s.charAt(i) - 'a']);
            
            if(farthest <= i) {
                result.add(i - prev + 1);
                prev = i+1;
            }

        }

        return result;
    }
}

public class Leetcode_763 {
    public static void main(String[] args) {
        Solution763 sol = new Solution763();

        String s = "ababcbacadefegdehijhklij";
        System.out.println(sol.partitionLabels(s));
    }
}