#include <iostream>
#include <cmath>

using namespace std;

int tc, t;
bool DEBUG = false;

int N, K;
double A[503];
double sqrA[503];

int main() {

//    FILE *fp = freopen("../data/kakao/B.input", "r", stdin);
//    if(!fp)
//        perror("freopen error");

    tc = 1;
    t = 0;
    while(t++ < tc) {

        scanf("%d%d", &N, &K);
        for(int i=0; i<N; i++) scanf("%lf", &A[i]);
        for(int i=0; i<N; i++) sqrA[i] = A[i]*A[i];

        double V = 987654321;
        double sum, square_sum;

        for(int l=K; l<N+1; l++) {
            sum = 0;
            square_sum = 0;
            for(int j=0; j<l; j++) {
                sum += A[j];
                square_sum += sqrA[j];
            }
            // V = E(X^2)-E(X)^2
            V = min(V, square_sum/l-(sum*sum)/(l*l));

            int left = 0, right = l;
            while(right<N) {
                // sliding window.
                sum = sum - A[left] + A[right];
                square_sum = square_sum - sqrA[left] + sqrA[right];
                V = min(V, square_sum/l-(sum*sum)/(l*l));

                left++, right++;
            }
        }

        printf("%0.10f\n", sqrt(V));
    }

    return 0;
}
