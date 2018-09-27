#include <stdio.h>
int N, K;
/**
 * recursive approach
 * can be memoized.
 */
int recur_combination(int n, int r) {
    if(r==0||n==r) return 1;
//    if(cache[n][r]!=-1) return cache[n][r];
    return recur_combination(n-1, r)+recur_combination(n-1, r-1);
}
/**
 * iterative approach
 */
int iter_combination(int n, int r) {
    int sum = 1, m = r<n-r? r:n-r, k = 1;
    while(m--) sum = sum*(n--)/(k++);
    return sum;
}

int main() {
    scanf("%d%d", &N, &K);
    printf("%d", iter_combination(N, K));
//    printf("%d", recur_combination(N, K));
    return 0;
}

