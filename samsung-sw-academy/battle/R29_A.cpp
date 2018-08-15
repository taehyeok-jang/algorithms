#include <iostream>
#include <vector>

using namespace std;

int tc, t;
int N, L;
int T[20], K[20];

int cache[20][10001];

bool DEBUG = false;

int solve(int index, int cal) {

    if(index == N)
        return 0;
    if(cache[index][cal] != -1)
        return cache[index][cal];

    int p = 0;
    p = max(p, solve(index+1, cal));
    if(cal+K[index]<=L)
        p = max(p, T[index]+solve(index+1, cal+K[index]));

    return cache[index][cal] = p;
}

int main() {

//    FILE *fp = freopen("../data/battle.input", "r", stdin);
//    if(!fp)
//        perror("freopen error");

    scanf("%d", &tc);
    t = 0;
    while(t++ < tc) {

        scanf("%d%d", &N, &L);
        for(int i=0; i<N; i++)
            scanf("%d%d", &T[i], &K[i]);

        for(int i=0; i<N; i++)
            for(int j=0; j<L+1; j++)
                cache[i][j] = -1;

        printf("#%d %d\n", t, solve(0, 0));
    }

    return 0;
}
