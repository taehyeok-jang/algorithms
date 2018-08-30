#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAX 1000001

int tc, t;
int A, B;
bool prime[MAX];
int sum[MAX];
#ifdef DEBUG
#endif

int main() {

//    FILE *fp = freopen("../data/3501.input", "r", stdin);
//    if(!fp)
//        perror("freopen error");

    memset(prime, 1, sizeof(bool)*MAX);
    prime[1] = false;

    int bound = sqrt(MAX)+1;
    for(int i=2; i<=bound; i++) {
        if(prime[i])
            for(int j=i*i; j<=MAX; j+=i) // i*i-k was already divided.
                prime[j] = false;
    }

    sum[2] = 1;
    for(int i=3; i<MAX; i++) {
        if(prime[i]&&i%4==1) sum[i] = sum[i-1]+1;
        else sum[i] = sum[i-1];
    }

    scanf("%d", &tc);
    t = 0;
    while(t++ < tc) {
        // eratos.

        scanf("%d%d", &A, &B);

//        for(int i=2; i<MAX; i++)
//            cout << (prime[i]? i:0) << "\t";
//        cout << "\n";
//        for(int i=2; i<MAX; i++)
//            cout << sum[i] << "\t";
//        cout << "\n";

        printf("#%d %d\n", t, sum[B]-sum[A-1]);
    }

    return 0;
}
