#include <stdio.h>
#define MOD 11
typedef long long ll;
ll N, K, M;
ll f[2005], dp[2005];

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
 * Lucas & Fermat.
 * n, r: non-negative integer, p: prime.
 * @@ trouble shootin! if p is not prime, facto[i] must be 0.(i<p)
 * nCr mod(p) = pi(niCri)mod(p) = (nkCrk*....*n0Cr0)mod(p)
 *
 * where ni, ri are remainings of n%p, r%p.
 * time: O(p * log p(n)), space: O(p).
 */
int lucas_fermat_combination(ll n, ll r, int p) {
    if(r==0) return 1;
    for(int i=0;i<p+1;i++) f[i] = 1;
    for(int i=1;i<p;i++) f[i] = (f[i-1]*i)%p;
    int ans = 1;
    while(n&&r) {
        ll ni = n%p, ri = r%p;
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
int lucas_combination(ll n, ll r, int p) {
    if(r==0) return 1;
    int ans = 1;
    while(n&&r) {
        ll ni = n%p, ri = r%p;
        if(ni<ri) {
            ans = 0;
            break;
        }
        ans = (ans*iter_combination(ni, ri, p))%p;
        n /= p, r /= p;
    }
    return ans;
}

int main() {

    scanf("%lld%lld%lld", &N, &K, &M);
//    printf("lucas-fermat: %d\n", lucas_fermat_combination(N, K, M));
//    printf("lucas: %d\n", lucas_combination(N, K, M));
//    printf("iter: %d\n", iter_combination(N, K, M));
    printf("%d", lucas_fermat_combination(N, K, M));
    return 0;
}