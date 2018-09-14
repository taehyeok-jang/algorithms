
#include <stdio.h>
#include <iostream>

using namespace std;
int tc, t;
int map[15][15], dist[15][15];
int N, A, B, C, D;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

struct state {
    int x, y, t;
};

state q[100001];
int f, r;

bool out_of_bounds(int x, int y) { return x<0||x>=N||y<0||y>=N; }

int main() {

    scanf("%d", &tc);
    t = 0;
    while(t++ < tc) {

        scanf("%d", &N);
        for(int i=0; i<N; i++)
            for(int j=0; j<N; j++)
                scanf("%d", &map[i][j]);
        scanf("%d%d%d%d", &A, &B, &C, &D);
        for(int i=0; i<N; i++)
            for(int j=0; j<N; j++)
                    dist[i][j] = 654321;

        int x, y, time, nx, ny;
        f = r = 0;
        q[r++] = state({A, B, 0});
        dist[A][B] = 0;
        while(f!=r) {

            state s = q[f++];
            x = s.x, y = s.y, time = s.t;
//            cout << x << ',' << y << " .. " << time << '\n';
            for(int d=0; d<4; d++) {
                nx = x+dx[d], ny = y+dy[d];
                if(out_of_bounds(nx, ny)) continue;
                if(map[nx][ny]==1) continue;

                if(map[nx][ny]==0) {
                    if(dist[x][y]+1<dist[nx][ny]) {
                        q[r++] = state({nx, ny, time+1});
                        dist[nx][ny] = dist[x][y]+1;
                    }
                }
                else { // == 2
                    if(dist[x][y]+3-time%3<dist[nx][ny]) {
                        q[r++] = state({nx, ny, time+3-time%3});
                        dist[nx][ny] = dist[x][y]+3-time%3;
                    }
                }
            }
        }

        int ans = dist[C][D];
        printf("#%d %d\n", t, ans==654321? -1:ans);
    }

    return 0;
}
/*
#include <stdio.h>

using namespace std;
#define MAX 654321;
int tc, t;
int map[15][15], visited[15][15];
int cache[15][15][501];
int N, A, B, C, D;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

bool out_of_bounds(int x, int y) { return x<0||x>=N||y<0||y>=N; }
int min(int a, int b) { return a<b? a:b; }

int dfs(int x, int y, const int time) {

    if(x==C&&y==D) return 0;
    if(cache[x][y][time]!=-1) return cache[x][y][time];
    cache[x][y][time] = 0; // just define in advance.

    visited[x][y] = 1;
    int ans = MAX;
    int nx, ny;
    for(int d=0; d<4; d++) {
        nx = x+dx[d], ny = y+dy[d];
        if(out_of_bounds(nx, ny)) continue;
        if(map[nx][ny]==1||visited[nx][ny]) continue;

        if(map[nx][ny]==0)
            ans = min(ans, 1+dfs(nx, ny, time+1));
        else // == 2
            ans = min(ans, 3-time%3+dfs(nx, ny, time+3-time%3));
    }
    visited[x][y] = 0;
    return cache[x][y][time] = ans;
}

int main() {

    scanf("%d", &tc);
    t = 0;
    while(t++ < tc) {

        scanf("%d", &N);
        for(int i=0; i<N; i++)
            for(int j=0; j<N; j++)
                scanf("%d", &map[i][j]);
        for(int i=0; i<N; i++)
            for(int j=0; j<N; j++)
                for(int k=0; k<501; k++)
                    cache[i][j][k] = -1;
        scanf("%d%d%d%d", &A, &B, &C, &D);

        int ans = dfs(A, B, 0);
        printf("#%d %d\n", t, ((ans==654321)? -1:ans)) ;
    }

    return 0;
}

*/