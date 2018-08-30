#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;

int tc, t;
int N;

//#define DEBUG 1
#ifdef DEBUG
#endif

int main() {

    scanf("%d", &N);
    int A = N;
    int a, b, cnt = 0, tmp;

    tmp = -1;
    a = N/10, b = N%10;
    while(N!=tmp) {
        cnt++;
        tmp = 10*b+(a+b)%10;
        a = tmp/10;
        b = tmp%10;
    }
    printf("%d", cnt);
    return 0;
}
