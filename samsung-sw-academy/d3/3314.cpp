#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;

int tc, t;
int A[5];

bool DEBUG = false;

int main() {

//    FILE *fp = freopen("../data/3501.input", "r", stdin);
//    if(!fp)
//        perror("freopen error");

    scanf("%d", &tc);
    t = 0;
    while(t++ < tc) {

        int a, b;
        b = 0;
        for(int i=0; i<5; i++) {
            scanf("%d", &a);
            b += max(40, a);
        }

        printf("#%d %d\n", t, b/5);
    }

    return 0;
}
