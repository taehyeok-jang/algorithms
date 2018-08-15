#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

int tc, t;
int N;
int map[11][11], check[11][11];

int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

bool DEBUG = false;

bool out_of_bound(int x, int y) { return x<0||x>=N||y<0||y>=N; }

long long solve(int x) {
    if(x == N) return 1;
    long long s = 0;
    int nx, ny;
    for(int y=0; y<N; y++) {
        if(check[x][y]==0) {
            for(int d=0; d<8; d++) {
                nx = x+dx[d], ny = y+dy[d];
                while(!out_of_bound(nx, ny)) {
                    check[nx][ny]++;
                    nx+=dx[d], ny+=dy[d];
                }
            }
            s += solve(x+1);
            for(int d=0; d<8; d++) {
                nx = x+dx[d], ny = y+dy[d];
                while(!out_of_bound(nx, ny)) {
                    check[nx][ny]--;
                    nx+=dx[d], ny+=dy[d];
                }
            }
        }
    }
    return s;
}

int main() {

//    FILE *fp = freopen("../data/3501.input", "r", stdin);
//    if(!fp)
//        perror("freopen error");

    scanf("%d", &tc);
    t = 0;
    while(t++ < tc) {

        scanf("%d", &N);
        memset(map, 0, sizeof(int)*121);
        memset(check, 0, sizeof(int)*121);

        printf("#%d %lld\n", t, solve(0));
    }

    return 0;
}
