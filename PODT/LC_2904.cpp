class Solution {
    public String shortestBeautifulSubstring(String s, int k) {
        int i = 0;
        int ones = 0;
        String result = "";

        for (int j = 0; j < s.length(); j++) {
            if (s.charAt(j) == '1')
                ones++;

            while (ones > k) {
                if (s.charAt(i) == '1')
                    ones--;
                i++;
            }

            // Remove unnecessary leading zeros
            while (ones == k && s.charAt(i) == '0') {
                i++;
            }
            
            if (ones == k) {
                String temp = s.substring(i, j + 1);

                if (result.isEmpty()
                        || temp.length() < result.length()
                        || (temp.length() == result.length()
                            && temp.compareTo(result) < 0)) {

                    result = temp;
                }
            }
        }

        return result;
    }
}

//sliding window approach