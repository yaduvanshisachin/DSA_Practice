//logic is same as #2904.... extra thing is palindrome

class Solution {
    private int halfLen;
    char midChar = '$';
    String result = "";

    private boolean solve(StringBuilder curr, String target, 
                            int[] freq, int i, boolean greater) {
        if(i == halfLen) {
            StringBuilder candidate = new StringBuilder(curr);

            if(midChar != '$') {
                candidate.append(midChar);
            }

            StringBuilder rightHalf = new StringBuilder(curr).reverse();
            candidate.append(rightHalf);

            if(candidate.toString().compareTo(target) > 0) {
                result = candidate.toString();
                return true;
            }

            return false;
        } 


        for(char ch = 'a'; ch <= 'z'; ch++) {
            if(freq[ch - 'a'] == 0) continue;

            if(!greater && ch < target.charAt(i)) 
                continue;

            curr.append(ch);
            freq[ch - 'a']--;

            boolean newGreater = greater || ch > target.charAt(i);
            if(solve(curr, target, freq, i+1, newGreater))
                return true;
            
            //undo
            curr.deleteCharAt(curr.length() - 1);
            freq[ch - 'a']++;
        }  

        return false;
    }

    public String lexPalindromicPermutation(String s, String target) {
        halfLen = s.length() / 2;

        int[] freq = new int[26];
        for(char ch : s.toCharArray()) freq[ch - 'a']++;

        int oddFreqCount = 0; //char with odd frequencies
        for(int i = 0; i < 26; i++) {
            if(freq[i] % 2 == 1) { 
                oddFreqCount++;
                midChar = (char)(i + 'a');
            }

            freq[i] /= 2; //we utilize only half of the chars
        }

        if(oddFreqCount > 1)
            return "";

        StringBuilder curr = new StringBuilder();
        solve(curr, target, freq, 0, false);
        
        return result;
    }
}