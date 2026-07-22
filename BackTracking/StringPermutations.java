package BackTracking;

import java.util.List;
import java.util.ArrayList;

public class StringPermutations {
    static List<String> result = new ArrayList<>();

    static void solve(StringBuilder perm, String s, boolean[] used){
        if(perm.length() == s.length()){
            result.add(perm.toString());
            return;
        }

        for(int i=0; i<s.length(); i++){
            if(used[s.charAt(i) - 'a']) continue;
            
            //avoid duplicate

            perm.append(s.charAt(i));
            used[s.charAt(i) - 'a'] = true;
            solve(perm, s, used);

            //backtrack
            perm.deleteCharAt(perm.length()-1);
            used[s.charAt(i) - 'a'] = false; //mark unvisited
        }
    }

    public static void main(String[] args) {
        
        String str = "sachin";
        
        boolean[] used = new boolean[26];
        StringBuilder perm = new StringBuilder("");
        solve(perm, str, used);

        for(var s : result){
            System.out.print(s + " ");
        }
        // System.out.println(result.size());
    }
}
