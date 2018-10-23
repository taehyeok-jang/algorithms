#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

long long INF = 8765432187654321;

// time complexity: O((E+V)logV).
class Dijkstra {

private:
    int start;
    int V;
    vector<vector<pair<int, int>>> adjs; // adjs[0]: dummy, pair<v, weight>
//    int *prev;
    long long *d;

public:
    Dijkstra(int s, int v, vector<vector<pair<int, int>>> &a) {

        start = s;
        V = v;
        adjs = a;
//        prev = new int[V+1];
//        memset(prev, -1, sizeof(int)*(V+1));
        d = new long long[V+1];

        initialize();
    }

    void initialize() {
        // pair sorted by pair.first. (edge weight)
        // sorted by distance 'd' from start point.
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(int i=0; i<V+1; i++) d[i] = INF;
        bool inMST[V+1];
        memset(inMST, 0, sizeof(bool)*(V+1));

        pq.push(make_pair(0, start));
        d[start] = 0;

        while(!pq.empty()) {

            int u = pq.top().second; // O(VlogE)
            pq.pop();
            inMST[u] = true;

            for(auto edge: adjs[u]) { // O(ElogE)
                // (u, v)
                int v = edge.first;
                int weight = edge.second;
                if(!inMST[v]&&d[u]+weight<d[v]) {
                    d[v] = d[u]+weight;
                    pq.push(make_pair(d[v], v));
//                    prev[v] = u;
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



#include <stdio.h>
#include <vector>
using namespace std;
int tc, t;
int N;
int board[105][105];
int score[105][105][4];
vector<pair<int, int>> worm_hole[11];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int block_dir[6][4] = {
        {-1, -1, -1, -1},
        {2, 3, 1, 0},
        {1, 3, 0, 2},
        {3, 2, 0, 1},
        {2, 0, 3, 1},
        {2, 3, 0, 1}
};
bool out_of_bounds(int x, int y) { return x<0||x>=N||y<0||y>=N; }

int play(int xx, int yy, int dd) {
    int cnt = 0;
    int x, y, d;
    x = xx+dx[dd], y = yy+dy[dd], d = dd;
    score[x][y][d] = 0;

    while(1) {
        if(board[x][y]==-1||(x==xx&&y==yy))
            break;
        if(out_of_bounds(x, y)) {
            cnt++;
            d = (d+2)%4;
        }
        else if(board[x][y]>0&&board[x][y]<=5) {
            cnt++;
            d = block_dir[board[x][y]][d];
        }
        else { // >=6 worm hole
            for(auto w: worm_hole[board[x][y]]) {
                if(x==w.first&&y==w.second) continue;
                x = w.first, y = w.second; break;
            }
        }
        x += dx[d], y += dy[d];
    }
    score[xx][yy][dd] = cnt;
    return cnt;
}

int main() {
    scanf("%d", &tc);
    t = 0;
    while(t++ < tc) {

        for(int i=0; i<11; i++)
            worm_hole[i].clear();

        scanf("%d", &N);
        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                scanf("%d", &board[i][j]);
                if(board[i][j]>=6)
                    worm_hole[board[i][j]].push_back(make_pair(i, j));
            }
        }
        int ans = 0;
        for(int i=0; i<N; i++)
            for(int j=0; j<N; j++)
                for(int d=0; d<4; d++) {
                    if(board[i][j]==0&&score[i][j][d]<0
) {
                        int ss = play(i, j, d);
                        ans = max(ans, ss);
                    }
                }
        printf("#%d %d\n", t, ans);
    }

    return 0;
}



