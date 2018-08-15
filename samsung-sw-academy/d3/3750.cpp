#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;

int tc, t;
long long n;

bool DEBUG = false;

int main() {

//    FILE *fp = freopen("../data/3501.input", "r", stdin);
//    if(!fp)
//        perror("freopen error");

    scanf("%d", &tc);
    t = 0;
    while(t++ < tc) {

        scanf("%lld", &n);

        while(n > 9) {
//            cout << n << "\n";
            int f = 0;
            while(n > 0) {
                f += (n%10);
                n /= 10;
            }
            n = f;
        }

        printf("#%d %lld\n", t, n);



//        printf("#%d %d\n", t, a);
    }

    return 0;
}
