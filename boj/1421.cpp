#include <stdio.h>
using namespace std;

int N, C, W;
int A[1001];

int main() {

    scanf("%d%d%d", &N, &C, &W);
    int m = -1;
    for(int i=0; i<N; i++) {
        scanf("%d", &A[i]);
        m = m>A[i]? m:A[i];
    }

    int ans = -1, tmp;
    int a, b;
    for(int l=1; l<m+1; l++) {
        tmp = 0;
        for(int i=0; i<N; i++) {
            if(l>A[i]) continue;
            a = A[i]-A[i]%l;
            b = (A[i]%l>0)? A[i]/l:A[i]/l-1;
            tmp += a*W-b*C>0? a*W-b*C:0;
        }
        ans = ans>tmp? ans:tmp;
    }

    printf("%d", ans>0? ans:0);
    return 0;
}
