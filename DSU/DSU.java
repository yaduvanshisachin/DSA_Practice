class DisjointSet{
    int[] parent, size;

    DisjointSet(int n){
        parent = new int[n+1];
        size = new int[n+1];

        for(int i=0; i<=n; i++){
            parent[i] = i; // initially everyone is their own parent
            size[i] = i;
        }
    }

    public int find(int x){
        if(x == parent[x]) return x;
        return parent[x] = find(parent[x]); //path compresssion
    }

    public void unite(int u, int v){
        int pu = find(u);
        int pv = find(v);

        if(pu == pv) return;

        if(size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
}

public class DSU {
    public static void main(String[] args) {
        System.out.println("Hello");
    }
}