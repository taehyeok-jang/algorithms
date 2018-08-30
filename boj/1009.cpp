#include <stdio.h>

using namespace std;
#define MOD 97
int tc, t;
int a, b, c;

int mod(int a, int b) {
    if(b==0) return 1;
    int r = mod(a, b/2);
    int ans = r*r*(b%2?a:1)%10;
    return ans;
}

int main() {

    scanf("%d", &tc);
    t = 0;
    while(t++ < tc) {
        scanf("%d%d", &a, &b);
/**
iterative approach (https://www.acmicpc.net/source/2391771)
        c = 1;
        while (b){
            if (b % 2) c = (c* a) % 10;
            b /= 2;
            a = (a*a) % 10;
        }
*/
        printf("%d\n", (mod(a, b)+9)%10+1);
    }

    return 0;
}
