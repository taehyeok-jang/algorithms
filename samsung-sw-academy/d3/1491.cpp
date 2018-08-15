#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;

int tc, t;
long long N, A, B;

bool DEBUG = false;

long long min(long long a, long long b) { return a<b? a:b;};

int main() {

//    FILE *fp = freopen("../data/3501.input", "r", stdin);
//    if(!fp)
//        perror("freopen error");

    scanf("%d", &tc);
    t = 0;
    while(t++ < tc) {

        scanf("%lld%lld%lld", &N, &A, &B);
        int k = sqrt(N);
        int offset = 1000;
        long ans = N*(A+B);
        for(int r=1; r<N+1; r++) {
            for(int c=1; c*r<N+1; c++) {
                if(r>=c) ans = min(ans, A*(r-c)+B*(N-r*c));
            }
        }


//        for(int i=max(1, k-offset); i<k+offset; i++) {
//            for(int j=max(1, k-offset); j<k+offset; j++) {
//                if(i*j>N) continue;
////                cout << i << ", " << j << "\n";
//                ans = min(ans, (A*abs(i-j)+B*abs(N-i*j)));
//            }
//        }
        printf("#%d %ld\n", t, ans);
    }

    return 0;
}
