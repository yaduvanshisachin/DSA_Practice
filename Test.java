import java.util.*;

public class Test {
    public static void main(String[] args) {

        String[] strs = {"eat","tea","tan","ate","nat","bat"};
        
        for(List<String> it : Solution.groupAnagrams(strs)) {
            
            System.out.print("[");
            for(var itt : it) {
                System.out.print(itt + " ");
            }
            System.out.print("[ \n");
        }
    }
}

class Solution {
    public static List<List<String>> groupAnagrams(String[] strs) {
        
        Map<String, List<String>> mp = new HashMap<>();

        for(String s : strs) {
            char[] chars = new char[26];
            Arrays.sort(chars);

            String str = new String(chars);

            mp.get(str).add(s);
        }

        List<List<String>> result = new ArrayList<>();
        for(var it : mp.values()) {
            result.add(it);
        }

        return result;
    }
}

