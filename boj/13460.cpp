#include <stdio.h>
#include <cstdio>

using namespace std;
class Pos {
public:
    int y, x;
};
int ans, N, M;
char board[11][11];
Pos RP, BP, OP;
const int INF = 100;
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
int min(int a, int b) {
    return a < b ? a : b;
}
void dfs(int ry, int rx, int by, int bx, int cnt, int d) {
    if (10 < cnt) return;

    printf("%d %d %d %d %d %d\n", ry, rx, by, bx, cnt, d);

    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");


    for (int i = 0; i < 4; i++) {
        if ((d != 5) && (d == (i + 2) % 4)) continue;
        int cbY, cbX, crY, crX;
        cbY = by, cbX = bx;
        crY = ry, crX = rx;
        int doR = 1;
        while (1) {
            int nbY = cbY + dy[i];
            int nbX = cbX + dx[i];
            if (nbY < 0 || nbX < 0 || nbY >= N || nbX >= M || board[nbY][nbX] == '#') break;
            // 파란공이 가다가 빨간공과 만나면 밑에 while에서 빨간공 굴리지 않는다.
            if (board[nbY][nbX] == 'R') doR = 0;
            // 파란공이 구멍에 빠지면 끝낸다.
            if (nbY == OP.y && nbX == OP.x) return;
            cbY = nbY;
            cbX = nbX;
        }
        // 빨간공을 굴린다.
        if (doR) {
            board[by][bx] = '.';
            board[cbY][cbX] = 'B';
            while (1) {
                int nrY = crY + dy[i];
                int nrX = crX + dx[i];
                if (nrY < 0 || nrX < 0 || nrY >= N || nrX >= M || board[nrY][nrX] == '#' || board[nrY][nrX] == 'B') break;
                if (nrY == OP.y && nrX == OP.x) {
                    ans = min(ans, cnt);
                    return;
                }
                crY = nrY;
                crX = nrX;
            }
            board[ry][rx] = '.';
            board[crY][crX] = 'R';
        }
        else { // 파란공이 굴러가다 빨간공을 만난 경우이니 현재방향에서 빨간공을 파란공 앞에 둔다.
            crY = cbY;
            crX = cbX;
            cbY -= dy[i];
            cbX -= dx[i];
            board[ry][rx] = '.';
            board[crY][crX] = 'R';
            board[by][bx] = '.';
            board[cbY][cbX] = 'B';
        }
        /*printf("\n");
        for (int i = 0; i < N; i++) {
           for (int j = 0; j < M; j++) {
              printf("%c ", board[i][j]);
           }
           printf("\n");
        }*/
        dfs(crY, crX, cbY, cbX, cnt + 1, i);
        board[ry][rx] = 'R';
        board[crY][crX] = '.';
        board[by][bx] = 'B';
        board[cbY][cbX] = '.';
    }
}
// R, B가 동시에 구멍에 들어간다면 실패하는 거니 우선순위는 B가 더 크다. 그래서 B를 먼저 처리해 주어야 한다.
int main() {
    ans = INF;
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++)
        scanf("%s", board[i]);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (board[i][j] == 'R') RP.y = i, RP.x = j;
            else if (board[i][j] == 'B') BP.y = i, BP.x = j;
            else if (board[i][j] == 'O') OP.y = i, OP.x = j;
        }
    }
    dfs(RP.y, RP.x, BP.y, BP.x, 1, 5);
    printf("%d\n", ans == INF ? -1 : ans);
    return 0;
}