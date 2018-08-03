#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

long long INF = 8765432187654321;

class Dijkstra {

private:
    int start;
    int V;
    vector<vector<pair<int, int>>> adjs; // adjs[0]: dummy, pair<v, weight>
    int *prev;
    long long *d;

public:
    // time complexity: O((E+V)logV).
    Dijkstra(int s, int v, vector<vector<pair<int, int>>> &a) {

        start = s;
        V = v;
        adjs = a;
        prev = new int[V+1];
        memset(prev, -1, sizeof(int)*(V+1));
        d = new long long[V+1];

        initialize();
    }

    void initialize() {
        // pq sorted by pair.first.
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(int i=0; i<V+1; i++)
            d[i] = INF;
        bool inMST[V+1];
        memset(inMST, 0, sizeof(bool)*(V+1));

        pq.push(make_pair(0, start));
        d[start] = 0;

        while(!pq.empty()) {

            int u = pq.top().second;
            pq.pop();
            inMST[u] = true;

            for(auto edge: adjs[u]) {
                // (u, v)
                int v = edge.first;
                int weight = edge.second;
                if(!inMST[v] && d[u]+weight<d[v]) {

                    d[v] = d[u]+weight;
                    pq.push(make_pair(d[v], v));
                    prev[v] = u;
                }
            }
        }
//        for(int i=1; i<V+1; i++)
//            cout << i << "'s parent " << tree[i] << "\n";
    }

    long long min_distance(int v) {

        return d[v];
    }
};

int tc, t;

bool DEBUG = false;

int main() {

//    FILE *fp = freopen("../data/1803.input", "r", stdin);
//    if(!fp)
//        perror("freopen error");

    scanf("%d", &tc);
    t = 0;
    while(t++ < tc) {

        int N, M, S, D;
        scanf("%d%d%d%d", &N, &M, &S, &D);

        vector<vector<pair<int, int>>> adjs(N+1);
        for(int i=0; i<M; i++) {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            adjs[u].push_back(make_pair(v, w));
            adjs[v].push_back(make_pair(u, w));
        }

        Dijkstra dijkstra(S, N, adjs);
        printf("#%d %lld\n", t, dijkstra.min_distance(D));
    }

    return 0;
}