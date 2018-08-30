#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <list>

using namespace std;

#define MAX 100005
//#define DEBUG 1

int tc, t;
int N;
struct col {
    int a, b, c;
    bool operator < (const col &col2) const { return a < col2.a; }
} col[MAX];

int deleted[MAX];
list<int> pos[2][MAX];

int main() {

//    FILE *fp = freopen("../data/battle.input", "r", stdin);
//    if(!fp)
//        perror("freopen error");

    scanf("%d", &tc);
    t = 0;
    while(t++ < tc) {

        scanf("%d", &N);
        for(int i=1; i<N+1; i++) scanf("%d", &col[i].a);
        for(int i=1; i<N+1; i++) scanf("%d", &col[i].b);
        for(int i=1; i<N+1; i++) scanf("%d", &col[i].c);
        sort(col+1, col+N+1);

        for(int i=0; i<N+1; i++) deleted[i] = 0;
        for(int i=0; i<2; i++)
            for(int j=0; j<MAX; j++)
                pos[i][j].clear();

        for(int i=1; i<N+1; i++) { // col[i].b=j <-> PB[j]=i
            pos[0][col[i].b].push_back(i);
            pos[1][col[i].c].push_back(i);
        }

        int count = 0;
        queue<int> q;
        for(int i=1; i<N+1; i++)
            if(pos[0][i].size()==0) { count++, q.push(i), deleted[i] = 1; }
        for(int i=1; i<N+1; i++)
            if(pos[1][i].size()==0&&!deleted[i]) { count++, q.push(i), deleted[i] = 1; }

        int aa, bb, cc;
        while(!q.empty()) {

            // aa is column number. (1~N+1).
            aa = q.front(); q.pop();
            bb = col[aa].b, cc = col[aa].c;

            if(pos[0][bb].size()==1) {
                pos[0][bb].pop_back();
                if(!deleted[bb]) {
                    count++;
                    q.push(bb), deleted[bb] = 1;
                }
            }
            else {
                for(auto it=pos[0][bb].begin(); it!=pos[0][bb].end();)
                    if(*it==aa) { it = pos[0][bb].erase(it); }
                    else it++;
            }

            if(pos[1][cc].size()==1) {
                pos[1][cc].pop_back();
                if(!deleted[cc]) {
                    count++;
                    q.push(cc), deleted[cc] = 1;
                }
            }
            else {
                for(auto it=pos[1][cc].begin(); it!=pos[1][cc].end();)
                    if(*it==aa) { it = pos[1][cc].erase(it); }
                    else it++;
            }
        }

        printf("#%d %d\n", t, count);
    }

    return 0;
}
