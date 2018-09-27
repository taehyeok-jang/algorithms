#include <stdio.h>
#include <algorithm>

int N, M;
int A[11], result[11];

void dfs(int d, int k) {

    if(k==M) {
        for(int i=0; i<M; i++)
            printf("%d ", result[i]);
        printf("\n");
        return;
    }

    for(int i=d; i<N; i++) {
        result[k] = A[i];
        dfs(i+1, k+1);
    }
}

int main() {

    scanf("%d%d", &N, &M);
    for(int i=0; i<N; i++)
        scanf("%d", &A[i]);

    std::sort(A, A+N);

    dfs(0, 0);
    return 0;
}
