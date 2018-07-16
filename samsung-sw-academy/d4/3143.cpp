#include <iostream>
#include <cstring>

using namespace std;

int tc, t;
char A[10001], B[101];
int N, M;

bool DEBUG = false;

int main() {

    FILE *fp = freopen("../data/3143.input", "r", stdin);
    if(!fp)
        perror("freopen error");

    scanf("%d", &tc);
    t = 0;
    while(t++ < tc) {

        scanf("%s", A);
        scanf("%s", B);

//        printf("%s\n", A);

        int N = strlen(A);
        int M = strlen(B);

//        cout << N << ", " << M << "\n";

        int count = 0;
        int j = 0;
        for(int i=0; i<N; i++) {

//            cout << "i: " << i << "\n";
            j = 0;
            if(A[i] != B[j]) {
                count++;
                continue;
            }
            else {
                while(A[i]==B[j] && i<N && j<M) {
                    i++;
                    j++;
                }
                if(j == M)
                    count++;
                else {
                    count += j;
                }
                i--;
            }
        }

//        int i = 0;
//        while(A[i] != NULL)
//            printf("%c", A[i]);

//        for(int i=0; i<10001; i++)
//
//        int count = 0;
//        for(int i=0; i<N; i++)
//            count += solve(weight[i], 0, (1<<i));

        printf("#%d %d\n", t, count);
    }

    return 0;
}