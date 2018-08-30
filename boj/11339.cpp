#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;

int N;
int A[1001];

//#define DEBUG 1
#ifdef DEBUG
#endif

int main() {

    scanf("%d", &N);
    for(int i=0; i<N; i++) scanf("%d", &A[i]);
    sort(A, A+N);

    int sum = 0, s = 0;
    for(int i=0; i<N; i++) {
        sum += A[i]+s;
        s += A[i];
    }

    printf("%d", sum);
    return 0;
}
