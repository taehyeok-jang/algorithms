#include <stdio.h>
#include <cstring>

#define MAX 10005
using namespace std;
int N, cache[MAX], k;

int main()
{
    printf("%d", &N);
    for(int i=0; i<N+1; i++) cache[i] = 87654321;
    for(int i=1;i<n;i++){
        printf("%d", &k);
        for(int j=0;j<=i;j++)
            dp[j]=min(dp[j],dp[i-j]+nn);
    }
    cout<<dp[n/2];
    return 0;
}