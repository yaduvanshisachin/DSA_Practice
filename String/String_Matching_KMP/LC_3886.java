package String.String_Matching_KMP;
import java.util.*;;

class Solution3886 {
    private void buildLPS(int[] pattern, int[] lps) {
        int M = pattern.length;
        int len = 0;
        lps[0] = 0;

        int i = 1;
        while (i < M) {
            if (pattern[i] == pattern[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }

    private boolean searchKMP(int[] pattern, int[] text) {
        int N = text.length;
        int M = pattern.length;

        int[] lps = new int[M];
        buildLPS(pattern, lps);

        int i = 0; // index for text
        int j = 0; // index for pattern

        while (i < N) {
            if(pattern[j] == text[i]) {
                i++; j++;
            }
            else{
                if(j > 0) j = lps[j-1];
                else i++;
            }

            if(j == M) return true;
        }
        return false;
    }

    // if arr1 a cyclic rotation of arr2...then arr1 occurs in (arr2+arr2)
    boolean isRotation(int[] arr1, int[] arr2) {
        int n = arr2.length;

        int[] text = new int[2* n];  // text = arr2 + arr2
        for(int i = 0; i < 2*n; i++) {
            text[i] = arr2[i % n];
        }

        return searchKMP(arr1, text);
    }

    public int sortableIntegers(int[] nums) {
        int n = nums.length;

        int[] sorted = nums.clone();
        Arrays.sort(sorted);

        int result = 0;

        for (int k = 1; k <= n; k++) {
            if (n % k != 0) continue;

            boolean valid = true;
            for(int start = 0; start < n; start += k) {
                int[] arr1 = Arrays.copyOfRange(nums, start, start + k);
                int[] arr2 = Arrays.copyOfRange(sorted, start, start + k);

                if(!isRotation(arr1, arr2)) {
                    valid = false;
                    break;
                }
            }

            if(valid)
                result += k;
        }

        return result;
    }
}


//Approach (Using KMP)
//T.C: O(n log n + n · M), where M is the number of divisors of n
//S.C: O(n)
//T.C: O(n log n + n · M), where M is the number of divisors of n
//S.C: O(n),