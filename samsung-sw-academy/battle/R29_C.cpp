#include <iostream>
#include <vector>

using namespace std;

/**
 * Not solved... and no one solved this problem due to time complexity.
 */

int tc, t;
long long N, K;

int cache[20][10001];

long long f1(long long n, long long k) {

    if(k>2*n||k<0) return 0;
    if(n == 0) { if(k == 0)  return 1; else return 0; }
    if(n == 1 || k == 0) return 1;

//    if(cache[n][k] != -1)
//        return cache[n][k];
    return /*cache[n][k] = */f1(n-1, k)+f1(n-1, k-1)+f1(n-1, k-2);
}

long long f2(long long n, long long k) {

//    printf("%d, %d\n", n, k);

    // TODO
    // cache for small range.
    if(k>2*n||k<0)
        return 0;
    if(n == 0) {
        if(k == 0)  return 1;
        else        return 0;
    }
    if(n == 1 || k == 0)
        return 1;

    long long s = 0;
    if(n%2 == 0) {
        for(int l=0; l<=k; l++)
            s += f2(n/2, l)*f2(n/2, k-l);
    }
    else {
        // sol 1.
//        for(int l=0; l<=k; l++)
//            s += f2((n-1)/2, l)*f2((n+1)/2, k-l);
        // sol 2.
        for(int l=0; l<=k; l++) {
            s += f2((n-1)/2, l)*f2((n-1)/2, k-l);
            s += f2((n-1)/2, l)*f2((n-1)/2, k-1-l);
            s += f2((n-1)/2, l)*f2((n-1)/2, k-2-l);
        }
    }
    return s;
}

int main() {

//    FILE *fp = freopen("../data/battle.input", "r", stdin);
//    if(!fp)
//        perror("freopen error");

    scanf("%d", &tc);
    t = 0;
    while(t++ < tc) {

        scanf("%lld%lld", &N, &K);
//        for(int i=0; i<N; i++)
//            for(int j=0; j<L+1; j++)
//                cache[i][j] = -1;

//        printf("#%d %d\n", t, f2(N, K)%3);
        int tt = 10;
        for(int i=0; i<10; i++) {
            cout << f2(i, i) << " ";
//            for(int j=0; j<=2*i; j++) {
//                cout << f2(i, 2*i-j) << " ";
//            }
            cout << "\n";
        }

        printf("#%d %lld %lld\n", t, f1(N, K), f2(N, K));
    }

    return 0;
}
