#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;

int tc, t;
long long N;

bool DEBUG = false;

int main() {

//    FILE *fp = freopen("../data/3501.input", "r", stdin);
//    if(!fp)
//        perror("freopen error");

    scanf("%d", &tc);
    t = 0;
    while(t++ < tc) {

        scanf("%d", &N);
//        long long s1 = LONG_LONG_MAX;
        long long s1, s2, s3;
        s1 = N*(N+1)/2;
        s3 = s1*2;
        s2 = s3-N;

//        cout << LONG_LONG_MAX << "\n";
        printf("#%d %lld %lld %lld\n", t, s1, s2, s3);
    }

    return 0;
}
