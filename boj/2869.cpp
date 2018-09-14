#include <stdio.h>
using namespace std;

long long A, B, V;
int main() {

    scanf("%lld%lld%lld", &A, &B, &V);

    int ans = 0;
    int l, r, m;
    long long p;
    l = 0, r = 1e9;
    while(l<=r) {
        m = (l+r)/2;
        p = (A-B)*(m-1)+A;
        if(p==V) { ans = m; break; }
        if(p<V) l = m+1;
        else    ans = m, r = m-1;
    }
    printf("%d", ans);
    return 0;
}
