#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;

int N, S;
int A[21];
//#define DEBUG 1
#ifdef DEBUG
#endif

int main() {

    scanf("%d%d", &N, &S);
    for(int i=0; i<N; i++) scanf("%d", A+i);
    int idx = (1<<N), cnt = 0, sum;
    for(int i=1; i<idx; i++) {
        sum = 0;
        for(int j=0; j<N; j++)
            if(i&(1<<j))
                sum += A[j];
        if(sum==S) cnt++;
    }

    printf("%d", cnt);
    return 0;
}
