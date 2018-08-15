#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;

int tc, t;
int N, K;
int V[101], C[101];
int cache[101][10001];

bool DEBUG = false;

int solve(int index, int w) {

    if(index == N)
        return 0;
    if(cache[index][w] != -1)
        return cache[index][w];

    int m = 0;
    m = max(m, solve(index+1, w));
    if(w+V[index]<=K) m = max(m, C[index]+solve(index+1, w+V[index]));

    return cache[index][w] = m;
}

int main() {

//    FILE *fp = freopen("../data/3501.input", "r", stdin);
//    if(!fp)
//        perror("freopen error");

    scanf("%d", &tc);
    t = 0;
    while(t++ < tc) {

        scanf("%d%d", &N, &K);
        for(int i=0; i<N; i++) scanf("%d%d", &V[i], &C[i]);
        for(int i=0; i<101; i++) for(int j=0; j<10001; j++) cache[i][j] = -1;

        printf("#%d %d\n", t, solve(0, 0));
    }

    return 0;
}
