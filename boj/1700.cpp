#include <cstdio>
#include <cstring>

int N, K;
int A[101], used[101], tmp[101];
using namespace std;
int main() {
    scanf("%d%d", &N, &K);
    for(int i=0; i<K; i++) scanf("%d", &A[i]);

    int m = 0, cnt = 0;
    for(int i=0; i<K; i++) {
        if(used[A[i]]) continue;
        if(m<N) { m++, used[A[i]] = 1; continue; }

        int idx;
        memset(tmp, 0, sizeof(tmp));
        for(int j=i+1; j<K; j++)
            if(used[A[j]]&&!tmp[A[j]]) {
                tmp[A[j]] = 1; idx=A[j];
            }
        for(int j=1; j<K+1; j++)
            if(used[j]&&!tmp[j]) {
                idx = j; break;
            }
        used[idx] = 0;
        used[A[i]] = 1;
        cnt++;
    }

    printf("%d", cnt);
    return 0;
}
