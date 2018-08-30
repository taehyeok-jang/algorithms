#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

int tc, t;
int N, M, K, A, B;
int a[11], b[11];
int tk[1001];

struct p {
    int t;
    int a, b;
} client[1001];

struct waiting {
    int idx, end;
} a_process[11], b_process[11];

struct q {
    int arr[1001];
    int f, r;
    void initialize() { for(int i=0; i<1001; i++) arr[i] = 0; f = r = 0; }
    void push(int idx) { arr[r++] = idx; }
    int pop() { return arr[f++]; }
    int size() { return r-f; }
} aq, bq, cq;

int main() {

//    FILE *fp = freopen("../data/battle.input", "r", stdin);
//    if(!fp)
//        perror("freopen error");

    scanf("%d", &tc);
    t = 0;
    while(t++ < tc) {

        scanf("%d %d %d %d %d ", &N, &M, &K, &A, &B);
        for(int i=1; i<N+1; i++) scanf("%d", &a[i]);
        for(int i=1; i<M+1; i++) scanf("%d", &b[i]);
        for(int i=0; i<11; i++) a_process[i].idx = -1;
        for(int i=0; i<11; i++) b_process[i].idx = -1;

        for(int i=1; i<K+1; i++) scanf("%d", &tk[i]);
        for(int i=1; i<K+1; i++) client[i].t = tk[i];

        aq.initialize(); bq.initialize();
        cq.initialize();

        int time = 0, idx = 1, completed = 0;
        while(completed<K) {

            while(idx<K+1&&client[idx].t<=time) aq.push(idx++);

            // clear&push at 'a' desk.
            for(int i=1; i<N+1; i++)
                if(a_process[i].idx!=-1&&a_process[i].end==time) {
                    bq.push(a_process[i].idx);
                    a_process[i].idx = -1;
                }
            for(int i=1; i<N+1; i++) {
                if(aq.size()==0) break;
                if(a_process[i].idx==-1) {
                    int j = aq.pop();
                    client[j].a = i;
                    a_process[i].idx = j;
                    a_process[i].end = time+a[i];
                }
            }

            // clear&push at 'b' desk.
            for(int i=1; i<M+1; i++)
                if(b_process[i].idx!=-1&&b_process[i].end==time) {
                    completed++;
                    b_process[i].idx = -1;
                }
            for(int i=1; i<M+1; i++) {
                if(bq.size()==0) break;
                if(b_process[i].idx==-1) {
                    int j = bq.pop();
                    client[j].b = i;
                    b_process[i].idx = j;
                    b_process[i].end = time+b[i];
                }
            }
            time++;
        }

        int ans = 0;
        for(int i=1; i<K+1; i++)
            if(client[i].a==A&&client[i].b==B)
                ans += i;

        printf("#%d %d\n", t, ans==0? -1:ans);
    }

    return 0;
}
