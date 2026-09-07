package Trie;

class TrieNode {
    TrieNode[] childs = new TrieNode[10];
    boolean isEnd = false; 
}

class Solution {
    private TrieNode root = new TrieNode();

    private void insert(String s) {
        TrieNode node = root;

        for(char ch : s.toCharArray()) {
            if(node.childs[ch - '0'] == null) {
                node.childs[ch - '0'] = new TrieNode();
            }
            node = node.childs[ch - '0']; 
        }
        node.isEnd = true;
    }

    private int check(String s) {
        TrieNode node = root;

        int count = 0;
        for(char ch : s.toCharArray()) {
            if(node.childs[ch - '0'] != null) {
                node = node.childs[ch - '0'];
                count++;
            }
            else break;
        }

        return count;
    }

    public int longestCommonPrefix(int[] arr1, int[] arr2) {
        for(int x : arr2) {
            insert(Integer.toString(x));
        }
        
        int ans = 0;
        for(int y : arr1) {
            ans = Math.max(ans, check(Integer.toString(y)));
        }
        return ans;
    }
}

public class Leetcode3043 {
    public static void main(String[] args) {
        Solution sol = new Solution();

        int[] arr1 = {1, 10, 100}, arr2 = {1000};
        System.out.println(sol.longestCommonPrefix(arr1, arr2));
    }
}