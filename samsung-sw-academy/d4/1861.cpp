#include <iostream>
#include <cmath>

using namespace std;

int tc, t;
int N;
int MAP[1000][1000];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

bool DEBUG = false;

int dfs(int current, int x, int y) {

    int m = 0;
    for(int i=0; i<4; i++) {

        int nx = x+dx[i];
        int ny = y+dy[i];

        if(nx>=0&&nx<N&&ny>=0&&ny<N)
            if(MAP[nx][ny] == current+1)
                m = max(m, 1+dfs(MAP[nx][ny], nx, ny));
    }

    return m;
}

int main() {

//    FILE *fp = freopen("../data/1861.input", "r", stdin);
//    if(!fp)
//        perror("freopen error");

    scanf("%d", &tc);
    t = 0;
    while(t++ < tc) {

        scanf("%d", &N);
        for(int i=0; i<N; i++)
            for(int j=0; j<N; j++)
                scanf("%d", &MAP[i][j]);

        int index = -1;
        int m = 0;
        for(int x=0; x<N; x++) {
            for(int y=0; y<N; y++) {

//                cout << x << ", " << y << "\n";

                int length = dfs(MAP[x][y], x, y);
                if(length > m) {
//                    cout << "max length: " << length << "\n";
                    m = length;
                    index = MAP[x][y];
                }
                else if(length == m) {
//                    cout << "index update " << index << " to " << MAP[x][y] << "\n";
                    if(MAP[x][y] < index)
                        index = MAP[x][y];
                }
            }
        }

        printf("#%d %d %d\n", t, index, m+1);
    }

    return 0;
}