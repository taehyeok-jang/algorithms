#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

int tc, t;
int N;
vector<int> A;

//#define DEBUG 1
#ifdef DEBUG
#endif

int main() {

    scanf("%d", &N);
    A = vector<int>(N);
    for(int i=0; i<N; i++)
        scanf("%d", &A[i]);

    sort(A.begin(), A.end());

    int sum;
    int m = -1;
    do {
//        for(int i=0; i<N; i++) cout << A[i] << " ";
//        cout << "\n";
        sum = 0;
        for(int i=0; i<N-1; i++)
            sum += abs(A[i]-A[i+1]);
        m = max(m, sum);

    } while(next_permutation(A.begin(), A.end()));

    printf("%d", m);
    return 0;
}
