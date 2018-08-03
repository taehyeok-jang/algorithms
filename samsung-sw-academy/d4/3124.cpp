#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

long long INF = 8765432187654321;

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

//        cout << "merge " << p << ", " << q << "\n";
//        for(int i=0; i<MAX; i++)
//            cout << parent[i] << " ";
//        cout << "\n";

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

// for un-directed graph, find MST.
class Prim {

public:

    int V;
    vector<vector<pair<int, int>>> adjs; // adjs[0]: dummy, pair<v, weight>

    int *tree;

    Prim(int v, vector<vector<pair<int, int>>> &a) {

        V = v;
        adjs = a;

        tree = new int[V+1];
        memset(tree, -1, sizeof(int)*(V+1));

        initialize();
    }

    // time complexity: O((E+V)logV).
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

class Kruskal {

private:
    int V;
    vector<vector<pair<int, int>>> adjs;
    vector<pair<int, int>> tree;

public:
    Kruskal(int v, vector<vector<pair<int, int>>> &a) {

        V = v;
        adjs = a;

//        initialize();
    }

    long long solve() {

        vector<pair<pair<int, int>, int>> edges;
        for(int i=0; i<V+1; i++)
            for(int j=0; j<adjs[i].size(); j++)
                edges.push_back(make_pair(make_pair(i, adjs[i][j].first), adjs[i][j].second));
        //      edges.push_back({{i, adjs[i][j].first}, adjs[i][j].second});

        sort(edges.begin(), edges.end(), edge_compare);

        // TODO test print.
//        for(int i=0; i<edges.size(); i++)
//            cout << edges[i].first.first << ", " << edges[i].first.second << " ... " << edges[i].second << "\n";

        UnionFind uf(V+1);

        int index = 0;
        int count = 0;
        long long weight = 0;
        while(index<edges.size() && count<V-1) {

            int u = edges[index].first.first;
            int v = edges[index].first.second;
            int w = edges[index].second;
            index++;

//            cout << u << " and " << v << " connected? \n";
            if(!uf.connected(u, v)) {
//                cout << "no.\n";
                tree.push_back(make_pair(u, v));
                uf.merge(u, v);
                weight += w;

                count++;
            }
        }

        return weight;
//        for(int i=1; i<V+1; i++)
//            cout << i << "'s parent " << tree[i] << "\n";
    }

//    long long total_weight() {
//
//        long long weight = 0;
//        for(int i=0; i<tree.size(); i++) {
//            int u = tree[i].first;
//            int v = tree[i].second;
//            for(auto edge: adjs[u]) {
//                if(edge.first == v) {
//                    weight += edge.second;
//                    break;
//                }
//            }
//        }
//        return weight;
//    }

};

int tc, t;

int main() {

    scanf("%d", &tc);
    t = 0;
    while(t++ < tc) {

        int V, E;
        scanf("%d%d", &V, &E);

        vector<vector<pair<int, int>>> adjs(V+1);
        for(int i=0; i<E; i++) {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            adjs[u].push_back(make_pair(v, w));
            adjs[v].push_back(make_pair(u, w));
        }

//        Prim prim(V, adjs);
//        printf("#%d %lld\n", t, prim.total_weight());

        Kruskal kruskal(V, adjs);
        printf("#%d %lld\n", t, kruskal.solve());
    }

    return 0;
}