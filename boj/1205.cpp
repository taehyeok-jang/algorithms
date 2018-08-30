#include <cstdio>

using namespace std;

int N, P;
long long score;
long long A[55];
//#define DEBUG 1
#ifdef DEBUG
#endif

int main() {

    scanf("%d%lld%d", &N, &score, &P);
    for(int i=1; i<N+1; i++) scanf("%lld", &A[i]);

//    sort(A+1, A+N+1, greater<int>());

    int rank = 1, pos = 1;
    while(pos<N+1) {
        if(score>A[pos]) break;
        else if(score==A[pos]) pos++;
        else {
            pos++;
            rank = pos;
        }
    }

    printf("%d", (pos<=P)? rank:-1);
    return 0;
}
