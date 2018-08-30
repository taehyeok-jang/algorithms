#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

bool DEBUG = false;

int tc, t;
int N;

struct student {
    int s, e;
    bool operator <(const student &s2) const {
        return s < s2.s;
    }
};

student S[401];
bool visited[401];


int main() {

//    FILE *fp = freopen("../data/solved/4408.input", "r", stdin);
//    if(!fp)
//        perror("freopen error");

    scanf("%d", &tc);
    t = 0;
    while(t++ < tc) {

        scanf("%d", &N);
        for(int i=0; i<N; i++) {
            int a, b;
            scanf("%d%d", &a, &b);
            S[i].s = min(a, b);
            S[i].e = max(a, b);
        }
        memset(visited, 0, sizeof(bool)*N);

        sort(S, S+N);

//        for(int i=0; i<N; i++)
//            cout << S[i].s << ", " << S[i].e << "\n";

        int time = 0;
        int count = 0;
        int start;
        while(count<N) {

            start = -1;
            time++;

            for(int i=0; i<N; i++) {

                if(visited[i])
                    continue;

                if(start == -1) {
                    visited[i] = true;
                    start = S[i].e;
                    count++;
                }
                else if(start%2==0&&S[i].s>start) {
                    visited[i] = true;
                    start = S[i].e;
                    count++;
                }
                else if(start%2==1&&S[i].s>start+1){ // start%2 == 1
                    visited[i] = true;
                    start = S[i].e;
                    count++;
                }
            }
        }


        printf("#%d %d\n", t, time);
    }

    return 0;
}