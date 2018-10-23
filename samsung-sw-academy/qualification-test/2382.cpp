#include <iostream>
using namespace std;
int tc, t;
int N, M, K;
struct ss {
    int sum, mx, t;
} stat[101][101];
struct point {
    int x, y, s, d, alive;
} p[10001];
// none, up, down, left, right
int dx[5] = {-5, -1, 1, 0, 0};
int dy[5] = {-5, 0, 0, -1, 1};
bool on_bounds(int x, int y) { return x==0||x==N-1||y==0||y==N-1; }
int max(int a, int b) { return a>b? a:b; }

int main() {

//    FILE *fp = freopen("../data/3501.input", "r", stdin);
//    if(!fp)
//        perror("freopen error");

    cin >> tc;
    t = 0;
    while(t++ < tc) {

        cin >> N >> M >> K;

        for(int i=0; i<N; i++)
            for(int j=0; j<N; j++)
                stat[i][j].t = -1;

        for(int i=0; i<K; i++) {
            cin >> p[i].x >> p[i].y >> p[i].s >> p[i].d;
            p[i].alive = 1;
        }

        for(int time=0; time<M; time++) {

            for(int i=0; i<K; i++) {
                if(!p[i].alive) continue;
                int nx = p[i].x+dx[p[i].d], ny = p[i].y+dy[p[i].d];
                if(time>stat[nx][ny].t) {
                    stat[nx][ny].t = time;
                    stat[nx][ny].sum = 0, stat[nx][ny].mx = 0;
                }
                stat[nx][ny].sum += p[i].s, stat[nx][ny].mx = max(stat[nx][ny].mx, p[i].s);
                p[i].x = nx, p[i].y = ny;
            }

            for(int i=0; i<K; i++) {
                if(!p[i].alive) continue;
                if(on_bounds(p[i].x, p[i].y)) {
                    if(p[i].s/2>0) p[i].s /= 2, p[i].d += (p[i].d%2)? 1:-1;
                    else           p[i].alive = 0;
                }
                else {
                    if(stat[p[i].x][p[i].y].mx==p[i].s) p[i].s = stat[p[i].x][p[i].y].sum;
                    else p[i].alive = 0; // overrode.
                }
            }
        }

        int ans = 0;
        for(int i=0; i<K; i++) {
            if(!p[i].alive) continue;
            ans += p[i].s;
        }

        cout << "#" << t << " " << ans << "\n";
    }

    return 0;
}