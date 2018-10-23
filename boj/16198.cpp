#include <iostream>
using namespace std;
int N;
int W[11], dp[(1<<10)+1];
int max(int a, int b) { return a>b? a:b; }
int solve(int cur) { // l, r: 0~9.
    if(dp[cur]!=-1) return dp[cur];
    int cnt = 0;
    for(int i=0; i<N; i++)
        if((1<<i)&cur) cnt++;
    if(cnt==2) return 0;

    int ans = 0;
    int wl, wr;
    for(int i=0; i<N; i++) { // i: delete target.
        if(((1<<i)&cur)==0) continue;
        wl = -1, wr = -1;
        for(int j=0; j<i; j++)
            if((1<<j)&cur) wl = W[j];
        for(int j=N-1; j>i; j--)
            if((1<<j)&cur) wr = W[j];
        if(wl==-1||wr==-1)
            continue;
        ans = max(ans, wl*wr+solve(cur-(1<<i)));
    }
    return dp[cur] = ans;
}

int main() {
    cin >> N;
    for(int i=0; i<(1<<10)+1; i++)
        dp[i] = -1;
    for(int i=0; i<N; i++)
        cin >> W[i];
    cout << solve((1<<N)-1);
    return 0;
}
