#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;

int tc, t;
int H, W, N;
char map[21][21], command[101];

char d[4] = {'U', 'R', 'D', 'L'};
char d2[4] = {'^', '>', 'v', '<'};
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
bool DEBUG = false;

bool out_of_bound(int x, int y) { return x<0||x>=H||y<0||y>=W; }
int dir(char c) { for(int i=0; i<4; i++) if(d[i] == c) return i; }

int main() {

//    FILE *fp = freopen("../data/3501.input", "r", stdin);
//    if(!fp)
//        perror("freopen error");

    scanf("%d", &tc);
    t = 0;
    while(t++ < tc) {

        scanf("%d%d", &H, &W);
        char buf[21];
        int x, y, d;
        for(int i=0; i<H; i++) {
            scanf("%s", buf);
            for(int j=0; j<W; j++) {
                map[i][j] = buf[j];
                if(buf[j]=='^'||buf[j]=='>'||buf[j]=='v'||buf[j]=='<') {
                    x=i, y=j;
                    if(buf[j]=='^')         d = 0;
                    else if(buf[j]=='>')    d = 1;
                    else if(buf[j]=='v')    d = 2;
                    else                    d = 3;
                }
            }
        }
        scanf("%d", &N);
        scanf("%s", command);
        for(int i=0; i<N; i++) {
            char c = command[i];
            if(c == 'S') {
                int nx = x+dx[d], ny = y+dy[d];
                while(!out_of_bound(nx, ny)&&(map[nx][ny]=='.'||map[nx][ny]=='-'))
                    nx += dx[d], ny += dy[d];
                if(out_of_bound(nx, ny)) continue;
                else if(map[nx][ny]=='*') map[nx][ny] = '.';
                // '#'
            }
            else {
                d = dir(c);
                map[x][y] = d2[d];
                if(!out_of_bound(x+dx[d], y+dy[d])&&map[x+dx[d]][y+dy[d]]=='.') {
                    map[x+dx[d]][y+dy[d]] = map[x][y];
                    map[x][y] = '.';
                    x += dx[d];
                    y += dy[d];
                }
            }
        }

        printf("#%d ", t);
        for(int i=0; i<H; i++) {
            for(int j=0; j<W; j++) {
                cout << map[i][j];
            }
            cout << "\n";
        }
    }

    return 0;
}
