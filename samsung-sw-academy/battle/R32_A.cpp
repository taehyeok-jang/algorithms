#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;

int tc, t;
int N, S, j;
int A[101];

int main() {

    scanf("%d", &tc);
    while(t++ < tc) {

        memset(A, 0, sizeof(A));

        scanf("%d%d", &N, &S);
        for(int i=0; i<S; i++) {
            scanf("%d", &j);
            A[j] = 1;
        }
        printf("#%d", t);
        for(int i=1; i<N+1; i++)
            if(!A[i])
                printf(" %d", i);
        printf("\n");
    }

    return 0;
}

