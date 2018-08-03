#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <cmath>

using namespace std;

long long INF = 8765432187654321;

class Prim {

private:
    int V;
    vector<vector<pair<int, long long>>> adjs; // adjs[0]: dummy, pair<v, weight>
    int *tree;

public:
    // time complexity: O((E+V)logV).
    Prim(int v, vector<vector<pair<int, long long>>> &a) {

        V = v;
        adjs = a;
        tree = new int[V+1];
        memset(tree, -1, sizeof(int)*(V+1));

        initialize();
    }

    void initialize() {
        // pq sorted by pair.first.
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

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
                long long weight = edge.second;
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
                long long w = edge.second;
                if(v == i) {
                    weight += w;
                    break;
                }
            }
        }
        return weight;
    }
};

int tc, t;

bool DEBUG = false;

int main() {

//    FILE *fp = freopen("../data/1251.input", "r", stdin);
//    if(!fp)
//        perror("freopen error");

    scanf("%d", &tc);
    t = 0;

    while(t++ < tc) {

        int N;
        scanf("%d", &N);

        int x[N];
        int y[N];
        for(int i=0; i<N; i++)
            scanf("%d", &x[i]);
        for(int i=0; i<N; i++)
            scanf("%d", &y[i]);

        double E;
        scanf("%lf", &E);

        vector<vector<pair<int, long long>>> adjs(N+1);
        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                long long d = pow(x[i]-x[j], 2)+pow(y[i]-y[j], 2);
                adjs[i+1].push_back(make_pair(j+1, d));
                adjs[j+1].push_back(make_pair(i+1, d));
            }
        }

        Prim prim(N, adjs);
        printf("#%d %lld\n", t, (long long)floor(E*prim.total_weight()+0.5));
    }

    return 0;
}
