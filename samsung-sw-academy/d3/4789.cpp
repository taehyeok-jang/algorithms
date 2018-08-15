#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;

int tc, t;
char buf[1003];
int P[1003];

bool DEBUG = false;

int main() {

//    FILE *fp = freopen("../data/4789.input", "r", stdin);
//    if(!fp)
//        perror("freopen error");

    scanf("%d", &tc);
    t = 0;
    while(t++ < tc) {

        scanf("%s", buf);
        for(int i=0; i<strlen(buf); i++)
            P[i] = buf[i]-48;

//        cout << "l: " << strlen(buf) << "\n";

        // sol 1.
        int count1 = 0; // = P[0];
        int total = strlen(buf);
        for(int i=0; i<total-1; i++)
            count1 += P[i];

        // sol 2.
        int count2 = P[0];
        int add = 0;
        for(int i=1; i<strlen(buf); i++) {

            if(P[i] == 0)
                continue;

            if(count2 >= i) {
                count2 += P[i];
            }
            else {
                add += (i-count2);
                count2 += ((i-count2)+P[i]);
            }
        }
        printf("#%d %d  ", t, add);
//        printf("#%d %d\n", t, max(0, total-1-count1));
    }

    return 0;
}
