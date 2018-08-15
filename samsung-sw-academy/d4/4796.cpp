#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

int tc, t;
int N;
int A[50001];
bool DEBUG = false;

int main() {

    scanf("%d", &tc);
    t = 0;
    while(t++ < tc) {

        scanf("%d", &N);
        for(int i=0; i<N; i++) scanf("%d", &A[i]);

        int count = 0;
        int cur = 0;
        while(cur<N) {
            int up=0, down=0;
            while(cur+1<N&&A[cur]<A[cur+1]) up++, cur++;
            if(up==0)   { cur++; continue; }
            while(cur+1<N&&A[cur]>A[cur+1]) down++, cur++;
            if(down==0) { cur++; continue; }
            else { count += up*down; }
        }

        printf("#%d %d\n", t, count);
    }

    return 0;
}
