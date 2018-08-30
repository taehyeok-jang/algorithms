//#include <iostream>
//#include <cmath>
#include <algorithm>
//#include <cstring>

using namespace std;

#define MAX 10001
int tc, t;
int N;
int A[MAX];

int main() {

//    FILE *fp = freopen("../data/battle.input", "r", stdin);
//    if(!fp)
//        perror("freopen error");

    scanf("%d", &tc);
    t = 0;
    while(t++ < tc) {

        scanf("%d", &N);
        for(int i=0; i<N; i++) scanf("%d", &A[i]);
        sort(A, A+N);

        int mx = max(abs(A[0]-A[1]), abs(A[N-2]-A[N-1]));
        for(int i=0; i<N-2; i++)
            mx = max(mx, abs(A[i]-A[i+2]));

        printf("#%d %d\n", t, mx);
    }

    return 0;
}
