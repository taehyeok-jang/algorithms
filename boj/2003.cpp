#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;

int tc, t;
int N;
long long M;
long long A[10001];

int main() {

    scanf("%d%lld", &N, &M);
    for(int i=0; i<N; i++) scanf("%lld", &A[i]);

    long long sum = A[0];
    int l = 0, r = 0;
    int cnt = 0;
    while(l<N&&r<N) {
        if(sum<M) {
            sum += A[++r];
        }
        else if(sum==M) {
            cnt++;
            if(l==r) { sum += A[++r]; }
            else { sum -= A[l++]; }
        }
        else { // sum>M
            sum -= A[l++];
        }
    }

    printf("%d", cnt);
    return 0;
}
