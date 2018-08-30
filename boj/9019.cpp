#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;
#define MAX 10001
//#define DEBUG 1

int tc;

//struct state {
//    int reg;
//    vector<char> log;
//    state() {}
//    state(int r, vector<char> &ll) { // just copy val.
//        reg = r;
//        for(int i=0; i<ll.size(); i++) log.push_back(ll[i]);
//    }
//};

pair<int, int> q[MAX]; int f, r, size;
int visited[MAX];
pair<char, int> event_log[100*MAX]; int ei;

int D(int input) { return (2*input)%10000; }
int S(int input) { return (input==0)? 9999:input-1; }
int L(int input) { return (input*10+input/1000)%10000; }
int R(int input) { return (input%10)*1000+input/10; }

int main() {

//    FILE *fp = freopen("../data/battle.input", "r", stdin);
//    if(!fp)
//        perror("freopen error");

    scanf("%d", &tc);
    while(tc--) {

        int a, b;
        scanf("%d%d", &a, &b);

        memset(visited, 0, sizeof(visited));
        f = r = 0;

        for(int i=0; i<10*MAX; i++) {
            event_log[i].first = 0;
            event_log[i].second = 0;
        }
        ei = 0;

        bool solve = 0;
        event_log[ei] = make_pair(0, -1);
        q[r++] = make_pair(a, ei++);
        visited[a] = 1;

        int reg, tmp, before; string log; pair<int, pair<char, int>> ss;
        while(f!=r) {
            size = r-f;
            while(size--) {
                pair<int, int> pp = q[f++];
                reg = pp.first;
                before = pp.second;

                if(reg == b) {
                    int kk = 0; // TODO temp.
                    while(kk++<10001&&event_log[before].first!=0) {
                        printf("%c", event_log[before].first);
                        before = event_log[before].second;
                    }
                    printf("\n");
                    solve = 1;
                    break;
                }

                tmp = D(reg);
                if(!visited[tmp]) {
                    event_log[ei] = make_pair('D', before);
                    q[r++] = make_pair(tmp, ei++);
                    visited[tmp] = 1;
                }

                tmp = S(reg);
                if(!visited[tmp]) {
                    event_log[ei] = make_pair('S', before);
                    q[r++] = make_pair(tmp, ei++);
                    visited[tmp] = 1;
                }

                tmp = L(reg);
                if(!visited[tmp]) {
                    event_log[ei] = make_pair('L', before);
                    q[r++] = make_pair(tmp, ei++);
                    visited[tmp] = 1;
                }

                tmp = R(reg);
                if(!visited[tmp]) {
                    event_log[ei] = make_pair('R', before);
                    q[r++] = make_pair(tmp, ei++);
                    visited[tmp] = 1;
                }
            }
            if(solve) break;
        }
    }

//    printf("error.");
    return 0;
}

