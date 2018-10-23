#include <stdio.h>
#define INF 654321
int N, M, H;
int map[35][15]; // 0: go down, -1: go left, 1: go right.
int visited[15];
int min(int a, int b) { return a<b? a:b; }
bool check() {
    for(int c=1; c<N+1; c++) {
        int cur = c;
        for(int r=0; r<H+2; r++) {
            if(map[r][cur]==1) cur++;
            else if(map[r][cur]==-1) cur--;
        }
        if(cur!=c) return 0;
    }
    return 1;
}

int solve(int k) {

    if(check()) return k;
    if(k==3) return INF;

    int ans = INF;
    for(int c=1; c<N; c++) {
        for(int r=1; r<H+1; r++) {
            if(!(map[r][c]==0&&map[r][c+1]==0)) continue;
            map[r][c] = 1, map[r][c+1] = -1;
            ans = min(ans, solve(k+1));
            map[r][c] = 0, map[r][c+1] = 0; // back-track.
            while(1){
                if(r>=H) break;
                if(map[r+1][c]||map[r+1][c+1]) break;
                r++;
            }
        }
    }

    return ans;
}

int main() {
    scanf("%d%d%d", &N, &M, &H);
    int a, b;
    for(int i=0; i<M; i++) {
        scanf("%d%d", &a, &b);
        map[a][b] = 1, map[a][b+1] = -1;
    }
    int ans = solve(0);
    printf("%d", ((ans==INF)? -1:ans));
    return 0;
}

