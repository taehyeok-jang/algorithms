#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

int tc, t;
int N;
priority_queue<int> pq;

bool DEBUG = false;

int main() {

//    FILE *fp = freopen("../data/3501.input", "r", stdin);
//    if(!fp)
//        perror("freopen error");

    scanf("%d", &tc);
    t = 0;
    while(t++ < tc) {

        while(!pq.empty()) pq.pop();
        scanf("%d", &N);
        int c, a, b;
        printf("#%d", t);
        for(int i=0; i<N; i++) {
            scanf("%d", &c);
            if(c==1) scanf("%d", &a);

            if(c==1) {
                pq.push(a);
            }
            else {
                if(!pq.size()) b = -1;
                else { b = pq.top(), pq.pop(); }
                printf(" %d", b);
            }
        }
        printf("\n");
    }

    return 0;
}
