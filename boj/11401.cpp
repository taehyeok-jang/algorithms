#include <stdio.h>
typedef long long ll;
typedef unsigned long long ull;
int N, K;

int pow(ll x, ll y, int p) {
    ll ans = 1;
    while(y>0) {
        if(y%2!=0) {
            ans *= x;
            ans %= p;
        }
        x *= x;
        x %= p;
        y /= 2;
    }
    return ans%p;
}
int fermat_combination(ull n, ull r, int p) {

    ull t1 = 1, t2 = 1;
    r = r<n-r? r:n-r;
    for(ull i=1; i<=r; i++) {
        t1 = (t1*(n-i+1))%p;
        t2 = (t2*i)%p;
    }
//    for(ll i=1; i<=n; i++) {
//        t1 *= i;
//        t1 %= p;
//    }
//    for(ll i=1; i<=r; i++) {
//        t2 *= i;
//        t2 %= p;
//    }
//    for(ll i=1; i<=n-r; i++) {
//        t2 *= i;
//        t2 %= p;
//    }
    return (t1*pow(t2, p-2, p))%p;
}

int main() {

    scanf("%d%d", &N, &K);

    pow(N, K, 1000000007);

//    printf("%d", fermat_combination(N, K, 1000000007));
    return 0;
}