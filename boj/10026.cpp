#include <iostream>
#include <vector>

using namespace std;

int tc, t;
int N;
char MAP[100][100];
char str[100];

bool visited[100][100];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

bool DEBUG = false;

void dfs(int x, int y, bool normal) {

    visited[x][y] = true;

    for(int i=0; i<4; i++) {

        int nx = x+dx[i];
        int ny = y+dy[i];

        if(nx<0||nx>=N||ny<0||ny>=N)
            continue;
        if(visited[nx][ny])
            continue;

        if(normal) {
            if(MAP[x][y]==MAP[nx][ny])
                dfs(nx, ny, normal);
        }
        else { // abnormal
            if(MAP[x][y] == 'B') {
                if(MAP[nx][ny] == 'B')
                    dfs(nx, ny, normal);
            }
            else {
                if(MAP[nx][ny]=='R'||MAP[nx][ny]=='G')
                    dfs(nx, ny, normal);
            }
        }

    }


}

int main() {

//    FILE *fp = freopen("../data/10026.input", "r", stdin);
//    if(!fp)
//        perror("freopen error");

    tc = 1;
//    scanf("%d", &tc);
    t = 0;
    while(t++ < tc) {

        scanf("%d", &N);

        for(int i=0; i<N; i++) {
            scanf("%s", str);
            for(int j=0; j<N; j++)
                MAP[i][j] = str[j];
        }

        for(int i=0; i<N; i++)
            for(int j=0; j<N; j++)
                visited[i][j] = false;

        int normal = 0;
        for(int i=0; i<N; i++)
            for(int j=0; j<N; j++)
                if(!visited[i][j]) {
                    normal++;
                    dfs(i, j, true);
                }

        for(int i=0; i<N; i++)
            for(int j=0; j<N; j++)
                visited[i][j] = false;

        int abnormal = 0;
        for(int i=0; i<N; i++)
            for(int j=0; j<N; j++)
                if(!visited[i][j]) {
                    abnormal++;
                    dfs(i, j, false);
                }

        printf("%d %d", normal, abnormal);
    }

    return 0;
}