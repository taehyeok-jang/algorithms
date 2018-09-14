#include <stdio.h>
#include <iostream>

using namespace std;

int N, M;
int t[100001];

int main() {

    scanf("%d%d", &N, &M);
    for(int i=0; i<N; i++) scanf("%d", &t[i]);

    long long ans = 1e18;
    long long s;
    long long l, r, m;
    l = 0, r = 1e18+1;
    while(l<=r) {
        m = (l+r)/2;
        s = 0;
        for(int i=0; i<N; i++) s += m/(long long)t[i];
        // find least m that satisfies s>=M.
        if(s>=M) ans = min(ans, m), r = m-1;
        else     l = m+1;
    }

    printf("%lld", ans);
    return 0;
}
