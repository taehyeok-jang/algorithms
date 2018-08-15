#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;

int tc, t;
int N, M, K;
int A[101];

bool DEBUG = false;

int main() {

//    FILE *fp = freopen("../data/1860.input", "r", stdin);
//    if(!fp)
//        perror("freopen error");

    scanf("%d", &tc);
    t = 0;
    while(t++ < tc) {

        scanf("%d%d%d", &N, &M, &K);
        for(int i=0; i<N; i++) scanf("%d", &A[i]);
        sort(A, A+N);

        int i = 0, tt = 0;
        int num = 0;
        bool success = 1;
        while(i<N) {
            while(tt==A[i]) {
                i++;
                if(num==0) { success=0; break; }
                else       num-=1;
            }
            if(!success) break;
            tt++;
            if(tt%M==0) num += K;
        }
        printf("#%d ", t);
        if(i==N&&success)   printf("Possible\n");
        else                printf("Impossible\n");
    }

    return 0;
}
