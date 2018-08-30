#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;

int tc, t;
int N;

#define MAX 2000001
#ifdef DEBUG
#endif

bool is_prime(int n) {

    int s = (int)sqrt(n+1);
    for(int j=2; j<s+1; j++)
        if(n%j==0)
            return 0;
    return 1;
}

bool is_pal(int n) {

    int tmp = n, l = 0;
    while(tmp>0) l++, tmp/=10;

    int buf[10]; tmp = n;
    for(int i=0; i<l; i++) {
        buf[i] = tmp%10;
        tmp /= 10;
    }

    for(int i=0; i<l/2; i++)
        if(buf[i]!=buf[l-1-i])
            return 0;
    return 1;
}

int main() {

    scanf("%d", &N);
    int p = 0;
    if(N==1) { printf("2"); return 0; };

    for(int i=N; i<MAX; i++)
        if(is_pal(i)&&is_prime(i)) {
            p = i; break;
        }
    printf("%d", p);
    return 0;
}
