#include <iostream>

using namespace std;

int tc, t;
int N;
int P[16][16];

bool DEBUG = false;

double cache[16][65537];

double solve(int index, int done) {

    if(index == N)
        return 1;

    if(cache[index][done] != -1)
        return cache[index][done];

    double p = 0;
    for(int i=0; i<N; i++) {
        if(((1<<i) & done) == 0) {
            double dd = ((double)P[index][i]/100) * solve(index+1, done|(1<<i));
            p = max(p, dd);
        }
    }

    return cache[index][done] = p;
}

int main() {

//    FILE *fp = freopen("../data/1865.input", "r", stdin);
//    if(!fp)
//        perror("freopen error");

    scanf("%d", &tc);
    t = 0;
    while(t++ < tc) {

        scanf("%d", &N);
        for(int i=0; i<N; i++)
            for(int j=0; j<N; j++)
                scanf("%d", &P[i][j]);

        for(int i=0; i<16; i++)
            for(int j=0; j<65537; j++)
                cache[i][j] = -1;

//        for(int i=0; i<N; i++)
//            for(int j=0; j<N; j++)
//                cout << P[i][j] << " ";

        printf("#%d %.6f\n", t, 100*solve(0, 0));
    }

    return 0;
}