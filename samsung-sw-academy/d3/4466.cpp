#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;

int tc, t;
int N, K;
int score[100];

bool DEBUG = false;

int main() {

//    FILE *fp = freopen("../data/3501.input", "r", stdin);
//    if(!fp)
//        perror("freopen error");

    scanf("%d", &tc);
    t = 0;
    while(t++ < tc) {

        scanf("%d%d", &N, &K);
        for(int i=0; i<N; i++)
            scanf("%d", &score[i]);

        sort(score, score+N, greater<int>());

        int sum = 0;
        for(int i=0; i<K; i++)
            sum += score[i];

        printf("#%d %d\n", t, sum);
    }

    return 0;
}
