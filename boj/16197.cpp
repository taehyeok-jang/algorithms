#include <iostream>
#include <vector>
using namespace std;
#define INF 1e9
int N, M;
char board[22][22];
bool visited[2][22][22];
struct coin {
    int x, y;
};
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int min(int a, int b) { return a<b? a:b; }
bool out_of_bounds(int x, int y) { return x<1||x>=N+1||y<1||y>=M+1; }

int dfs(int cnt, int ax, int ay, int bx, int by) {
//    printf("%d,%d %d,%d\n", ax, ay, bx, by);
    if(cnt==11) return INF;
    if(out_of_bounds(ax, ay)&&out_of_bounds(bx, by)) return INF;
    if(out_of_bounds(ax, ay)||out_of_bounds(bx, by)) return cnt;
    visited[0][ax][ay] = 1, visited[1][bx][by] = 1;
    int nax, nay, nbx, nby;
    int ans = INF;
    for(int d=0; d<4; d++) {
        if(board[ax+dx[d]][ay+dy[d]]=='#'&&board[bx+dx[d]][by+dy[d]]=='#')
            continue;
        nax = ax, nay = ay, nbx = bx, nby = by;
        if(board[ax+dx[d]][ay+dy[d]]!='#') nax += dx[d], nay += dy[d];
        if(board[bx+dx[d]][by+dy[d]]!='#') nbx += dx[d], nby += dy[d];
        if(visited[0][nax][nay]&&visited[1][nbx][nby])
            continue;
        ans = min(ans, dfs(cnt+1, nax, nay, nbx, nby));
        visited[0][nax][nay] = 0, visited[1][nbx][nby] = 0;
    }
    return ans;
}

int main() {
    vector<coin> vec;
    cin >> N >> M;
    for(int i=0; i<N+2; i++)
        for(int j=0; j<M+2; j++)
            board[i][j] = '.';
    for(int i=1; i<N+1; i++) {
        for(int j=1; j<M+1; j++) {
            cin >> board[i][j];
            if(board[i][j]=='o')
                vec.push_back({i, j});
        }
    }
    int ans = dfs(0, vec[0].x, vec[0].y, vec[1].x, vec[1].y);
    cout << ((ans==INF)? -1:ans);
    return 0;
}

/*
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N, M;
char board[22][22];
struct coin {
    int x, y;
};
queue<vector<coin>> q;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
bool out_of_bounds(int x, int y) { return x<1||x>=N+1||y<1||y>=M+1; }
int main() {
    for(int i=0; i<N+2; i++)
        for(int j=0; j<M+2; j++)
            board[i][j] = '.';
    vector<coin> vec;
    cin >> N >> M;
    for(int i=1; i<N+1; i++) {
        for(int j=1; j<M+1; j++) {
            cin >> board[i][j];
            if(board[i][j]=='o')
                vec.push_back({i, j});
        }
    }

    q.push(vec);
    int ax, ay, bx, by;
    bool solved = 0; int cnt = 0;
    while(cnt<11) {
        int size = q.size();
        while(size--) {
            vector<coin> coins = q.front(); q.pop();
            ax = coins[0].x, ay = coins[0].y;
            bx = coins[1].x, by = coins[1].y;

//            printf("%d,%d %d,%d\n", ax, ay, bx, by);

            if(out_of_bounds(ax, ay)&&out_of_bounds(bx, by)) { continue; }
            if(out_of_bounds(ax, ay)||out_of_bounds(bx, by)) { solved = 1; break; }

            int nax, nay, nbx, nby;
            for(int d=0; d<4; d++) {
                if(board[ax+dx[d]][ay+dy[d]]=='#'&&board[bx+dx[d]][by+dy[d]]=='#')
                    continue;
                if(board[ax+dx[d]][ay+dy[d]]=='#') nax = ax, nay = ay;
                else                               nax = ax+dx[d], nay = ay+dy[d];
                if(board[bx+dx[d]][by+dy[d]]=='#') nbx = bx, nby = by;
                else                               nbx = bx+dx[d], nby = by+dy[d];

                if(nax==nbx&&nay==nby)
                    continue;

                vector<coin> next;
                next.push_back({nax, nay}); next.push_back({nbx, nby});
                q.push(next);
            }
        }

        if(solved) break;
        cnt++;
    }

    cout << ((solved)? cnt:-1);
    return 0;
}
*/