#include<iostream>
#include<queue>
using namespace std;
int tc, t;
int N, W, H;
int board[20][20];
struct point {
    int x, y, b;
};
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int min(int a, int b) { return a < b ? a : b; }
bool out_of_bounds(int x, int y) { return x < 0 || x >= H || y < 0 || y >= W; }

int solve(int n) {

    if (n == N) {
        int cnt = 0;
        for (int i = 0; i < H; i++)
            for (int j = 0; j < W; j++)
                if (board[i][j]) cnt++;
        return cnt;
    }

    int visited[20][20], aux[20][20];
    for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++)
            visited[i][j] = 0, aux[i][j] = board[i][j];

    queue<point> bomb, down;
    int ans = W * H;
    bool go = 0;
    for (int c = 0; c < W; c++) {

        int r = 0;
        while (r<H&&board[r][c] == 0) r++;
        if (r == H) continue;

        go = 1;

        bomb.push(point({ r, c, board[r][c] }));
        board[r][c] = 0, visited[r][c] = 1;

        while (!bomb.empty()) {

            point p = bomb.front(); bomb.pop();
            int nx, ny;
            for (int d = 0; d < 4; d++) {
                nx = p.x+dx[d], ny = p.y+dy[d];
                for (int i = 0; i < p.b - 1; i++) {
                    if (out_of_bounds(nx, ny)) continue;
                    if (!visited[nx][ny]) {
                        if (board[nx][ny] > 1) bomb.push({ nx, ny, board[nx][ny] });
                        board[nx][ny] = 0, visited[nx][ny] = 1;
                    }
                    nx += dx[d], ny += dy[d];
                }
            }
        }

        for (int i = 0; i < W; i++) {
            r = H - 1;
            while (r >= 0) {
                if (board[r][i]) down.push({ r, i, board[r][i] });
                r--;
            }
            r = H - 1;
            while (!down.empty()) {
                point p = down.front(); down.pop();
                board[r--][i] = p.b;
            }
            while (r >= 0) board[r--][i] = 0;
        }

        ans = min(ans, solve(n + 1));

        for (int i = 0; i < H; i++)
            for (int j = 0; j < W; j++)
                visited[i][j] = 0, board[i][j] = aux[i][j];
    }

    if (!go) return 0;
    else     return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> tc;
    t = 0;
    while (t++ < tc) {
        cin >> N >> W >> H;
        for (int i = 0; i < H; i++)
            for (int j = 0; j < W; j++)
                cin >> board[i][j];
        int ans = solve(0);
        cout << "#" << t << " " << ans << "\n";
    }
    return 0;
}