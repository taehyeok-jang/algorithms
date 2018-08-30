#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;
#define MAX 2500001
int N, M, D, ans;
char map[501][501];
int visited[501][501][2501];
#ifdef DEBUG
#endif

struct point {
    int x, y;
    int count;
};
point q[MAX];
int f, r;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
bool out_of_bounds(int x, int y) { return x<0||x>=N||y<0||y>=M; }

int main() {

    scanf("%d%d%d", &N, &M, &D);
    for(int i=0; i<N; i++) scanf("%s", map[i]);
    memset(visited, 0, sizeof(visited));

    ans = MAX;
    f = r = 0;
    q[r++] = point({0, 0, 0});
    visited[0][0][0] = 0;
    while(f!=r) {

        point p = q[f++];
        if(p.x==N-1&&p.y==M-1) {
            ans = min(ans, p.count);
            continue;
        }
        // if there is at least one wall, bomb.
        int check = 0, nx, ny;
        for(int d=0; d<4; d++) {
            nx = p.x+dx[d], ny = p.y+dy[d];
            if(out_of_bounds(nx, ny)) continue;
            if(map[nx][ny]=='#') { check++; continue; }

            if(!visited[nx][ny][p.count]) {
                q[r++] = point({nx, ny, p.count});
                visited[nx][ny][p.count] = 1;
            }
        }
        if(check) {

        }
    }


    // TODO
    // 서로 각기 다른 폭파들 간에 visit check를 어떻게 해야할까?






    return 0;
}
