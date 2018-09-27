#include <stdio.h>

#define MOD 1000000007
#define MAX 300005

using namespace std;

int tc, t;
int N, M;
int arr[MAX];

int main() {

//    FILE *fp = freopen("../data/battle.input", "r", stdin);
//    if(!fp)
//        perror("freopen error");

    scanf("%d", &tc);
    t = 0;
    while(t++ < tc) {

        scanf("%d%d", &N, &M);

        char buf[N+1];
        scanf("%s", buf);
        for(int i=0; i<N; i++) arr[i+1] = buf[i]-'0';

        int now = 0, cnt = 0;
        for(int i=1; i<N+1; i++) {
            now = 10*now+arr[i];
            now %= M;
            if(now==0)
                cnt++;
        }

        int ans = 1;
        while(cnt-->1) ans = (ans*2)%MOD;

        printf("#%d ", t);
        if(now>0) printf("%d\n", 0);
        else      printf("%d\n", ans);

        /**
         *  dynamic programming approach. O(N^2).
         *  dp[i] = arr[i~i]?dp[i+1]+arr[i~i+1]?dp[i+2]...
         *  each i, it takes O(N).
         */
//        for(int i=0; i<N+2; i++) dp[i] = 0;
//        dp[N] = arr[N]%M? 0:1;
//        dp[N+1] = 1; // marginal case for arr[i~N]%M.
//        for(int i=N-1; i>=1; i--) {
//            int tmp = 0;
//            for(int j=0; i+j<=N; j++) {
//                tmp = (10*tmp+arr[i+j])%M;
//                dp[i] += ((tmp? 0:1)*dp[i+j+1])%MOD;
//            }
//        }

//        printf("#%d %d\n", t, dp[1]);
    }

    return 0;
}