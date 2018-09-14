#include <stdio.h>
using namespace std;

int tc, t;
int cost[4], plan[13];
int MIN;

void dfs(int c, int m) {

    if(m>=13) {
        MIN = c;
        return;
    }
    if(c+plan[m]*cost[0]<MIN) dfs(c+plan[m]*cost[0], m+1);
    if(c+cost[1]<MIN) dfs(c+cost[1], m+1);
    if(c+cost[2]<MIN) dfs(c+cost[2], m+3);
}

int main() {

    scanf("%d", &tc);
    t = 0;
    while(t++ < tc) {

        for(int i=0; i<4; i++) scanf("%d", &cost[i]);
        for(int i=1; i<13; i++) scanf("%d", &plan[i]);

        MIN = cost[3];
        dfs(0, 1);
        printf("#%d %d\n", t, MIN);
    }

    return 0;
}
