#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;

int tc, t;
int N, M, x, y;

int gcd(int a, int b){
    int tmp, n;
    if(a<b){
        tmp = a;
        a = b;
        b = tmp;
    }
    while(b!=0){
        n = a%b;
        a = b;
        b = n;
    }
    return a;
}


pair<int, int> next(pair<int, int> cur) {
    return make_pair(cur.first<M? cur.first+1:1, cur.second<N? cur.second+1:1);
}

int main() {

    scanf("%d", &tc);
    t = 0;
    while(t++ < tc) {
//        printf("@@@ %d\n", t);
        scanf("%d%d%d%d", &M, &N, &x, &y);

        pair<int, int> p = make_pair(1, 1);
        if(p.first==x&&p.second==y) { printf("%d\n", 1); continue; }

        int solved = 0, count = 1;

        for(int i=0; i<x-1; i++) {
            p = next(p);
            count += 1;
//            printf("%d %d\n", p.first, p.second);
            if(count>N*M) { solved = -1; break; }
            if(p.first==x&&p.second==y) { solved = 1; break; }
        }

        if(solved==-1) { printf("%d\n", -1); continue; }
        if(solved==1) { printf("%d\n", count); continue; }

        for(int i=0; i<N/gcd(M, N); i++) {
//        for(int i=0; i<N; i++) {
            p.second = (p.second+M)%N==0? N:(p.second+M)%N;
            count += M;
            if(count>N*M) { solved = -1; break; }
            if(p.first==x&&p.second==y) { solved = 1; break; }
        }

        printf("%d\n", (solved==1)? count:-1);
    }

    return 0;
}

/**
 *
 * 2
12 10 12 10
40000 3 40000 3

15
40000 39999 39999 39998
40000 39999 40000 39999
40000 40000 40000 39999
40000 39998 40000 39997
39999 2 39998 2
3 40000 3 39999
40000 3 40000 3
8 2 4 2
10 12 2 12
12 10 12 10
12 10 1 1
12 6 12 6
10 1 5 1
1 10 1 5
1 1 1 1

1599959999
1599960000
-1
-1
39998
39999
120000
4
12
60
1
12
5
5

1
 */
