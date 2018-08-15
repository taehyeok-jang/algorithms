#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;

int tc, t;
int N, K;
int A[30];
int cache[30][1010];
bool DEBUG = false;

int solve(int index, int s) {

    if(s == K) return 1;
    if(index == N) return 0;
    if(cache[index][s] != -1) return cache[index][s];
    int ss = 0;
    if(s+A[index]<=K) ss += solve(index+1, s+A[index]);
    ss += solve(index+1, s);

    return cache[index][s] = ss;
}

int main() {

//    FILE *fp = freopen("../data/3501.input", "r", stdin);
//    if(!fp)
//        perror("freopen error");

    scanf("%d", &tc);
    t = 0;
    while(t++ < tc) {

        scanf("%d%d", &N, &K);
        for(int i=0; i<N; i++) scanf("%d", &A[i]);
        memset(cache, -1, sizeof(int)*30*1010);

        printf("#%d %d\n", t, solve(0, 0));
    }

    return 0;
}
