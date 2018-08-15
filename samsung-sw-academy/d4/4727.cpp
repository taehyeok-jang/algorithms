#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

#define FILE_IO 1
//#define DEBUG 1

int N, M;
int map[10][10];
int visited[10][10];
int TIME_MAX = 654321;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

struct sign {
    int x, y, period;
    sign(int a, int b, int c) { x=a, y=b, period=c; }
};
vector<sign> S;
struct walk {
    int x, y, stay;
    walk(int a, int b, int c) { x=a, y=b, stay=c; }
};

bool out_of_bound(int x, int y) { return x<0||x>=N||y<0||y>=N; }

bool is_cross(int x, int y) {

    int nx1, ny1, nx2, ny2;
    for(int d=0; d<4; d++) {
        nx1 = x+dx[d], ny1 = y+dy[d];
        nx2 = x+dx[(d+1)%4], ny2 = y+dy[(d+1)%4];
        if(out_of_bound(nx1, ny1)||out_of_bound(nx2, ny2)) continue;
        if(map[nx1][ny1]==0&&map[nx2][ny2]==0)
            return 1;
    }
    return 0;
}

int bfs(int x, int y, vector<sign> &S) {

    int time = 0;

    queue<walk> Q;
    Q.push(walk(0, 0, 0));
    visited[0][0] = 1;
    while(time++<TIME_MAX&&!Q.empty()) {
        #ifdef DEBUG
        cout << "t: " << time << "\n";
        #endif
        for(int i=0; i<S.size(); i++) {
            if(time%S[i].period==0) { map[S[i].x][S[i].y] = S[i].period; }
            else                    { map[S[i].x][S[i].y] = -S[i].period; }
        }
        int s = Q.size();
        while(s--) {
            walk w = Q.front(); Q.pop();
            if(w.x==N-1&&w.y==N-1) { return (time-1); }

            if(w.stay>0&&map[w.x][w.y]==1) {
                w.stay -= 1;
                Q.push(w);
                visited[w.x][w.y] += 1;
            }
            else {
                int nx, ny, wait;
                for(int d=0; d<4; d++) {
                    nx = w.x+dx[d], ny = w.y+dy[d];
                    if(out_of_bound(nx, ny)||visited[nx][ny]||map[nx][ny]==0)
                        continue;

                    // map: 0, 1~n, -1~
                    if(map[nx][ny]>=1) {
                        if(map[nx][ny]>1&&map[w.x][w.x]<0) continue;
                        Q.push(walk(nx, ny, 0));
                        visited[nx][ny] = 1;
                    }
                    else { // map[nx][ny]<0
                        wait = 0;
                        while(wait<time) wait += (-map[nx][ny]);
                        Q.push(walk(w.x, w.y, wait-time-1));
                    }
                }
            }
        }

        #if DEBUG
        for(int i=0; i<N; i++) {
            for (int j = 0; j < N; j++) {
                cout << visited[i][j] << " ";
            }
            cout << "\n";
        }
        cout << "\n";
        #endif
    }

    return 654321;
}

int main() {

#if FILE_IO
//    FILE *fp = freopen("../data/4727.input", "r", stdin);
//    if(!fp)
//        perror("freopen error");
#endif

    int tc, t;
    scanf("%d", &tc);
    t = 0;
    while(t++ < tc) {

        S.clear();

        scanf("%d%d", &N, &M);
        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                scanf("%d", &map[i][j]);
                if(map[i][j]>1) S.push_back(sign(i, j, map[i][j]));
            }
        }

        int time = TIME_MAX;
        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {

                if(map[i][j]!=0||is_cross(i,j)) continue;

                memset(visited, 0, sizeof(int)*100);
                map[i][j] = M;
                S.push_back(sign(i, j, M));

                time = min(time, bfs(i, j, S));

                map[i][j] = 0;
                S.pop_back();
            }
        }

        printf("#%d %d\n", t, time);
    }

    return 0;
}
