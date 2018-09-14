#include <stdio.h>
#include <iostream>

using namespace std;

int tc, t;
int N;
int map[21][21], check[101];
int dx[4] = {1, 1, -1, -1};
int dy[4] = {-1, 1, 1, -1};

bool out_of_bounds(int x, int y) { return x<0||x>=N||y<0||y>=N; }

int draw(int a, int b, int x, int y) {

    int l, count = 0;
    for(int d=0; d<4; d++) {
        l = (d%2==0)? a:b;
        for(int i=0; i<l; i++) {
            x += dx[d], y += dy[d];
            if(out_of_bounds(x, y)||check[map[x][y]]) return -1;
            check[map[x][y]] = 1;
            count++;
        }
    }
    return count;
}

int max(int a, int b) { return a>b? a:b; }

int main() {

//    FILE *fp = freopen("../data/battle.input", "r", stdin);
//    if(!fp)
//        perror("freopen error");

    scanf("%d", &tc);
    t = 0;
    while(t++ < tc) {

        scanf("%d", &N);
        for(int i=0; i<N; i++)
            for(int j=0; j<N; j++)
                scanf("%d", &map[i][j]);

        int ans = -1;
        for(int a=1; a<N; a++) {
            for(int b=1; b<N; b++) {
                // for each a x b parallelogram.
                for(int x=0; x<N; x++) {
                    for(int y=0; y<N; y++) {
                        // for each starting point.
                        for(int i=1; i<101; i++) check[i] = 0;
                        ans = max(ans, draw(a, b, x, y));
                    }
                }
            }
        }
        printf("#%d %d\n", t, ans);
    }

    return 0;
}
