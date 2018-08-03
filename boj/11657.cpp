#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

long long INF = 8765432187654321;

struct edge {
    int u, v;
    int w;
    bool operator < (const edge &e2) const {
        return w < e2.w;
    }
};

class BellmanFord {

private:
    int start;
    int V;
    vector<vector<pair<int, int>>> adjs; // adjs[0]: dummy, pair<v, weight>
    int *path;
    long long *d;

public:
    // time complexity: O((E+V)logV).
    BellmanFord(int s, int v, vector<vector<pair<int, int>>> &a) {

        start = s;
        V = v;
        adjs = a;
        d = new long long[V+1];
    }

    bool solve() {

        vector<edge> edges;
        for(int i=0; i<V+1; i++)
            for(int j=0; j<adjs[i].size(); j++)
                edges.push_back({i, adjs[i][j].first, adjs[i][j].second});

        for(int i=0; i<V+1; i++)
            d[i] = INF;
        d[start] = 0;

        for(int i=1; i<V; i++) {
            for(auto edge: edges) {
                if(d[edge.u]+edge.w<d[edge.v])
                    d[edge.v] = d[edge.u]+edge.w;
            }
        }

        for(auto edge: edges)
            if(d[edge.u]+edge.w<d[edge.v])
                return false;

        return true;
    }

    long long min_distance(int v) {

        return d[v];
    }
};

int tc, t;

int main() {

//    FILE *fp = freopen("../data/11657.input", "r", stdin);
//    if(!fp)
//        perror("freopen error");

//    scanf("%d", &tc);
    tc = 1;
    t = 0;
    while(t++ < tc) {

        int V, E;
        scanf("%d%d", &V, &E);

        vector<vector<pair<int, int>>> adjs(V+1);
        for(int i=0; i<E; i++) {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            adjs[u].push_back(make_pair(v, w));
        }

        BellmanFord bf(1, V, adjs);
        if(bf.solve()) {
            for(int i=2; i<V+1; i++)
                printf("%lld\n", bf.min_distance(i)==INF? -1:bf.min_distance(i));
        }
        else {
            printf("-1\n");
        }

    }

    return 0;
}