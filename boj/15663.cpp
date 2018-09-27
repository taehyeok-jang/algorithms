#include <stdio.h>
#include <algorithm>

int N, M, S;
int A[11], B[11], result[11];
bool check[11];

void dfs(int k) {

    if(k==M) {
        for(int i=0; i<M; i++)
            printf("%d ", result[i]);
        printf("\n");
        return;
    }

    for(int i=0; i<S; i++) {
        if(check[i]) continue;
        check[i] = 1;
        result[k] = B[i];
        dfs(k+1);
        check[i] = 0;
    }
}

#include <iostream>

using namespace std;

int main() {

    scanf("%d%d", &N, &M);
    for(int i=0; i<N; i++)
        scanf("%d", &A[i]);
    std::sort(A, A+N);
    for(int i=0; i<N; i++)
        cout << A[i] << " ";
    cout << "\n";

//    int i = 0, j = 0;
//    int tmp = -1;
//    while(i<N) {
//        cout << tmp << " " << i << ": " << A[i] << "\n";
//        if(A[i]==tmp) i++;
//        else { B[j++] = tmp = A[i++]; }
//    }
//
//    S = j;
//    for(int k=0; k<j; k++)
//        printf("%d ", B[k]);


    dfs(0);
    return 0;
}
