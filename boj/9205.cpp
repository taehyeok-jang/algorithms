#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

int tc, t;
int N;
struct p {
    int x, y;
} pp[102];
bool visited[102];

int main() {

    scanf("%d", &tc);
    t = 0;
    while(t++ < tc) {

        scanf("%d", &N);
        for(int i=0; i<N+2; i++) scanf("%d%d", &pp[i].x, &pp[i].y);
        for(int i=0; i<102; i++) visited[i] = 0;

        bool solve = false;
        queue<p> q;
        q.push(p({pp[0].x, pp[0].y})); visited[0] = 1;
        while(!q.empty()) {

            p a = q.front(); q.pop();
            if(a.x==pp[N+1].x&&a.y==pp[N+1].y) {
                solve = 1;
                break;
            }

            for(int i=1; i<N+2; i++) {
                if(visited[i]) continue;
                if(abs(a.x-pp[i].x)+abs(a.y-pp[i].y)<=1000) {
                    q.push(p({pp[i].x, pp[i].y}));
                    visited[i] = 1;
                }
            }
        }

        puts(solve? "happy":"sad");
    }

    return 0;
}
