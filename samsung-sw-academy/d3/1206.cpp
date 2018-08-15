#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;

int tc, t;
int N;
int A[1001];
bool DEBUG = false;

int main() {

//    FILE *fp = freopen("../data/3501.input", "r", stdin);
//    if(!fp)
//        perror("freopen error");

//    scanf("%d", &tc);
    tc = 1;
    t = 0;
    while(t++ < tc) {

        scanf("%d", &N);
        for(int i=0; i<N; i++) scanf("%d", &A[i]);
        int sum = 0, h;
        for(int i=2; i<N-2; i++) {
            bool safe = true;
            for(int j=i-2; j<i+3; j++) {
                if(j == i) continue;
                if(A[i]<=A[j]) { safe = false; break; }
            }
            if(safe) {
                h = 0;
                for(int j=i-2; j<i+3; j++) {
                    if(j == i) continue;
                    h = max(h, A[j]);
                }
                sum += A[i]-h;
            }
        }

        printf("#%d %d\n", t, sum);
    }

    return 0;
}
