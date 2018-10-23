#include <stdio.h>
using namespace std;
int N;
int A[1001], dp[1001];
int main() {
    scanf("%d", &N);
    for(int i=0; i<N; i++) scanf("%d", &A[i]);
    int ans = 0;
    for(int i=0; i<N; i++) {
        dp[i] = 1;
        for(int j=0; j<i; j++)
            if(A[i]<A[j]&&dp[i]<dp[j]+1)
                dp[i] = dp[j]+1;
        ans = ans<dp[i]? dp[i]:ans;
    }
    printf("%d", ans);
    return 0;
}