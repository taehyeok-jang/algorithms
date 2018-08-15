#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAX 1000001

int tc, t;
int d, a, b;

bool DEBUG = false;

int main() {

//    FILE *fp = freopen("../data/4698.input", "r", stdin);
//    if(!fp)
//        perror("freopen error");

    // eratos.
    bool prime[MAX];
    memset(prime, 1, sizeof(bool)*MAX);
    prime[1] = false;

    int bound = sqrt(MAX)+1;
    for(int i=2; i<=bound; i++) {
        if(prime[i])
            for(int j=i*i; j<=MAX; j+=i) // i*i-k was already divided.
                prime[j] = false;
    }

    scanf("%d", &tc);
    t = 0;
    while(t++ < tc) {

        scanf("%d%d%d", &d, &a, &b);

        int count = 0;
        for(int i=a; i<=b; i++) {
            if(prime[i]) {
                // contains d?
                int temp = i;
                while(temp > 0) {
                    if(temp%10 == d) {
                        count++;
                        break;
                    }
                    temp /= 10;
                }
            }
        }

        printf("#%d %d\n", t, count);
    }

    return 0;
}
