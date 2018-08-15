#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;

int tc, t;
char S[20];
int L, H;
int pos[101];

bool DEBUG = false;

int main() {

//    FILE *fp = freopen("../data/4676.input", "r", stdin);
//    if(!fp)
//        perror("freopen error");

    scanf("%d", &tc);
    t = 0;
    while(t++ < tc) {

        scanf("%s", S);
        L = strlen(S);

        scanf("%d", &H);
        for(int i=0; i<H; i++)
            scanf("%d", &pos[i]);
        sort(pos, pos+H);

        printf("#%d ", t);
        int index = 0;
        for(int i=0; i<L+1; i++) {

            while(index<H&&pos[index]==i) {
                printf("-");
                index++;
            }
            if(i<L)
                printf("%c", S[i]);
        }
        printf("\n");

//        printf("#%d %d\n", t, a);
    }

    return 0;
}
