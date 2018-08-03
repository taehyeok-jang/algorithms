#include <iostream>
#include <vector>
#include <queue>

using namespace std;

long long INF = 8765432187654321;

/**
 * Minimum Spainning Tree
 * For un-directed graph, find MST.
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

bool edge_compare(const pair<pair<int, int>, int> &e1, const pair<pair<int, int>, int> &e2) {
    return e1.second < e2.second;
}

struct EdgeComparator {
    bool operator() (const pair<pair<int, int>, int> &e1, const pair<pair<int, int>, int> &e2) {
        return e1.second < e2.second;
    }
};

class Prim {

private:
    int V;
    vector<vector<pair<int, int>>> adjs; // adjs[0]: dummy, pair<v, weight>
    int *tree;

public:
    // time complexity: O((E+V)logV).
    Prim(int v, vector<vector<pair<int, int>>> &a) {

        V = v;
        adjs = a;
        tree = new int[V+1];
        memset(tree, -1, sizeof(int)*(V+1));

        initialize();
    }

    void initialize() {
        // pq sorted by pair.first.
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        vector<long long> d(V+1, INF);
        bool inMST[V+1];
        memset(inMST, 0, sizeof(bool)*(V+1));

        // 1 as start point. (start point doesn't matter.)
        pq.push(make_pair(0, 1));
        d[1] = 0;

        while(!pq.empty()) {

            int u = pq.top().second;
            pq.pop();
            inMST[u] = true;

            for(auto edge: adjs[u]) {
                // (u, v)
                int v = edge.first;
                int weight = edge.second;
                if(!inMST[v] && weight<d[v]) {

                    d[v] = weight;
                    pq.push(make_pair(d[v], v));
                    tree[v] = u;
                }
            }
        }
//        for(int i=1; i<V+1; i++)
//            cout << i << "'s parent " << tree[i] << "\n";
    }

    long long total_weight() {

        long long weight = 0;
        for(int i=1; i<V+1; i++) {
            int u = tree[i]; // edge (u, i).
            if(u == -1)
                continue;
            for(auto edge: adjs[u]) {
                int v = edge.first;
                int w = edge.second;
                if(v == i) {
                    weight += w;
                    break;
                }
            }
        }
        return weight;
    }
};

struct edge {
    int u, v;
    int w;
    bool operator < (const edge &e2) const {
        return w < e2.w;
    }
};

class Kruskal {

private:
    int V;
    vector<vector<pair<int, int>>> adjs;
    vector<pair<int, int>> tree;

public:
    Kruskal(int v, vector<vector<pair<int, int>>> &a) {

        V = v;
        adjs = a;
    }

    long long solve() {

        vector<edge> edges;
        for(int i=0; i<V+1; i++)
            for(int j=0; j<adjs[i].size(); j++)
                edges.push_back({i, adjs[i][j].first, adjs[i][j].second});

        sort(edges.begin(), edges.end());

        long long weight = 0;
        UnionFind uf(V+1);
        for(auto edge: edges) {

            int u = edge.u;
            int v = edge.v;
            int w = edge.w;

            if(!uf.connected(u, v)) {
                uf.merge(u, v);
                weight += w;
                tree.push_back(make_pair(u, v));
            }
        }

        return weight;
    }
};