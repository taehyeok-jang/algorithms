#include <iostream>
#include <cstring>
using namespace std;
int N;
int dp[100001];

int main() {

    scanf("%d", &N);
    for(int i=1; i<=N; i++)
        for(int j=1; j*j<=i; j++)
            if(dp[i]==0||dp[i]>dp[i-j*j]+1)
                dp[i] = dp[i-j*j]+1;
    printf("%d", dp[N]);
    return 0;
}
