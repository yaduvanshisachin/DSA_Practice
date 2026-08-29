/******************************************************************************

                            Online Java Compiler.
                Code, Compile, Run and Debug java program online.
Write your code in this editor and press "Run" button to execute it.

*******************************************************************************/

import java.util.*;

class Solution {
    public int[] lexicographicallySmallestArray(int[] nums, int limit) {
        int n = nums.length;

        int[] sorted = nums.clone();
        Arrays.sort(sorted);

        //value --> group
        Map<Integer, Integer> groupOf = new HashMap<>();
        
        // group -> sorted elements
        Map<Integer, Deque<Integer>> groups = new HashMap<>();
        int groupId = 0;
        
        for(int i = 0; i < n; i++) {
            if(i > 0 && sorted[i] - sorted[i-1] > limit) {
                groupId++;
            }

            groupOf.put(sorted[i], groupId);
            
            // groups.put(groupId, new ArrayDeque<>(sorted[i]));
            groups
                .computeIfAbsent(groupId, k -> new ArrayDeque<>())
                .addLast(sorted[i]);
        }

        int[] result = new int[n];

        for(int i = 0; i < n; i++) {
            int grp = groupOf.get(nums[i]);

            //get the smallest available element in that group
            result[i] = groups.get(grp).pollFirst();
        }

        return result;
    }
}

public class Leetcode2948 {
    public static void main(String[] args) {
        Solution sol = new Solution();

        int[] nums = {1,7,28,19,10};
        int limit = 3;
        
        int[] ans = sol.lexicographicallySmallestArray(nums, limit);
        
        for(int x : ans)
            System.out.print(x + " ");
    }
}