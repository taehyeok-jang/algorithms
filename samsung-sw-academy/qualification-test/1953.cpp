#include <stdio.h>

using namespace std;

int tc, t;
int map[51][51], visited[51][51];
int N, M, R, C, L;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

struct p {
    int x, y;
    int depth;
};

p q[10001]; int f, r;

bool out_of_bounds(int x, int y) { return x<0||x>=N||y<0||y>=M; }

bool can_pass(int m, int d) {

    switch(m) {
        case 0: return 0;
        case 1: return 1;
        case 2: if(d==0||d==2) return 1; break;
        case 3: if(d==1||d==3) return 1; break;
        case 4: if(d==0||d==1) return 1; break;
        case 5: if(d==1||d==2) return 1; break;
        case 6: if(d==2||d==3) return 1; break;
        case 7: if(d==3||d==0) return 1; break;
    }
    return 0;
}

int main() {

//    FILE *fp = freopen("../data/battle.input", "r", stdin);
//    if(!fp)
//        perror("freopen error");

    scanf("%d", &tc);
    t = 0;
    while(t++ < tc) {

        scanf("%d%d%d%d%d", &N, &M, &R, &C, &L);
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
                scanf("%d", &map[i][j]);
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
                visited[i][j] = 0;

        int count = 1;
        f = r = 0;
        q[r++] = p({R, C, 1});
        visited[R][C] = 1;
        int x, y, depth, nx, ny;
        while(f!=r) {

            p pp = q[f++];
            x = pp.x, y = pp.y, depth = pp.depth;

            for(int d=0; d<4; d++) {
                nx = x+dx[d], ny = y+dy[d];
                if(out_of_bounds(nx, ny)) continue;
                if(depth==L||visited[nx][ny]) continue;
                if(!(can_pass(map[x][y], d)&&can_pass(map[nx][ny], (d+2)%4))) continue;

                q[r++] = p({nx, ny, depth+1});
                visited[nx][ny] = depth;
                count++;
            }
        }

        printf("#%d %d\n", t, count);
    }

    return 0;
}
