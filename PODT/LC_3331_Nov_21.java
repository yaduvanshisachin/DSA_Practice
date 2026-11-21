import java.util.*;

class Solution {
    int[] lastSeen = new int[26];
    int[] result;

    private void dfs(int currNode, String s, int[] parent, List<Integer>[] adj) {

        int ch = s.charAt(currNode);
        int nearestAncestor = lastSeen[ch - 'a'];

        lastSeen[ch-'a'] = currNode;

        for(int child : adj[currNode])
            dfs(child, s, parent, adj);

        lastSeen[ch-'a'] = nearestAncestor;

        if(currNode != 0) {
            int newParent = parent[currNode];

            if(nearestAncestor != -1)
                newParent = nearestAncestor;

            parent[currNode] = newParent;
            result[newParent] += result[currNode];
        }

    }

    public int[] findSubtreeSizes(int[] parent, String s) {
        int n = parent.length;
        Arrays.fill(lastSeen, -1);

        result = new int[n];
        Arrays.fill(result, 1);

        List<Integer>[] adj = new ArrayList[n];
        for(int i = 0; i < n; i++) {
            adj[i] = new ArrayList<>();
        }

        for(int node = 1; node < n; node++) {
            adj[parent[node]].add(node);
        }


        dfs(0, s, parent, adj);

        return result;
    }
}

public class LC_3331_Nov_21 {
    
}