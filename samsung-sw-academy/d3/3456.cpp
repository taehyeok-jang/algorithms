#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;

int tc, t;
int a, b, c, d;

bool DEBUG = false;

int main() {

//    FILE *fp = freopen("../data/3501.input", "r", stdin);
//    if(!fp)
//        perror("freopen error");

    scanf("%d", &tc);
    t = 0;
    while(t++ < tc) {

        scanf("%d%d%d", &a, &b, &c);

        printf("#%d ", t);
        if((a==b)&&(a==c))  printf("%d\n", a);
        else {
            if(a==b)        printf("%d\n", c);
            else if(b==c)   printf("%d\n", a);
            else            printf("%d\n", b);
        }



//        printf("#%d %d\n", t, a);
    }

    return 0;
}
