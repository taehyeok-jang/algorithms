#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAX 1000000

int tc, t;
int N;
int d[1000];
bool visit[MAX];

bool DEBUG = false;

int main() {

//    FILE *fp = freopen("../data/3501.input", "r", stdin);
//    if(!fp)
//        perror("freopen error");

    scanf("%d", &tc);
    t = 0;
    while(t++ < tc) {

        scanf("%d", &N);
        for(int i=0; i<N; i++)
            scanf("%d", &d[i]);
        memset(visit, 0, sizeof(bool)*MAX);

        for(int l=1; l<7; l++) {
            for(int i=0; i<N-l+1; i++) {
                int num = 0;
                for(int j=i; j<i+l; j++) {
                    num = 10*num+d[j];
                }
                visit[num] = true;
            }
        }

        printf("#%d ", t);
        for(int i=0; i<MAX; i++) {
            if(!visit[i]) {
                printf("%d\n", i);
                break;
            }
        }
//        printf("#%d %d\n", t, a);
    }

    return 0;
}
