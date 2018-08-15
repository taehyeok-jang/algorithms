#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAX 1000001
int tc, t;
int P, Q;

bool DEBUG = false;

int main() {

//    FILE *fp = freopen("../data/3501.input", "r", stdin);
//    if(!fp)
//        perror("freopen error");

    bool prime[MAX];
    memset(prime, 1, sizeof(bool)*MAX);

    int bound = sqrt(MAX)+1;
    for(int i=2; i<=bound; i++) {
        if(prime[i])
            for(int j=i*i; j<MAX; j+=i)
                prime[j] = false;
    }
    // 37550402023
//    long long sum = 0;
    for(int i=2; i<MAX; i++) {
        if(prime[i]) {
//            count++;
//            sum += i;
            printf("%d " , i);
        }
    }
    printf("\n");

//    cout << sum << "\n";
    return 0;
}
