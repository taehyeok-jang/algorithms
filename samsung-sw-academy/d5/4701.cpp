#include <iostream>
#include <vector>

using namespace std;

//#define MOD 1,000,000,007;
#define MOD 1000000007

int tc, t;
int N;
int A[100], B[100];

long long cache[101][100][100];

bool DEBUG = false;

// A should win by 'win', from A[a], B[b].
long long solve(int win, int a, int b, long long a_used) {

    if(win == 0)
        return 1;
    if(a==N || b==N)
        return 0;

    if(((1<<a)&&a_used) != 0)
        return solve(win, a+1, b, a_used);

    if(cache[win][a][b] != -1)
        return cache[win][a][b];

    long long count = 0;

    if(A[a] > B[b]) {

        count += (1+solve(win-1, a+1, b+1, a_used||(1<<a)));

        for(int i=a; a<N; i++)
            if(A[i] > B[b])
                count += (1+solve(win-1, a+1, b, a_used||(1<<i)));
    }
    else {
        count += solve(win, a+1, b+1, a_used||(1<<a));

        for(int i=0; a<N; i++)
            if(A[i]<B[b] && ((1<<i)&&a_used)==0)
                count += solve(win, a, b+1, a_used||(1<<a));
    }

    return count%MOD;
}

int main() {

    FILE *fp = freopen("../data/4701.input", "r", stdin);
    if(!fp)
        perror("freopen error");

    scanf("%d", &tc);
    t = 0;
    while(t++ < tc) {

        scanf("%d", &N);

        for(int i=0; i<N; i++)
            scanf("%d", &A[i]);
        for(int i=0; i<N; i++)
            scanf("%d", &B[i]);

        sort(A, A+N, greater<int>());
        sort(B, B+N), greater<int>();

        for(int i=0; i<N+1; i++)
            for(int j=0; j<N; j++)
                for(int k=0; k<N; k++)
                    cache[i][j][k] = -1;

//        for(int i=0; i<N; i++)
//            cout << A[i] << " ";

        printf("#%d", t);

        for(int i=0; i<N+1; i++)
            printf(" %lld", solve(i, 0, 0, 0));
        printf("\n");
    }

    return 0;
}