#include <stdio.h>
using namespace std;

/**
 * recursive approach
 */
/*
int N;
int A[1001], dp[1001];
int max(int a, int b) { return a>b? a:b; }
int lis(int now) {
    if(dp[now]!=-1) return dp[now];
    int ans = 0;
    for(int i=now+1; i<N+1; i++)
        if(A[i]>A[now])
            ans = max(ans, lis(i));
    return dp[now] = ans+(now?1:0);
}
int main() {
    scanf("%d", &N);
    A[0] = -1;
    for(int i=1; i<N+1; i++) scanf("%d", &A[i]);
    for(int i=0; i<N+1; i++) dp[i] = -1;
    printf("%d", lis(0));
    return 0;
}
*/

/**
 * iterative approach
 * gradually increase size of sub-problem i=0~N-1.
 * dp[i]: length of lis[0...i].
 */
int N;
int A[1001], dp[1001];
int main() {
    scanf("%d", &N);
    for(int i=0; i<N; i++) scanf("%d", &A[i]);
    int ans = 0;
    for(int i=0; i<N; i++) {
        dp[i] = 1;
        for(int j=0; j<i; j++)
            if(A[i]>A[j]&&dp[i]<dp[j]+1)
                dp[i] = dp[j]+1;
        ans = ans<dp[i]? dp[i]:ans;
    }
    printf("%d", ans);
    return 0;
}
