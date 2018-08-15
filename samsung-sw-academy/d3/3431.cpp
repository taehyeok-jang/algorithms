#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;

int tc, t;
int l, u, x;

bool DEBUG = false;

int main() {

//    FILE *fp = freopen("../data/3501.input", "r", stdin);
//    if(!fp)
//        perror("freopen error");

    scanf("%d", &tc);
    t = 0;
    while(t++ < tc) {

        scanf("%d%d%d", &l, &u, &x);
        if(x>u)
            printf("#%d -1\n", t);
        else
            printf("#%d %d\n", t, max(0, l-x));

//        printf("#%d %d\n", t, a);
    }

    return 0;
}
