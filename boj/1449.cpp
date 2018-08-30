#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;

int tc, t;
int N, L;
int A[1001];

//#define DEBUG 1
#ifdef DEBUG
#endif

int main() {

    scanf("%d%d", &N, &L);
    for(int i=0; i<N; i++) scanf("%d", &A[i]);
    sort(A, A+N);

    int idx = 0, cnt = 0;
    double last = -1;
    while(idx<N) {
        if(last<A[idx]) cnt++, last = A[idx]+L-0.5;
        else idx++;
    }

    printf("%d", cnt);

    return 0;
}
