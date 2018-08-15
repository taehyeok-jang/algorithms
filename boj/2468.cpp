#include <iostream>
#include <cmath>

using namespace std;

int tc, t;
int N;
int MAP[100][100];
char str[100];

bool visited[100][100];


bool DEBUG = false;

void dfs(int x, int y, int h) {

    visited[x][y] = true;

    for(int i=0; i<4; i++) {

        int nx = x+dx[i];
        int ny = y+dy[i];

        if(nx<0||nx>=N||ny<0||ny>=N)
            continue;
        if(visited[nx][ny])
            continue;

        if(MAP[nx][ny] > h)
            dfs(nx, ny, h);
    }
}

int main() {

//    FILE *fp = freopen("../data/2468.input", "r", stdin);
//    if(!fp)
//        perror("freopen error");

    tc = 1;
//    scanf("%d", &tc);
    t = 0;
    while(t++ < tc) {

        scanf("%d", &N);

        for(int i=0; i<N; i++)
            for(int j=0; j<N; j++)
                scanf("%d", &MAP[i][j]);

        int MAX = 1;
        for(int h=0; h<101; h++) {

            for(int i=0; i<N; i++) {
                for(int j=0; j<N; j++) {
                    visited[i][j] = false;
                }
            }

            int zone = 0;
            for(int i=0; i<N; i++)
                for(int j=0; j<N; j++)
                    if(!visited[i][j] && MAP[i][j] > h) {
                        zone++;
                        dfs(i, j, h);
                    }

            MAX = max(MAX, zone);
        }

        printf("%d", MAX);
    }

    return 0;
}

