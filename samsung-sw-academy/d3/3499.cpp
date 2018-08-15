#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;

int tc, t;
int N;
char card[2000][81];
int deck[2000];
int output[2000];

bool DEBUG = false;

int main() {

//    FILE *fp = freopen("../data/3499.input", "r", stdin);
//    if(!fp)
//        perror("freopen error");

    scanf("%d", &tc);
    t = 0;
    while(t++ < tc) {

        scanf("%d", &N);
        for(int i=0; i<N; i++)
            scanf("%s", card[i]);

        int b = (N%2==0)? (N/2):(N/2+1);
        for(int i=0; i<b; i++)
            deck[2*i] = i;
        for(int i=b; i<N; i++)
            deck[2*(i-b)+1] = i;

        printf("#%d", t);
        for(int i=0; i<N; i++)
            printf(" %s", card[deck[i]]);
        printf("\n");

//        printf("#%d %d\n", t, a);
    }

    return 0;
}
