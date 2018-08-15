#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;

int tc, t;
int N, M;

bool DEBUG = false;

int pow(int n, int m) {
    if(m==0) return 1;
    return n*pow(n, m-1);
}

int main() {

//    FILE *fp = freopen("../data/1992.input", "r", stdin);
//    if(!fp)
//        perror("freopen error");

//    scanf("%d", &tc);
    tc = 10;
    t = 0;
    while(t++ < tc) {
        int k;
        scanf("%d", &k);
        scanf("%d%d", &N, &M);
        printf("#%d %d\n", t, pow(N, M));
    }

    return 0;
}
