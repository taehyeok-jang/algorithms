#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;

int tc, t;
double a, b, c, d;

bool DEBUG = false;

int main() {

//    FILE *fp = freopen("../data/3501.input", "r", stdin);
//    if(!fp)
//        perror("freopen error");

    scanf("%d", &tc);
    t = 0;
    while(t++ < tc) {

        scanf("%lf%lf%lf%lf", &a, &b, &c, &d);

        string s;
        if(a/b>c/d)         s = "ALICE";
        else if(a/b<c/d)    s = "BOB";
        else                s = "DRAW";

        printf("#%d %s\n", t, s.c_str());
    }

    return 0;
}
