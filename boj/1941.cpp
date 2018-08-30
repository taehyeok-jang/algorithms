#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

char map[5][5];
int perm[5][5], visited[5][5];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

bool out_of_bound(int x, int y) { return x<0||x>=5||y<0||y>=5; }

int dfs(int x, int y) {

    visited[x][y] = 1;
    int l = 1, nx, ny;
    for(int d=0; d<4; d++) {
        nx = x+dx[d], ny = y+dy[d];
        if(out_of_bound(nx, ny)||visited[nx][ny]||!perm[nx][ny]) continue;
        l += dfs(nx, ny);
    }
    return l;
}

int main() {

    for(int i=0; i<5; i++)
        scanf("%s", map[i]);

    vector<int> state(25, 0);
    for(int i=0; i<7; i++) state[24-i] = 1;
    int ans = 0;
    do {

        memset(perm, 0, sizeof(perm));
        int scnt = 0, x, y, lx, ly;
        for(int i=0; i<25; i++) {
            x = i/5, y = i%5;
            perm[x][y] = state[i];
            if(perm[x][y]) {
                lx = x;
                ly = y;
                scnt += (map[x][y]=='S');
            }
        }
        if(scnt<4)
            continue;

        memset(visited, 0, sizeof(visited));
        ans += (dfs(lx, ly)==7);

    } while(next_permutation(state.begin(), state.end()));

    printf("%d", ans);

    return 0;
}
