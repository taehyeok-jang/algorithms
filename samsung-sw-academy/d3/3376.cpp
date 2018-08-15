#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;

int tc, t;
int N;
long long P[101];
bool DEBUG = false;
int A[6] = {1, 1, 1, 2, 2, 3};
int main() {

//    FILE *fp = freopen("../data/3501.input", "r", stdin);
//    if(!fp)
//        perror("freopen error");

    for(int i=0; i<6; i++)
        P[i] = A[i];
    for(int i=6; i<101; i++)
        P[i] = P[i-1]+P[i-5];

    for(int i=0; i<20; i++)
        cout << P[i] << "\n";

    scanf("%d", &tc);
    t = 0;
    while(t++ < tc) {

        scanf("%d", &N);
        printf("#%d %lld\n", t, P[N-1]);
    }

    return 0;
}
