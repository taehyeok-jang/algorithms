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

/**
 * corner case 를 어떻게 처리할 것인가? out_of_bounds & block, worm_hole ...
 *
 * dp 적용하려 했는데 이게 dfs 로 되는 문제인가? 값을 비교해서 큰 경우에 overriding 하면 될까.
 * 최적화 할 수 있는 부분이 존재하나?
 */



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
                    if(board[i][j]==0&&score[i][j][d]<0) {
                        int ss = play(i, j, d);
                        ans = max(ans, ss);
                    }
                }
        printf("#%d %d\n", t, ans);
    }

    return 0;
}