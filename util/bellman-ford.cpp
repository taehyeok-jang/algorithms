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

// time complexity: O(VE).
class BellmanFord {

private:
    int start;
    int V;
    vector<vector<pair<int, int>>> adjs; // adjs[0]: dummy, pair<v, weight>
    int *path;
    long long *d;

public:
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
