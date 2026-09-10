// Definition for a binary tree node.

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode() {}
    TreeNode(int val) { this.val = val; }
    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

// solve will return {sum, count}
class Solution2265 {
    private int ans = 0;

    private int[] solve(TreeNode root) {
        if(root == null)
            return new int[]{0, 0};

        int[] left = solve(root.left);

        int[] right = solve(root.right);
        
        int totalSum = left[0] + right[0] + root.val;
        int nodeCnt = left[1] + right[1] + 1;

        if(totalSum / nodeCnt == root.val)
            ans++;

        return new int[]{totalSum, nodeCnt};
    }

    public int averageOfSubtree(TreeNode root) {
        solve(root);

        return ans;
    }
}

public class Leetcode2265 {
    public static void main(String[] args) {
        
    }
}

