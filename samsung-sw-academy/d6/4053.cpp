//#include <stdio.h>
//#include <cstring>
#include <iostream>

using namespace std;

int tc, t;
int N, Q;
long long T;

struct person {
    long long x;
    int dir;
} p[100001];
int X[1001];

int stack[100001], st;
long long bound;

long long max(long long a, long long b) { return a>b? a:b; }
long long min(long long a, long long b) { return a<b? a:b; }

int main() {

    scanf("%d", &tc);
    t = 0;
    while(t++ < tc) {

        scanf("%d%lld%d", &N, &T, &Q);
        for(int i=1; i<N+1; i++)
            scanf("%lld%d", &p[i].x, &p[i].dir);
        for(int i=0; i<Q; i++)
            scanf("%d", &X[i]);

        st = 0;
        bound = -2*1e18;
        int i = 1;
        long long mid;
        while(i<N+1) {
            if(p[i].dir==2) {
                p[i].x = max(p[i].x-T, bound);
                i += 1;
            }
            else { // p[i].dir==1
                if(i==N) {
                    p[i].x += T;
                    break;
                }
                if(p[i+1].dir==2) {
                    mid = (p[i].x+p[i+1].x)/2;
                    p[i].x = min(p[i].x+T, mid);
                    p[i+1].x = max(p[i+1].x-T, mid);
                    bound = p[i+1].x;
                    i += 2;
                    while(st) {
                        int k = stack[st--];
                        p[k].x = min(p[k].x+T, bound);
                    }
                }
                else {
                    stack[++st] = i;
                    i += 1;
                }
            }
        }
        while(st) {
            int k = stack[st--];
            p[k].x += T;
        }

        printf("#%d", t);
        for(int i=0; i<Q; i++)
            printf(" %lld", p[X[i]].x);
        printf("\n");
    }

    return 0;
}
