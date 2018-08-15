#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int tc, t;
int P, Q;

bool DEBUG = false;

int main() {

//    FILE *fp = freopen("../data/5162.input", "r", stdin);
//    if(!fp)
//        perror("freopen error");

    scanf("%d", &tc);
    t = 0;
    while(t++ < tc) {

        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);

        printf("#%d %d\n", t, c/min(a,b));
    }

    return 0;
}
