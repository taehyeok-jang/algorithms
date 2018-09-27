#include <stdio.h>
#define MOD 10007
int N, K;
//int cache[2001][2001];
int dp[2002];
/**
 * recursive approach
 * can be memoized.
 * (a+b)%m = (a%m+b%m)%m.
 */
//int recur_combination(int n, int r) {
//    if(r==0||n==r) return 1;
//    if(cache[n][r]!=0) return cache[n][r];
//    return cache[n][r] = (recur_combination(n-1, r)+recur_combination(n-1, r-1))%MOD;
//}
/**
 * iterative approach
 * (a+b)%m = (a%m+b%m)%m.
 */
int iter_combination(int n, int r) {
    dp[0] = 1;
    for(int i=0; i<n; i++) {
        dp[i+1] = 1;
        for(int j=i; j>0; j--)
            dp[j] = (dp[j]%MOD+dp[j-1]%MOD)%MOD;
//          dp[j] = (dp[j-1]+dp[j])%MOD;
    }
    return dp[r];
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
    scanf("%d%d", &N, &K);
    printf("%d", iter_combination(N, K));
//    printf("%d", recur_combination(N, K));
    return 0;
}