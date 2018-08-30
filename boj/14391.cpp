#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;
struct point {
    int x, y;
    int n;
};

int N, M, ans;
int map[4][4];
int visited[4][4];

int sum(const bool hv) {

    int sum = 0;
    int tmp; bool check;

    for(int x=0; x<N; x++) {
        tmp = 0, check = 0;
        for(int y=0; y<M; y++) {
            if(visited[x][y]==hv) { // check 0, 1 both inclusive.
                tmp = 10*tmp+map[x][y];
                check = 1;
            }
            if(visited[x][y]!=hv&&check) {
                sum += tmp;
                tmp = 0;
                check = 0;
            }
        }
        sum += tmp;
    }

    for(int y=0; y<M; y++) {
        tmp = 0, check = 0;
        for(int x=0; x<N; x++) {
            if(visited[x][y]!=hv) { // check 0, 1 both inclusive.
                tmp = 10*tmp+map[x][y];
                check = 1;
            }
            if(visited[x][y]==hv&&check) {
                sum += tmp;
                tmp = 0;
                check = 0;
            }
        }
        sum += tmp;
    }

    return sum;
}

void h_dfs(int l) {

    if(l==N) {
        ans = max(ans, sum(true));
        return;
    }
    for(int i=0; i<(1<<M); i++) {

        for(int j=0; j<M; j++)
            if(i&(1<<j))
                visited[l][j] = 1;
        h_dfs(l+1);
        for(int j=0; j<M; j++)
            visited[l][j] = 0;
    }
}

void v_dfs(int l) {

    if(l==M) {
        ans = max(ans, sum(false));
        return;
    }
    for(int i=0; i<(1<<N); i++) {
        for(int j=0; j<N; j++)
            if(i&(1<<j))
                visited[j][l] = 1;
        v_dfs(l+1);
        for(int j=0; j<N; j++)
            visited[j][l] = 0;
    }
}

int main() {

//    FILE *fp = freopen("../data/battle.input", "r", stdin);
//    if(!fp)
//        perror("freopen error");

    scanf("%d%d", &N, &M);
    char buf[4];
    for(int i=0; i<N; i++) {
        scanf("%s", buf);
        for(int j=0; j<M; j++) map[i][j] = buf[j]-'0';
    }

    ans = -1;
    memset(visited, 0, sizeof(visited));
    h_dfs(0);
//    memset(visited, 0, sizeof(visited));
//    v_dfs(0);

    printf("%d", ans);
    return 0;
}
