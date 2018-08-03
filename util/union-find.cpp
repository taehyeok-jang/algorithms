/**
 * Weighted UnionFind with Path Compression
 *
 * referenced from
 * https://algs4.cs.princeton.edu/15uf/
 */

class UnionFind {

private:

    int MAX;
    int count;
    int *parent;
    int *size;

public:

    UnionFind(int S) {
        MAX = S;
        count = S;
        parent = new int[S];
        size = new int[S];

        for(int i=0; i<S; i++)
            parent[i] = i;
        for(int i=0; i<S; i++)
            size[i] = 1;
    };

    int find(int p) {
        int root = p;
        while (root != parent[root])
            root = parent[root];
        // path compression.
        while (p != root) {
            int newp = parent[p];
            parent[p] = root;
            p = newp;
        }
        return root;
    }

    void merge(int p, int q) {
        int rootP = find(p);
        int rootQ = find(q);
        if(rootP == rootQ)
            return;

        // give weight to larger one by small one.
        if (size[rootP] < size[rootQ]) {
            parent[rootP] = rootQ;
            size[rootQ] += size[rootP];
        }
        else {
            parent[rootQ] = rootP;
            size[rootP] += size[rootQ];
        }
        count--;
    }

    bool connected(int p, int q) {
        return find(p) == find(q);
    }

};