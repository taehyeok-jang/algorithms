#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;

int tc, t;
int N;
int A[100001];

int main() {

//    FILE *fp = freopen("../data/3501.input", "r", stdin);
//    if(!fp)
//        perror("freopen error");

    scanf("%d", &tc);
    t = 0;
    while(t++ < tc) {

        scanf("%d", &N);
        int a, b;
        for(int i=0; i<N; i++) {
            scanf("%d%d", &a, &b);
            A[a] = b;
        }

        int rank= A[1], cnt = 1;
        for(int i=2; i<N+1; i++) {
            if(A[i]<rank) {
                cnt++;
                rank = A[i];
            }
        }
        printf("%d\n", cnt);
    }

    return 0;
}
