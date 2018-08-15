#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

int tc, t;
int N;
int map[51][51];
bool visited[51][51];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

bool DEBUG = false;

bool out_of_bound(int x, int y) { return x<0||x>=N||y<0||y>=N; }
struct p {
    int x, y, l;
    p(int a, int b, int c) { x=a, y=b, l=c; }
};

int main() {

//    FILE *fp = freopen("../data/3501.input", "r", stdin);
//    if(!fp)
//        perror("freopen error");

    scanf("%d", &tc);
    t = 0;
    while(t++ < tc) {

        scanf("%d", &N);
        char buf[51];
        for(int i=0; i<N; i++) {
            scanf("%s", buf);
            for(int j=0; j<N; j++)
                map[i][j] = (buf[j]-48);
        }
        memset(visited, 0, sizeof(bool)*51*51);

        int sum = 0;
        queue<p> q;
        q.push(p(N/2, N/2, 0));
        visited[N/2][N/2] = 1;
        while(!q.empty()) {
            p a = q.front(); q.pop();
            sum += map[a.x][a.y];
            if(a.l==N/2) continue;
            for(int d=0; d<4; d++) {
                if(out_of_bound(a.x+dx[d], a.y+dy[d])||visited[a.x+dx[d]][a.y+dy[d]])
                    continue;
                q.push(p(a.x+dx[d], a.y+dy[d], a.l+1));
                visited[a.x+dx[d]][a.y+dy[d]] = 1;
            }
        }
//        for(int i=0; i<N; i++) {
//            for(int j=0; j<N; j++)
//                cout << visited[i][j] << "";
//            cout << "\n";
//        }
        printf("#%d %d\n", t, sum);
    }

    return 0;
}
