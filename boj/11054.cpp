#include <stdio.h>
using namespace std;
int N;
int A[1001], dp1[1001], dp2[1001];
int main() {
    scanf("%d", &N);
    for(int i=0; i<N; i++) scanf("%d", &A[i]);
    for(int i=0; i<N; i++) {
        dp1[i] = 1;
        for(int j=0; j<i; j++)
            if(A[i]>A[j]&&dp1[i]<dp1[j]+1)
                dp1[i] = dp1[j]+1;
    }
    // separating loop is more efficient by cache locality.
    for(int i=N-1; i>=0; i--) {
        dp2[i] = 1;
        for(int j=N-1; j>i; j--)
            if(A[i]>A[j]&&dp2[i]<dp2[j]+1)
                dp2[i] = dp2[j]+1;
    }
    int ans = 0;
    for(int i=0; i<N; i++)
        ans = ans<(dp1[i]+dp2[i]-1)? (dp1[i]+dp2[i]-1):ans;
    printf("%d", ans);
    return 0;
}

