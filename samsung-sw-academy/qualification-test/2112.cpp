#include <stdio.h>

using namespace std;

int tc, t;
int D, W, K; // 13, 20, D.
int map[14][21], buf[14][21];
int check[14];
int ans;

int max(int a, int b) { return a>b? a:b; }
int min(int a, int b) { return a<b? a:b; }

bool is_ok(int c) {

    int a, b, flag;
    for(int w=0; w<W; w++) {
        a = 0, b = 0, flag = 0;
        for(int v=0; v<D; v++) {
            if(map[v][w]==c||check[v]) a++, b=0;
            else b++, a=0;
            if(a>=K||b>=K) { flag = 1; break; }
        }
        if(!flag) return 0;
    }
    return 1; // return pass.
}

void dfs(int idx, int cnt) {

    if(cnt>=ans) return;
    if(is_ok(0)||is_ok(1)) {
        ans = min(ans, cnt);
        return;
    }
    if(idx==D) return;

    dfs(idx+1, cnt);

    check[idx] = 1;
    dfs(idx+1, cnt+1);
    check[idx] = 0;
}


int main() {

//    FILE *fp = freopen("../data/battle.input", "r", stdin);
//    if(!fp)
//        perror("freopen error");

    scanf("%d", &tc);
    t = 0;
    while(t++ < tc) {

        scanf("%d%d%d", &D, &W, &K);
        for(int i=0; i<D; i++)
            for(int j=0; j<W; j++)
                scanf("%d", &map[i][j]);

        ans = K;
        dfs(0, 0); // update ans.
        printf("#%d %d\n", t, ans);
    }

    return 0;
}
