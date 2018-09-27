#include <stdio.h>

int N, M;
char result[22];

void dfs(int d, int k) {

    if(k==M) {
        printf("%s\n", result);
        return;
    }

    for(int i=d; i<N+1; i++) {
        result[2*k] = i+'0';
        dfs(i, k+1);
    }
}

int main() {

    scanf("%d%d", &N, &M);
    for (int i=0; i<2*M; i++)
        result[i] = ' ';

    dfs(1, 0);
    return 0;
}
