#include <iostream>
#include <vector>

using namespace std;

int tc, t, tt;

const int N = 16;
int MAP[N][N];
bool visit[N][N];
bool reach;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

bool DEBUG = false;

void dfs(int x, int y) {

//    cout << "dfs " << x << ", " << y << "\n";

    if(MAP[x][y] == 3) {
//        cout << "reach!!\n";
        reach = true;
        return;
    }

    visit[x][y] = true;

    for(int i=0; i<4; i++) {

        int nx = x+dx[i];
        int ny = y+dy[i];
        if(nx<0||nx>=N||ny<0||ny>=N)
            continue;

        if(!visit[nx][ny] && MAP[nx][ny] != 1)
            dfs(nx, ny);
    }
}

int main() {

//    FILE *fp = freopen("../data/1226.input", "r", stdin);
//    if(!fp)
//        perror("freopen error");

    tc = 10;
    t = 0;
    while(t++ < tc) {

        scanf("%d", &tt);
        char temp[N];
        for(int i=0; i<N; i++) {
            scanf("%s", temp);
            for(int j=0; j<N; j++)
                MAP[i][j] = temp[j]-48;
        }

        for(int i=0; i<N; i++)
            for(int j=0; j<N; j++)
                visit[i][j] = false;

        reach = false;

        int x = -1;
        int y = -1;
        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                if(MAP[i][j] == 2) {
                    x = i;
                    y = j;
                    break;
                }
            }
            if(x != -1)
                break;
        }

//        cout << "initial: " << x << ", " << y << "\n";

        dfs(x, y);

        printf("#%d %d\n", t, reach);
    }

    return 0;
}