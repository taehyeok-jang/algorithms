#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;

int N;
int A[51], B[51];
int idx[51], temp[51];

//#define DEBUG 1
#ifdef DEBUG
#endif

int main() {

    scanf("%d", &N);
    for(int i=0; i<N; i++) scanf("%d", A+i);
    for(int i=0; i<N; i++) scanf("%d", B+i);

    sort(A, A+N);
    sort(B, B+N, greater<int>());

    int sum = 0;
    for(int i=0; i<N; i++) sum += A[i]*B[i];

    printf("%d", sum);
    return 0;
}
