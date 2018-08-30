#include <stdio.h>
#include <cstring>
#include <queue>

using namespace std;

int F, S, G, U, D;
int q[1000001], f, r, s;
bool visited[1000001];
int tt, ans;

//#define DEBUG 1
#ifdef DEBUG
#endif

int main() {

    scanf("%d%d%d%d%d", &F, &S, &G, &U, &D);
    memset(visited, 0, sizeof(visited));

    f = r = 0, tt = ans = 0;
    q[r++] = S;
    visited[S] = 1;
    while(f!=r) {
        s = r-f;
        while(s--) {
            int k = q[f++];
            if(k==G) { ans = 1; break; }
            if(k+U<=F&&!visited[k+U]) { q[r++] = k+U; visited[k+U] = 1; }
            if(k-D>=0&&!visited[k-D]) { q[r++] = k-D; visited[k-D] = 1; }
        }
        if(ans) break;
        tt++;
    }
    if(ans) printf("%d", tt);
    else    printf("use the stairs");
    return 0;
}
