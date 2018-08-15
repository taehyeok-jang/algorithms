#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;

int tc, t;
int N;
char p[11], q[1001];

bool DEBUG = false;

int main() {

//    FILE *fp = freopen("../data/3501.input", "r", stdin);
//    if(!fp)
//        perror("freopen error");

//    scanf("%d", &tc);
    tc = 10;
    t = 0;
    while(t++ < tc) {

        scanf("%d", &N);
        scanf("%s%s", p, q);
        int count = 0;
        for(int i=0; i<strlen(q)-strlen(p)+1; i++) {
            for(int j=0; j<strlen(p); j++) {
                if(p[j]!=q[i+j]) break;
                if(j==strlen(p)-1&&p[j]==q[i+j]) count++;
            }
        }

        printf("#%d %d\n", t, count);
    }

    return 0;
}
