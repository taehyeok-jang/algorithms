#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/**
 * state 0: none, -1: dead, 1: un-activated, 2: alive.
 */

struct cell {
    int x, y, t, state, cur;
    cell() {}
    cell(int _x, int _y, int _t, int _s, int _c) {
        x = _x; y = _y; t = _t; state = _s; cur = _c;
    }
};
// board state
struct bb {
    int t, state;
};

int tc, t;
int N, M, K;
queue<cell> q;
bb board[501][501];
int visited[501][501];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

//bool out_of_bounds(int x, int y) { return x<0||x>=501||y<0||y>=501; }
int max(int a, int b) { return a>b? a:b; }

int main() {

//    FILE *fp = freopen("../data/battle.input", "r", stdin);
//    if(!fp)
//        perror("freopen error");

    scanf("%d", &tc);
    t = 0;
    while(t++ < tc) {

        while(!q.empty()) q.pop();
        for(int i=0; i<501; i++) {
            for(int j=0; j<501; j++) {
                visited[i][j] = 0;
                board[i][j].t = -1, board[i][j].state = 0;
            }
        }

        int tt;
        scanf("%d%d%d", &N, &M, &K);
        for(int i=0; i<N; i++) {
            for(int j=0; j<M; j++) {
                scanf("%d", &tt);
                if(tt>0) {
                    board[200+i][200+j].t = tt, board[200+i][200+j].state = 1;
                    q.push(cell(200+i, 200+j, tt, 1, tt));
                    visited[200+i][200+j] = 1;
                }
            }
        }

        vector<cell> next;

        int x, y, nx, ny, state, cur;
        int time = 0;
        while(time<K) {

            int size = q.size();
            while(size--) {
                cell c = q.front(); q.pop();
                x = c.x; y = c.y;
                state = c.state; cur = c.cur;

                if(state==1) {
                    if(cur>1)   q.push(cell(x, y, c.t, 1, cur-1));
                    else q.push(cell(x, y, c.t, 2, c.t)), next.push_back(cell(x, y, c.t, 2, c.t));
                }
                else { // == 2
                    for(int d=0; d<4; d++) {
                        nx = x+dx[d], ny = y+dy[d];
                        if(visited[nx][ny]) continue;
                        int nx2, ny2;
                        int mx = -1;
                        for(int d2=0; d2<4; d2++) {
                            nx2 = nx+dx[d2], ny2 = ny+dy[d2];
                            if(board[nx2][ny2].state!=2) continue;
                            mx = max(mx, board[nx2][ny2].t);
                        }
                        q.push(cell(nx, ny, mx, 1, mx));
                        next.push_back(cell(nx, ny, mx, 1, mx));
                        visited[nx][ny] = 1;
                    }
                    if(cur>1) q.push(cell(x, y, c.t, 2, cur-1));
                    else      board[x][y].state = -1;
                }
            }

            while(!next.empty()) {
                cell nc = next.back(); next.pop_back();
                board[nc.x][nc.y].t = nc.t;
                board[nc.x][nc.y].state = nc.state;
            }
            time++;
        }

        int ans = 0;
        for(int i=0; i<501; i++)
            for(int j=0; j<501; j++)
                if(board[i][j].state>0) ans++;

        printf("#%d %d\n", t, ans);
    }

    return 0;
}