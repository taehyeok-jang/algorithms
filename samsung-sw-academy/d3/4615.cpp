#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;

int tc, t;
int N, K;
int map[10][10];

int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

bool DEBUG = false;

int main() {

//    FILE *fp = freopen("../data/4615.input", "r", stdin);
//    if(!fp)
//        perror("freopen error");

    scanf("%d", &tc);
    t = 0;
    while(t++ < tc) {

        scanf("%d%d", &N, &K);
        for(int i=0; i<N; i++)
            for(int j=0; j<N; j++)
                map[i][j] = 0;

        // b:1, w:2
        int th = N/2-1;
        map[th][th+1] = 1;
        map[th+1][th] = 1;
        map[th][th] = 2;
        map[th+1][th+1] = 2;

        int x, y, c;
        int a, b;
        for(int i=0; i<K; i++) {

            scanf("%d%d%d", &a, &b, &c);

//            cout << "input: " << a << ", " << b << ", " << c << "\n";
            x = b-1;
            y = a-1;

            map[x][y] = c;

            int nx, ny;
            for(int d=0; d<8; d++) {

//                bool flip = true;
                nx = x+dx[d];
                ny = y+dy[d];
                if(map[nx][ny] == c)
                    continue;

                while((nx>=0&&nx<N)&&(ny>=0&&ny<N)&&map[nx][ny]==(c%2+1)) {
                    nx += dx[d];
                    ny += dy[d];
                }
                // if out of bounds, or map[nx][ny] == 0 or c.
                if(!((nx>=0&&nx<N)&&(ny>=0&&ny<N))||map[nx][ny]==0)
                    continue;

//                cout << "success at " << d << "\n";

                nx = x+dx[d];
                ny = y+dy[d];
                while((nx>=0&&nx<N)&&(ny>=0&&ny<N)&&map[nx][ny]==(c%2+1)) {
                    map[nx][ny] = c;
                    nx += dx[d];
                    ny += dy[d];
                }
            }

//            for(int i=0; i<N; i++) {
//                for(int j=0; j<N; j++) {
//                    cout << map[i][j] << " ";
//                }
//                cout << "\n";
//            }
//            cout << "\n";
        }

        int black = 0;
        int white = 0;
        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                if(map[i][j] == 1)  black++;
                if(map[i][j] == 2)  white++;
            }
        }

        printf("#%d %d %d\n", t, black, white);
    }

    return 0;
}
