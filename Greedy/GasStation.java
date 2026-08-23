package Greedy;

class Solution {
    public int canCompleteCircuit(int[] gas, int[] cost) {
        
        //determine if solution exists or not
        int total = 0;
        for(int i = 0; i < gas.length; i++) {
            total += gas[i] - cost[i];
        }

        if(total < 0) return -1;

        //find the start point
        int start = 0;
        int tank = 0;
        for(int i = 0; i < gas.length; i++) {
            tank += gas[i] - cost[i];

            if(tank < 0) {
                tank = 0;
                start = i + 1;
            }
        }

        return start;
    }
}

public class GasStation {
    public static void main(String[] args) {
        
        Solution sol = new Solution();

        int[] gas = {1,2,3,4,5};
        int[] cost = {3,4,5,1,2};

        System.out.println(sol.canCompleteCircuit(gas, cost));
    }
}
