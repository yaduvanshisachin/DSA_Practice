class Node {
    int[] cnt = new int[5];
    int prod = 0;
}

class SegmentTree {
    int n, k;
    Node[] tree;

    SegmentTree(int[] nums, int k) {
        this.k = k;
        this.n = nums.length;
        tree = new Node[4 * n];

        for (int i = 0; i < 4 * n; i++) {
            tree[i] = new Node();
        }

        build(0, 0, n - 1, nums);
    }

    void build(int i, int l, int r, int[] nums) {
        if (l == r) {
            leafNode(i, nums[l]);
            return;
        }

        int mid = l + (r - l) / 2;
        build(2*i+1, l, mid, nums);
        build(2*i+2, mid + 1, r, nums);
        tree[i] = mergeNodes(tree[2*i+1], tree[2*i+2]);
    }

    void leafNode(int i, int value) { //represents 1 element nums[i];
        for (int x = 0; x < k; x++) {
            tree[i].cnt[x] = 0;
        }

        int r = value % k;
        tree[i].cnt[r] = 1;
        tree[i].prod = r;
    }

    Node mergeNodes(Node left, Node right) {
        Node result = new Node();
        result.prod = (left.prod * right.prod) % k;

        for (int x = 0; x < k; x++) {
            result.cnt[x] = left.cnt[x];
        }
        for (int x = 0; x < k; x++) {
            int newRem = (left.prod * x) % k;
            result.cnt[newRem] += right.cnt[x];
        }

        return result;
    }

    void point_update(int i, int l, int r, int index, int value) {
        if (l == r) {
            leafNode(i, value);
            return;
        }

        int mid = l + (r - l) / 2;
        if (index <= mid) {
            point_update(2*i+1, l, mid, index, value);
        } else {
            point_update(2 * i + 2, mid + 1, r, index, value);
        }

        tree[i] = mergeNodes(tree[2 * i + 1], tree[2 * i + 2]);
    }

    void update(int index, int value) {
        point_update(0, 0, n - 1, index, value);
    }

    Node query(int ql, int qr, int i, int l, int r) {
        if (l >= ql && r <= qr) {
            return tree[i];
        }

        int mid = l + (r - l) / 2;
        if (qr <= mid) {
            return query(ql, qr, 2*i+1, l, mid);
        }
        if (ql > mid) {
            return query(ql, qr, 2*i+2, mid + 1, r);
        }

        Node left  = query(ql, qr, 2 * i + 1, l, mid);
        Node right = query(ql, qr, 2*i+2, mid + 1, r);

        return mergeNodes(left, right);
    }

    Node segTreeQuery(int ql, int qr) {
        //range is [ql, qr]
        //i = 0 -> index of root node of segment tree which covers the range of 0...n-1 of nums
        return query(ql, qr, 0, 0, n - 1);
    }
}

class Solution3525 {
    public int[] resultArray(int[] nums, int k, int[][] queries) {
        int n = nums.length;
        SegmentTree segTree = new SegmentTree(nums, k);
        int[] result = new int[queries.length];

        for (int idx = 0; idx < queries.length; idx++) {
            int index = queries[idx][0];
            int value = queries[idx][1];
            int start = queries[idx][2];
            int x     = queries[idx][3];

            segTree.update(index, value);

            Node node = segTree.segTreeQuery(start, n - 1);

            result[idx] = node.cnt[x];
        }

        return result;
    }
}


//T.C : O((n + q*logn) * k)   [Build = O(n*k), each Update/Query = O(k*logn)]
//S.C : O(n*k) [segment tree storage, Each node stores an array of size k]