#include <stdio.h>
#include <cmath>

using namespace std;

#define MAX 501
int arr[MAX][MAX];
int N;

int max(int a, int b) { return a>b? a:b; }

int main() {

    scanf("%d", &N);
    for(int i=0; i<N; i++)
        for(int j=0; j<i+1; j++)
            scanf("%d", &arr[i][j]);

    for(int i=0; i<N-1; i++) {
        arr[i+1][0] += arr[i][0];
        arr[i+1][i+1] += arr[i][i];
        for(int j=1; j<i+1; j++)
            arr[i+1][j] += max(arr[i][j-1], arr[i][j]);
    }

    int ans = 0;
    for(int i=0; i<N; i++)
        ans = max(ans, arr[N-1][i]);
    printf("%d", ans);

    return 0;
}
