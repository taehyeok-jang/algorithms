#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

int tc, t;
bool DEBUG = false;

int main() {

//    FILE *fp = freopen("../data/3501.input", "r", stdin);
//    if(!fp)
//        perror("freopen error");

//    scanf("%d", &tc);
    tc = 10;
    t = 0;
    while(t++ < tc) {

        queue<int> q;
        int k;
        scanf("%d", &k);
        for(int i=0; i<8; i++) {
            scanf("%d", &k);
            q.push(k);
        }

//        for(int i=0; i<8; i++) {
//            int b = q.front(); q.pop();
//            printf(" %d", b);
//            q.push(b);
//        }
//        cout << "\n";

        bool end = 0;
        while(!q.empty()) {
            for(int i=1; i<6; i++) {
                int a = max(0, q.front()-i); q.pop();
                q.push(a);
                if(a==0) { end = 1; break; }
            }

            if(end) break;
        }

        printf("#%d", t);
        while(!q.empty()) printf(" %d", q.front()), q.pop();
        printf("\n");
//        printf("#%d %d\n", t, pow(N, M));
    }

    return 0;
}
