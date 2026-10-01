import java.util.*;

class SegmentTree {
    int n;
    int[] arr;
    int[] tree;

    private int gcd(int a, int b) {
        if(b == 0)
            return a;

        return gcd(b, a % b);
    }

    private void build(int i, int l, int r) {
        if(l == r) {
            tree[i] = arr[l];
            return;
        }

        int mid = l + (r - l)/2;

        build(2*i+1, l, mid);
        build(2*i+2, mid+1, r);

        tree[i] = gcd(tree[2*i+1], tree[2*i+2]);
    }

    private void update(int i, int l, int r, int idx, int val) {
        if(l == r) {
            tree[i] = val;
            return;
        }

        int mid = l + (r - l) / 2; 

        if(idx <= mid)
            update(2*i+1, l, mid, idx, val);
        else
            update(2*i+2, mid + 1, r, idx, val);

        tree[i] = gcd(tree[2*i+1], tree[2*i+2]);
    }

    private int query(int i, int l, int r, int ql, int qr) {
        
        if(qr < l || ql > r)
            return 0;

        if (ql <= l && r <= qr)
            return tree[i];

        int mid = l + (r - l) / 2;

        return gcd(query(2*i+1, l, mid, ql, qr), 
                    query(2*i+2, mid+1, r, ql, qr));
    }

    SegmentTree(int[] arr) {
        this.arr = arr;
        this.n = arr.length;
        this.tree = new int[4*n];
    }

    public void buildSegTree() {
        build(0, 0, n-1);
    }

    public void point_update(int idx, int val) {
        update(0, 0, n-1, idx, val);
    }

    public int querySegTree(int ql, int qr) {
        return query(0, 0, n-1, ql, qr);
    }
    
}

class Solution {
    public ArrayList<Integer> processQueries(int[] arr, int[][] queries) {
        
        SegmentTree segTree = new SegmentTree(arr);
        segTree.buildSegTree();

        ArrayList<Integer> result = new ArrayList<>();

        for(int[] q : queries) {
            if(q[0] == 0) {
                result.add(segTree.querySegTree(q[1], q[2]));
            }
            else 
                segTree.point_update(q[1], q[2]);
        }

        return result;
    }
}

public class RangeGcdQuery {
    public static void main(String[] args) {
        
    }
}