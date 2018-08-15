#include <iostream>

using namespace std;
#define MAX 31

int M, N;
char map[MAX][MAX];
bool visited[MAX][MAX];
char buf[MAX];
int t, ans, point;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
bool DEBUG = false;

bool out_of_bound(int x, int y) { return x<0||x>=M||y<0||y>=N; }

int solve(int x, int y, int p) {
    if(p == point-1) { return 0; }
    int m = 654321;
    bool stop = 1;
    int nx, ny, sx, sy, ex, ey;
    visited[x][y] = 1;
    for(int d=0; d<4; d++) {
        nx=x+dx[d], ny=y+dy[d];
        if(out_of_bound(nx, ny)||map[nx][ny]=='*'||visited[nx][ny]) continue;
        stop = 0;
        sx=nx, sy=ny;
        while(!(out_of_bound(nx, ny)||map[nx][ny]=='*'||visited[nx][ny])) nx+=dx[d], ny+=dy[d];
        ex=nx-dx[d], ey=ny-dy[d];

        nx=sx, ny=sy;
        while(!(nx==ex&&ny==ey)) visited[nx][ny] = 1, nx+=dx[d], ny+=dy[d], p++;
        m = min(m, 1+solve(ex, ey, 1+p));
        // back-track.
        nx=sx, ny=sy;
        while(!(nx==ex&&ny==ey)) visited[nx][ny] = 0, nx+=dx[d], ny+=dy[d], p--;
    }
    visited[x][y] = 0;
    if(stop) return 654321;
    else     return m;
}

int main() {

//    FILE *fp = freopen("../data/9944.input", "r", stdin);
//    if(!fp)
//        perror("freopen error");
    t = 1;
    while(scanf("%d%d", &M, &N)!=EOF) {

        point = 0;
        for(int i=0; i<M; i++) { scanf("%s", buf); for(int j=0; j<N; j++) { if(buf[j]=='.') point++; map[i][j] = buf[j]; }}
        for(int i=0; i<M; i++) for(int j=0; j<N; j++) visited[i][j] = 0;
        ans = 654321;
        for(int x=0; x<M; x++) {
            for(int y=0; y<N; y++) {
                if(map[x][y]=='*') continue;
                ans = min(ans, solve(x, y, 0));
            }
        }
        printf("Case %d: %d\n", t++, (ans==654321)? -1:ans);
    }

    return 0;
}
