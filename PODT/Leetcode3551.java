import java.util.*;

class Solution3551 {
    private int getDigitSum(int x) {
        int sum = 0;

        while (x != 0) {
            sum += x % 10;
            x /= 10;
        }
        return sum;
    }

    public int minSwaps(int[] nums) {
        int n = nums.length;

        // Store original indices along with values
        int[][] arr = new int[n][2];

        for(int i = 0; i < n; i++) {
            arr[i][0] = nums[i];
            arr[i][1] = i;
        }

        // Sort by digit sum, then by numeric value
        Arrays.sort(arr, (a, b) -> {
            int sumA = getDigitSum(a[0]);
            int sumB = getDigitSum(b[0]);

            if (sumA != sumB) {
                return Integer.compare(sumA, sumB);
            }

            return Integer.compare(a[0], b[0]);
        });

        // Map each original index to its target index
        int[] targetIdx = new int[n];

        for(int i = 0; i < n; i++) {
            targetIdx[arr[i][1]] = i;
        }

        // Count cycles in the permutation
        boolean[] visited = new boolean[n];
        int swaps = 0;

        for(int i = 0; i < n; i++) {
            if(visited[i] || targetIdx[i] == i) {
                continue;
            }

            int cycleSize = 0;
            int j = i;

            while(!visited[j]) {
                visited[j] = true;
                j = targetIdx[j];
                cycleSize++;
            }

            swaps += cycleSize - 1;
        }

        return swaps;
    }
}

class Leetcode3551 {
    public static void main(String[] args) {
        
    }
}