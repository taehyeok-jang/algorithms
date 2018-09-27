#include <stdio.h>
#include <algorithm>

int N, M;
int A[11], result[11];
bool check[11];

void dfs(int k) {

    if(k==M) {
        for(int i=0; i<M; i++)
            printf("%d ", result[i]);
        printf("\n");
        return;
    }

    for(int i=0; i<N; i++) {
        if(check[i]) continue;
        check[i] = 1;
        result[k] = A[i];
        dfs(k+1);
        check[i] = 0;
    }
}

int main() {

    scanf("%d%d", &N, &M);
    for(int i=0; i<N; i++)
        scanf("%d", &A[i]);

    std::sort(A, A+N);

    dfs(0);
    return 0;
}
