#include <stdio.h>
#include <cstring>
#include <iostream>

using namespace std;

#define MAX 1000005
int N, M;
int map[1001][1001];
int visited[1001][1001][2], cache[1001][1001][2];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

bool out_of_bounds(int x, int y) { return x<0||x>=N||y<0||y>=M; }
int min(int a, int b) { return a<b? a:b; }

int solve(int x, int y, int used) {

    if(x==N-1&&y==M-1) return 1;
    if(cache[x][y][used]!=-1) return cache[x][y][used];
    visited[x][y][used] = 1;

    int ans = MAX, nx, ny, next_used;
    for(int d=0; d<4; d++) {
        nx = x+dx[d], ny = y+dy[d];
        if(out_of_bounds(nx, ny)) continue;
        if(used&&map[nx][ny]==1) continue;

        next_used = (map[nx][ny])? 1:used;
        if(!visited[nx][ny][next_used])
            ans = min(ans, 1+solve(nx, ny, next_used));
    }
    visited[x][y][used] = 0;
    return cache[x][y][used] = ans;
}

int main() {

    char buf[1001];
    scanf("%d%d", &N, &M);
    for(int i=0; i<N; i++) {
        scanf("%s", buf);
        for(int j=0; j<M; j++) map[i][j] = buf[j]-48;
    }
    memset(visited, 0, sizeof(visited));
    memset(cache, -1, sizeof(cache));

    int ans = solve(0, 0, 0);
    printf("%d", (ans<MAX)? ans:-1);
    return 0;
}


/*
 * bfs implementation.

#include <stdio.h>
using namespace std;

#define MAX 1000005
int N, M;
int map[1001][1001], visited[1001][1001][2];
struct point {
    int x, y;
    bool used;
    point() {}
    point(int _x, int _y, bool _u) { x=_x, y=_y, used=_u; }
};
point q[MAX];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

bool out_of_bounds(int x, int y) { return x<0||x>=N||y<0||y>=M; }

int main() {

    char buf[1001];
    scanf("%d%d", &N, &M);
    for(int i=0; i<N; i++) {
        scanf("%s", buf);
        for(int j=0; j<M; j++) map[i][j] = buf[j]-48;
    }

    bool solved = 0;
    int time = 0, f = 0, r = 0, nx, ny, s;
    q[r++] = point(0, 0, 0);
    visited[0][0][0] = 1;
    while(f!=r) {
        time++;
        s = r-f;
        while(s--) {
            point p = q[f++];
            if(p.x==N-1&&p.y==M-1) { solved = 1; break; }
            for(int d=0; d<4; d++) {
                nx = p.x+dx[d], ny = p.y+dy[d];
                if(out_of_bounds(nx, ny)) continue;
                if(p.used&&map[nx][ny]) continue;

                int used = (map[nx][ny])? 1:p.used;
                if(!visited[nx][ny][used]) {
                    q[r++] = point(nx, ny, used);
                    visited[nx][ny][used] = 1;
                }
            }
        }
        if(solved) break;
    }

    printf("%d", (solved)? time:-1);
    return 0;
}
*/
