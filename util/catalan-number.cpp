#define MAX 100000 // 10^5.
#define MOD 1000000007
typedef long long ll;
/**
 * def.
 * https://en.wikipedia.org/wiki/Catalan_number
 *
 * C(n) = sigma(i=0~n-1) C(i)*c(n-1-i)
 *
 * C(n)
 * <=> align n parentheses in fine order.
 *
 * <=> align binary tree which has n+1 leaf node.
 *
 * <=> align binary operation which has n+1 node.
 *
 * <=> a convex polygon with n + 2 sides can be cut into triangles
 * by connecting vertices with non-crossing line segments
 * (a form of polygon triangulation). The number of triangles formed is n and
 * the number of different ways that this can be achieved is Cn.
 *
 *
 * application.
 * http://jjycjnmath.tistory.com/139
 * http://bowbowbow.tistory.com/23
 */
int dp[MAX];

int iter_combination(int n, int r, int mod) {
    dp[0] = 1;
    for(int i=0; i<n; i++) {
        dp[i+1] = 1;
        for(int j=i; j>0; j--)
            dp[j] = (dp[j-1]+dp[j])%mod;
    }
    return dp[r];
}

int catalan_number(int n) {

    return iter_combination(2*n, n, MOD)-iter_combination(2*n, n+1, MOD);
}