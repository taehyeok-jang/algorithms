#include <cstdio>

struct coord{
    int x, y;
};
const int MX = 55;
int home_cnt, chicken_cnt;
coord chicken[MX], home[MX * 2];
int ans, N, M;
int map[MX][MX];


int abs(int a) { return a<0? -a:a; }
int min(int a, int b) { return a<b? a:b;}
int manhatten_dist(int x1, int y1, int x2, int y2) { return abs(x1 - x2) + abs(y1 - y2); }

int chicken_dist(bool *selected) {

    int sum = 0;
    for(int i=0; i<home_cnt; i++) {
        int tmp = 0x7fffffff;
        for(int j=0; j<chicken_cnt; j++)
            if(selected[j])
                tmp = min(tmp, manhatten_dist(home[i].x, home[i].y, chicken[j].x, chicken[j].y));
        sum += tmp;
    }
    return sum;
}

void solve() {

    for(int i=1; i<(1<<chicken_cnt); i++) {
        bool selected[MX] = {false, };
        int selected_cnt = 0;

        for(int j=0; j<chicken_cnt; j++)
            if(i&(1<<j))
                selected[j]=1, selected_cnt++;

        if(selected_cnt==M)
            ans = min(ans, chickent_dist(selected));
    }
}

int main() {

    scanf("%d%d", &N, &M);
    ans = 0x7fffffff;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++) {
            scanf("%d", &map[i][j]);
            if(map[i][j]==1) {
                home[home_cnt].x = j;
                home[home_cnt].y = i;
                home_cnt++;
            }
            else if(map[i][j]==2) {
                chicken[chicken_cnt].x = j;
                chicken[chicken_cnt].y = i;
                chicken_cnt++;
            }
        }
    }
    solve();
    printf("%d", ans);
}