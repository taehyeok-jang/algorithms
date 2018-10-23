#include <stdio.h>
int N;
int A[1001], dp[1001], prv[1001];
int main() {
    scanf("%d", &N);
    for(int i=0; i<N; i++) scanf("%d", &A[i]);
    for(int i=0; i<N; i++) prv[i] = i;
    int ans = 0, last;
    for(int i=0; i<N; i++) {
        dp[i] = 1;
        for(int j=0; j<i; j++)
            if(A[i]>A[j]&&dp[i]<dp[j]+1)
                dp[i] = dp[j]+1, prv[i] = j;
        if(ans<dp[i])
            ans = dp[i], last = i;
    }
    printf("%d\n", ans);
    int cur = last; int i = 0;
    while(cur!=prv[cur]) dp[i++] = A[cur], cur = prv[cur];
    dp[i] = A[cur];
    for(int j=i; j>=0; j--)
        printf("%d ", dp[j]);
    return 0;
}