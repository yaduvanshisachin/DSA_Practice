import java.util.*;

class Solution670 {
    public int maximumSwap(int num) {
        int[] lastIdx = new int[10];
        Arrays.fill(lastIdx, -1);

        String s = Integer.toString(num);

        for(int i = 0; i < s.length(); i++) {
            lastIdx[s.charAt(i) - '0'] = i;
        }

        for(int i = 0; i < s.length(); i++) {
            int d = s.charAt(i) - '0'; //curr digit

            for(int j = 9; j >= d+1; j--) {
                if(lastIdx[j] > i) {
                    char[] chars = s.toCharArray();

                    //swapping
                    char temp = chars[i];
                    chars[i] = chars[lastIdx[j]];
                    chars[lastIdx[j]] = temp;

                    return Integer.parseInt(new String(chars));
                }
            }
        }
        
        return num;
    }
}

public class Leetcode670 {
    public static void main(String[] args) {
        Solution670 sol = new Solution670();
        System.out.println(sol.maximumSwap(2736));
    }
}