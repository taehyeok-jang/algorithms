#include <stdio.h>

int N, M;
char result[22];

void dfs(int i, int k) {

    if(i==N+2)
        return;
    if(k==M) {
        printf("%s", result);
        return;
    }

    result[2*k] = i+'0';
    dfs(i+1, k+1);
    if(i<N+1)
        dfs(i+1, k);
}

int main() {

    scanf("%d%d", &N, &M);
    for (int i=0; i<2*M; i++)
        result[i] = ' ';

    dfs(1, 0);
    return 0;
}
