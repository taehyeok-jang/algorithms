#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;

int tc, t;
int N;
int A[1002];
int cache[1002];

bool DEBUG = false;

int solve(int index) {
    if(index == N+1) return 0;
    if(cache[index] != -1) return cache[index];
    int m = 0;
    for(int i=index; i<N+1; i++)
        if(A[i]>=A[index-1])
            m = max(m, 1+solve(i+1));
    return cache[index] = m;
}

int main() {

//    FILE *fp = freopen("../data/3501.input", "r", stdin);
//    if(!fp)
//        perror("freopen error");

    scanf("%d", &tc);
    t = 0;
    while(t++ < tc) {
        scanf("%d", &N);
        memset(cache, -1, sizeof(int)*1002);
        A[0] = -1;
        for(int i=1; i<N+1; i++) scanf("%d", &A[i]);
        printf("#%d %d\n", t, solve(1));
    }
    return 0;
}
