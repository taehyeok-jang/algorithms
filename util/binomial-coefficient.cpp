#include <stdio.h>
#define MOD 1000000007
typedef long long ll;
int N, K, M;
int cache[2001][2001];
int f[10001];
int dp[1000000]; // 10^6.

/**
 * type integer or long long. dependant on given conditions.
 */
int pow(int n, int r, int p);
int fermat_combination(int n, int r, int p);
int lucas_fermat_combination(int n, int r, int p);
int lucas_combination(int n, int r, int p);
int iter_combination(int n, int r, int p);
int recur_combination(int n, int r, int p);
int brute_force_combination(int n, int r);

/**
 * power.
 * time: O(log N), space: O(1).
 * same as generating binary num from decimal.
 * x = x^1, x^2, x^4, x^8 -> x = x^(2^0), x^(2^1), x^(2^2), x^(2^3)...
 *
 * @@ watch-out!
 * cuz p is big number, x, y can easily be over integer's max-value.
 * so we should get parameter x, y as long long.
 */
int pow(ll x, ll y, int p) {
    long long ans = 1;
    while(y>0) {
        if(y%2>0) {
            ans *= x;
            ans %= p;
        }
        x *= x;
        x %= p;
        y /= 2;
    }
    return ans;
}
/**
 * Fermat's little Th.
 * n, r: non-negative integer, p: prime.
 * @@ trouble shootin! if p is not prime, facto[i] must be 0.(i<p)
 * use modular inverse.
 * a^p = a (mod p) -> a^(p-2) = a^-1 (mod p).
 * nCr = (n! mod p) * {(r! mod p)*(n-r)! mod p}^(p-2) mod p.
 * time: O(N), space: O(1).
 */
int fermat_combination(ll n, ll r, int p) {

    ll t1 = 1, t2 = 1;
    r = r<n-r? r:n-r;
    for(ll i=1; i<=r; i++) {
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
/**
 * Lucas & Fermat.
 * n, r: non-negative integer, p: prime.
 * @@ trouble shootin! if p is not prime, facto[i] must be 0.(i<p)
 * nCr mod(p) = pi(niCri)mod(p) = (nkCrk*....*n0Cr0)mod(p)
 * -> nCr = (n! mod p) * {(r! mod p)*(n-r)! mod p}^(p-2) mod p.
 *
 * where ni, ri are remainings of n%p, r%p.
 * time: O(p * log p(n)), space: O(p).
 */
int lucas_fermat_combination(int n, int r, int p) {
    if(r==0) return 1;
    for(int i=0;i<p+1;i++) f[i] = 1;
    for(int i=1;i<p;i++) f[i] = (f[i-1]*i)%p;
//    for(int i=1;i<p+1;i++) printf("%d: %d\n", i, f[i]);
    int ans = 1;
    while(n&&r) {
        int ni = n%p, ri = r%p;
        if(ni<ri) {
            ans = 0;
            break; // TODO why?
        }
        ans = (ans*f[ni])%p;
        for(int i=0; i<p-2; i++)
            ans = ((ans*f[ri])%p*f[ni-ri])%p;
        n /= p, r /= p;
    }
    return ans;
}
/**
 * Lucas Th.
 * n, r: non-negative integer, p: prime.
 * nCr mod(p) = pi(niCri)mod(p) = (nkCrk*....*n0Cr0)mod(p)
 * where ni, ri are remainings of n%p, r%p.
 * time: O(p2 * log p(n)), space: O(p).
 */
int lucas_combination(int n, int r, int p) {
    if(r==0) return 1;
    /*
     * iterative impl.
     */
    int ans = 1;
    while(n&&r) {
        int ni = n%p, ri = r%p;
        if(ni<ri) {
            ans = 0;
            break; // TODO why?
        }
        ans = (ans*iter_combination(ni, ri, p))%p;
        n /= p, r /= p;
    }
    return ans;
    /*
     * recursive impl.
     */
//    int ni = n%p, ri = r%p;
//    return (lucas_combination(n/p, r/p, p)
//            *iter_combination(ni, ri, p))%p;
}
/**
 * iterative approach
 * (a+b)%m = (a%m+b%m)%m.
 * time: O(NR), space: O(N).
 */
int iter_combination(int n, int r, int mod) {
    dp[0] = 1;
    for(int i=0; i<n; i++) {
        dp[i+1] = 1;
        for(int j=i; j>0; j--)
            dp[j] = (dp[j-1]+dp[j])%mod;
    }
    return dp[r];
}
/**
 * recursive approach
 * can be memoized.
 * (a+b)%m = (a%m+b%m)%m.
 * time: O(NR), space: O(NR)+additional subroutine call stack.
 */
int recur_combination(int n, int r, int mod) {
//    for(int i=0; i<2001; i++)
//        for(int j=0; j<2001; j++)
//            cache[i][j] = -1;
    if(r==0||n==r) return 1;
    if(cache[n][r]!=-1) return cache[n][r];
    return cache[n][r] = (recur_combination(n-1, r, mod)+recur_combination(n-1, r-1, mod))%mod;
}
/**
 * brute-force approach
 */
int brute_force_combination(int n, int r) {
    int sum = 1, m = r<n-r? r:n-r, k = 1;
    while(m--) sum = sum*(n--)/(k++); // cannot be operated by modula.
    return sum;
}

int main() {

    scanf("%d%d%d", &N, &K, &M);
    printf("lucas-fermat: %d\n", lucas_fermat_combination(N, K, M));
    printf("lucas: %d\n", lucas_combination(N, K, M));
    printf("iter: %d\n", iter_combination(N, K, M));
    printf("recur: %d\n", recur_combination(N, K, M));
    return 0;
}