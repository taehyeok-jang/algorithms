#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;

int N;
struct p {
    int x, y;
    bool operator <(const p &p2) const { if(y==p2.y) return x<p2.x; else return y<p2.y; }
} pp[100001];

//#define DEBUG 1
#ifdef DEBUG
#endif

int main() {

    scanf("%d", &N);
    for(int i=0; i<N; i++)
        scanf("%d%d", &pp[i].x, &pp[i].y);
    sort(pp, pp+N);

    int s = -1, i = 0;
    int cnt = 0;
    while(i<N) {
        if(s<=pp[i].x) cnt++, s = pp[i].y;
        i++;
    }
    printf("%d", cnt);
    return 0;
}
