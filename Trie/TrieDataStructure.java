package Trie;

import java.util.Arrays;

class TrieNode{
    boolean isEnd = false;  
    TrieNode[] links = new TrieNode[26];

    boolean contains(char ch){
        return links[ch - 'a'] != null;
    }
}

class Solution{
    // TrieNode root =  new TrieNode();  //ye bhi kr skte ho 
    private final TrieNode root;  // or use composition and do constructor injection

    Solution(TrieNode root){
        this.root = root;
    }

    //Insert a string in Trie Data Structure
    public void insert(String s){
        TrieNode node = root;

        for(var ch : s.toCharArray()){
            if(!node.contains(ch)){
                node.links[ch - 'a'] = new TrieNode();
            }
            node = node.links[ch-'a'];
        }
        node.isEnd = true;
    }

    //Search a word/string in trie (if present return true or false otherwise)
    public boolean search(String s){
        TrieNode node = root;

        for(char ch : s.toCharArray()){
            if(!node.contains(ch)) return false;
            node = node.links[ch -'a'];
        }
        return node.isEnd;
    }

    //search prefix
    public boolean startsWith(String prefix) {
        TrieNode node = root;

        for (char ch : prefix.toCharArray()) {
            if (!node.contains(ch)) {
                return false;
            }
            node = node.links[ch - 'a'];
        }
        return true;
    }

}

public class TrieDataStructure {
    public static void main(String[] args) {
        TrieNode node = new TrieNode();
        Solution sol = new Solution(node);

        String sentence = "hello my name is Sachin I am a big looser";
        String[] strs = sentence.split(" ");


        Arrays.stream(strs)
                .map(String::toLowerCase)
                .forEach(sol::insert);
        
        System.out.println(sol.startsWith("sachin"));
    }   
}
