#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <map>

using namespace std;

#define MAX 1000001

int tc, t;
int L, R;

map<int, bool> is_prime;
int primes[100000];
int prime_size;
long long cache[MAX];
long long sum[MAX];

bool DEBUG = false;

void eratos();
long long f(int n);

void eratos() {

    bool prime[MAX];
    memset(prime, 1, sizeof(bool)*MAX);

    int bound = sqrt(MAX)+1;
    for(int i=2; i<=bound; i++) {
        if(prime[i])
            for(int j=i*i; j<=MAX; j+=i)
                prime[j] = false;
    }
    prime_size = 0;
    for(int i=2; i<=MAX; i++) {
        if(prime[i]) {
            primes[prime_size++] = i;
            is_prime[i] = true;
        }
    }
}

long long f(int n) {

    if(cache[n] != -1) return cache[n];
    if(n == 1) return 1;
    if(n>2 && is_prime[n]) return 1+n;
    if(n%2 == 0) return cache[n] = f(n/2);

    int div = -1;
    // O(sqrt(MAX)) = O(1000).
    for(int i=0; i<prime_size; i++) {
        if(n%primes[i] == 0) {
            div = primes[i];
            break;
        }
    }
    int s = n/div;
    if(s%div != 0) {
        return cache[n] = (1+div)*f(s);
    }
    else {
        int temp = s;
        while(temp%div == 0)
            temp /= div;
        return cache[n] = f(temp)+div*f(s);
    }
}

int main() {

//    FILE *fp = freopen("../data/battle.input", "r", stdin);
//    if(!fp)
//        perror("freopen error");

    scanf("%d", &tc);
    t = 0;

    // TODO pre-processing.
    // find primes.
    eratos();

    for(int i=0; i<MAX; i++) cache[i] = -1;
    for(int i=0; i<MAX; i++) sum[i] = 0;
    sum[1] = 1;
    for(int i=2; i<MAX; i++)
        sum[i] = sum[i-1]+f(i);

//    for(int i=1; i<11; i++)
//        cout << "f(" << i << "): " << f(i) << "\n";

    while(t++ < tc) {

        scanf("%d%d", &L, &R);
        printf("#%d %lld\n", t, sum[R]-sum[L-1]);
    }

    return 0;
}
