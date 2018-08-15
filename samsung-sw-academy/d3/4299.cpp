#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;

int tc, t;
int D, H, M;

bool DEBUG = false;

int main() {

//    FILE *fp = freopen("../data/3501.input", "r", stdin);
//    if(!fp)
//        perror("freopen error");

    scanf("%d", &tc);
    t = 0;
    while(t++ < tc) {

        scanf("%d%d%d", &D, &H, &M);

        bool wait = true;
        if(D<11)                wait = false;
        if(D==11&&H<11)         wait = false;
        if(D==11&&H==11&&M<11)  wait = false;

        if(!wait) {
            printf("#%d -1\n", t);
            continue;
        }

        int a = 1440*11+60*11+11;
        int b = 1440*D+60*H+M;

        printf("#%d %d\n", t, b-a);
    }

    return 0;
}
