#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAX 10001
int tc, t;
int a, b;

//#define DEBUG 1
#ifdef DEBUG
#endif

int height(int k) {
    int s = 0, h = 0;
    while(s<k) s += (h++);
    return h-1;
}

int main() {

//    FILE *fp = freopen("../data/4112.input", "r", stdin);
//    if(!fp)
//        perror("freopen error");

    scanf("%d", &tc);
    t = 0;
    while(t++ < tc) {

        int x, y;
        scanf("%d%d", &x, &y);
        a = min(x, y), b = max(x, y);

        int ah, bh, tmp, l, r;
        ah = height(a), bh = height(b);

        tmp = ah;
        l = a, r = a;
        while(tmp<bh) {
            l += tmp, r += tmp+1;
            tmp++;
        }
        int count = bh-ah;
        if(b<l) count += l-b;
        if(b>r) count += b-r;

        printf("#%d %d\n", t, count);
    }

    return 0;
}
