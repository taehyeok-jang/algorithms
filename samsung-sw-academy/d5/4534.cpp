#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

#define MAX 100005
#define MOD 1000000007
#ifdef DEBUG
#endif

int tc, t;
int N;
long long cache[MAX][2];

struct node {
    vector<int> childs;
} nodes[MAX];

void prune(int parent, int k) {

    for(auto it=nodes[k].childs.begin(); it!=nodes[k].childs.end();) {
        if(*it==parent) it = nodes[k].childs.erase(it);
        else it++;
    }
    for(auto it=nodes[k].childs.begin(); it!=nodes[k].childs.end(); it++)
        prune(k, *it);
}

long long solve(int k, int c) {

    if(cache[k][c] != -1) return cache[k][c];
    if(nodes[k].childs.size()==0) return 1;

    long long ans = 1;
    for(int i=0; i<nodes[k].childs.size(); i++) {
        ans = ans*((c==0)? (solve(nodes[k].childs[i], 0)+solve(nodes[k].childs[i], 1))%MOD:
                        solve(nodes[k].childs[i], 0));
        ans %= MOD;
    }

    return cache[k][c] = ans%MOD;
}

int main() {

//    FILE *fp = freopen("../data/4534.input", "r", stdin);
//    if(!fp)
//        perror("freopen error");

    scanf("%d", &tc);
    t = 0;
    while(t++ < tc) {

        scanf("%d", &N);
        for(int i=1; i<N+1; i++) nodes[i].childs.clear();
        for(int i=1; i<N+1; i++) for(int j=0; j<2; j++) cache[i][j] = -1;

        int a, b;
        for(int i=0; i<N-1; i++) {
            scanf("%d%d", &a, &b);
            nodes[a].childs.push_back(b);
            nodes[b].childs.push_back(a);
        }
        prune(-1, 1);
        printf("#%d %lld\n", t, (solve(1, 0)+solve(1, 1))%MOD);
    }

    return 0;
}
