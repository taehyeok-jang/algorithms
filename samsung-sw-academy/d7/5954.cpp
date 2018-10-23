/**
 * ref. http://cerc.tcs.uj.edu.pl/2012/
 * this code implemented based on solution.
 */
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <random>
#include <ctime>
using namespace std;
#define MAX 200005
int tc, t, n, m;
int a[MAX], vals[MAX];
int last[MAX], prv[MAX], nxt[MAX];
//
///**
// * a: the number of function calls and iterations.
// * b: only the number of function calls.
// */
//int a1 = 0, b1 = 0;
//int a2 = 0, b2 = 0;
//int a3 = 0, b3 = 0;

/**
 * @@ performance profiling.
 * f3 >> f3 > f1 >= f2
 *
 * 시간 복잡도가 감이 잘 안 와서 몇개를 시도해봤음.
 * f1. naive solution
 * f2. select function as biased as each partition is.
 * f3. f2+jump.
 * f4. from mid(=(l+r)/2), propagate to the margin += alternatively.
 *
 * 1. time complexity seriously depend on data distribution.
 * 2. f3 always performed best.
 * 3. unlike what we expected it to be observed, f1 performs better than f2.
 *
 * ref.
 * http://khsoo01.tistory.com/category/Problem%20Solving/문제%20풀이
 */

bool f1(int l, int r) {
    a1++, b1++;
    if(l>=r) return 0;
    for(int i=l; i<r; i++) {
        a1++;
        int mid = i;
        if(prv[mid]<l&&nxt[mid]>r)
            return f1(l, mid-1)||f1(mid+1, r);
    }
    return 1;
}
bool f2(int l, int r) {
    a2++, b2++;
    if(l>=r) return 0;
    for(int i=l, j=r; i<=j; i++, j--) {
        a2++;
        if(prv[i]<l&&nxt[i]>r)
            return f2(l, i-1)||f2(i+1, r);
        if(prv[j]<l&&nxt[j]>r)
            return f2(l, j-1)||f2(j+1, r);
    }
    return 1;
}

bool is_boring(int l, int r) {
//    TODO @@ optimization. jump 2 blocks.
//    if(l>=r) return 0;
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

    srand(time(NULL));
    int size = 10000;
    for(int i=0; i<size; i++)
        a[i] = rand()%size+1;
    for(int i=0; i<size; i++)
        printf("%d ", a[i]);
//    scanf("%d", &tc);
    tc = 1;
    t = 0;
    while(t++<tc) {
//        scanf("%d", &n);
        n = size;
        for(int i=0; i<n; i++) {
//            scanf("%d", &a[i]);
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
        printf("#%d %d\n", t, (is_boring(0, n-1)? 0:1));
    }
    return 0;
}

