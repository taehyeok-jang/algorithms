#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAX 1000000000

int tc, t;
int N;
int day[5001];

bool DEBUG = false;

int main() {

//    FILE *fp = freopen("../data/4371.input", "r", stdin);
//    if(!fp)
//        perror("freopen error");

    scanf("%d", &tc);
    t = 0;
    while(t++ < tc) {

        scanf("%d", &N);
        for(int i=0; i<N; i++)
            scanf("%d", &day[i]);

        bool visit[N];
        memset(visit, 0, sizeof(bool)*N);

        int count = 0;
//        while(count < N) {

            for(int i=1; i<N; i++) {

                if(!visit[i]) {
                    visit[i] = true;
                    count++;
                    for(int j=i+1; j<N; j++)
                        if((day[j]-1)%(day[i]-1)==0)
                            visit[j] = true;
                }

            }
//        }

        printf("#%d %d\n", t, count);
    }

    return 0;
}
