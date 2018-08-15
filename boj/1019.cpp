#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

int tc, t;
int N;
int A[10];
vector<int> cache[10];

bool DEBUG = false;

int main() {

//    FILE *fp = freopen("../data/3501.input", "r", stdin);
//    if(!fp)
//        perror("freopen error");
    tc = 10;
    t = 0;
    while(t++<10) {

        for(int i=0; i<10; i++) A[i] = 0;
        scanf("%d", &N);
        for(int i=1; i<N+1; i++) {

            int k = i;
            while(k>0) {
                A[k%10]++;
                k /= 10;
            }
        }

        for(int i=0; i<10; i++) printf("%d ", A[i]);
        printf("\n");
    }


    return 0;
}
