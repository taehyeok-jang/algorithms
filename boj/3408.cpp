/**
 * ref. http://cerc.tcs.uj.edu.pl/2012/
 * this code implemented based on solution.
 */
#include <stdio.h>
#include <algorithm>
using namespace std;
#define MAX 200005
int tc, t, n, m;
int a[MAX], vals[MAX];
int last[MAX], prv[MAX], nxt[MAX];

bool is_boring(int l, int r) {
//    if(l>=r) return 0;
//    @@ optimization. jump 2 blocks.
//    for(int i=l, j=r; i<=j; i++, j--) {
//        if(prv[i]<l&&nxt[i]>r) {
//            if((i==l&&i+1<j)&&(nxt[i+1]>r)) return is_boring(i+2, r);
//            else return is_boring(l, i-1)||is_boring(i+1, r);
//        }
//        if(prv[j]<l&&nxt[j]>r) {
//            if((j==r&&j-1>i)&&(prv[j-1]<l)) return is_boring(l, j-2);
//            else return is_boring(l, j-1)||is_boring(j+1, r);
//        }
//    }
    if(l>=r) return 0;
    for(int i=0; i<(r-l+1); i++) {
        int mid = (l+r)/2+((i%2)? 1:-1)*(i+1)/2;
        if(prv[mid]<l&&nxt[mid]>r)
            return is_boring(l, mid-1)||is_boring(mid+1, r);
    }
    return 1;
}

int main() {

    scanf("%d", &tc);
    t = 0;
    while(t++<tc) {
        scanf("%d", &n);
        for(int i=0; i<n; i++) {
            scanf("%d", &a[i]);
            vals[i] = a[i];
        }
        sort(vals, vals+n);
        m = unique(vals, vals+n)-vals;
        for(int i=0; i<n; i++)
            a[i] = lower_bound(vals, vals+m, a[i])-vals;
        for(int i=0; i<n; i++)
            last[a[i]] = -1;
        for(int i=0; i<n; i++) {
            prv[i] = last[a[i]];
            last[a[i]] = i;
        }
        for(int i=0; i<n; i++)
            last[a[i]] = n;
        for(int i=n-1; i>=0; i--) {
            nxt[i] = last[a[i]];
            last[a[i]] = i;
        }
        printf("#%d %d\n", t, (is_boring(0, n-1)? "boring":"non-boring"));
    }
    return 0;
}

