#include <stdio.h>
#include <set>
using namespace std;
typedef long long ll;
int tc, t;
int N;
int money[21][21];
ll debt[21];
set<int> survivor;

char dp[(1<<20)+1];

// 0: no survivor.
// 1: there exists survivors.
// alive: represent alive by bit-masking. initial value: 11...11(Nth).
int solve(int alive) {

    if(dp[alive]!=-1) return dp[alive];
    if(alive==0) return 0;

    int count = 0, idx;
    for(int i=1; i<N+1; i++)
        if(((1<<(i-1))&alive)) count++, idx = i;

    if(count==1) {
        survivor.insert(idx);
        return dp[alive] = 1;
    }

    for(int i=1; i<N+1; i++) {
        if(((1<<(i-1))&alive)==0) continue;
        ll m = 0;
        for(int j=1; j<N+1; j++)
            if(((1<<(j-1))&alive)) m += money[i][j];
        debt[i] = m;
    }

    ll aux[21];
    for(int i=1; i<N+1; i++)
        aux[i] = debt[i];

    int ans = 0, original = alive;
    for(int i=1; i<N+1; i++) {
        if(((1<<(i-1))&alive)==0||debt[i]<=0) continue;
        alive -= (1<<(i-1));

        ans |= solve(alive);
        // back-track
        alive = original;
        for(int j=1; j<N+1; j++)
            debt[j] = aux[j];
    }
    return dp[alive] = ans;
}

int main() {

//    FILE *fp = freopen("../data/3501.input", "r", stdin);
//    if(!fp)
//        perror("freopen error");

    scanf("%d", &tc);
    t = 0;
    while(t++ < tc) {

        scanf("%d", &N);
        for(int i=1; i<N+1; i++)
            for(int j=1; j<N+1; j++)
                scanf("%d", &money[i][j]);
        for(int i=1; i<N+1; i++) debt[i] = 0;
        for(int i=0; i<(1<<N)+1; i++) dp[i] = -1;
        survivor.clear();

        solve((1<<N)-1);

        printf("#%d %d", t, (int)survivor.size());
        for(auto it=survivor.begin(); it!=survivor.end(); it++)
            printf(" %d", *it);
        printf("\n");
    }

    return 0;
}
