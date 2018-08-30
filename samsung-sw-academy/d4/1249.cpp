#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

bool DEBUG = false;

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
//            cout << i << " ~ " << prev[i] << "\n";
    }

    long long min_distance(int v) {

        return d[v];
    }
};

int tc, t;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {

//    FILE *fp = freopen("../data/1249.input", "r", stdin);
//    if(!fp)
//        perror("freopen error");

    scanf("%d", &tc);
    t = 0;
    while(t++ < tc) {

        int N;
        scanf("%d", &N);
        int MAP[N][N];
        int dp[N][N];
        char buf[N];
        for(int i=0; i<N; i++) {
            scanf("%s", buf);
            for(int j=0; j<N; j++)
                MAP[i][j] = buf[j]-48;
        }
/*
        vector<vector<pair<int, int>>> adjs(N*N+1);
        for(int x=0; x<N; x++) {
            for(int y=0; y<N; y++) {
                int u = x*N+y+1;
                for(int i=0; i<4; i++) {
                    if((x+dx[i]>=0&&x+dx[i]<N)&&(y+dy[i]>=0&&y+dy[i]<N)) {
                        int v = (x+dx[i])*N+(y+dy[i])+1;
                        adjs[u].push_back(make_pair(v, MAP[x+dx[i]][y+dy[i]]));
                        adjs[v].push_back(make_pair(u, MAP[x][y]));
                    }
                }
            }
        }

        Dijkstra dijkstra(1, N*N, adjs);
        printf("#%d %d\n", t, (int)dijkstra.min_distance(N*N));*/

        /**
         * another solution (light ver.)
         */
        for(int i=0; i<N; i++)
            for(int j=0; j<N; j++)
                dp[i][j] = 87654321;

        int q = 0;
        vector<pair<int, int>> vec;
        vec.push_back({0, 0});
        dp[0][0] = 0;
        while(q < vec.size()) {
            int x = vec[q].first;
            int y = vec[q].second;
            for(int i=0; i<4; i++) {
                if((x+dx[i]>=0&&x+dx[i]<N)&&(y+dy[i]>=0&&y+dy[i]<N)) {
                    if(dp[x+dx[i]][y+dy[i]] > dp[x][y]+MAP[x+dx[i]][y+dy[i]]) {
                        dp[x+dx[i]][y+dy[i]] = dp[x][y]+MAP[x+dx[i]][y+dy[i]];
                        vec.push_back({x+dx[i], y+dy[i]});
                    }
                }
            }
            q++;
        }

        printf("#%d %d\n", t, dp[N-1][N-1]);

    }

    return 0;
}
