#include<stdio.h>
#include<algorithm>
using namespace std;
#define MAX 1001
int data[MAX], data2[MAX*MAX], cnt, N;
int main() {

    int i, j;
    scanf("%d", &N);
    for(i=0; i<N; i++) scanf("%d", &data[i]);
    sort(data, data+N);

    for(i=0; i<N; i++)
        for(j=i; j<N; j++)
            data2[cnt++] = data[i]+data[j];
    sort(data2, data2+cnt);

    for(i=N-1; i>=0; i--) {
        for(j=i;j>=0; j--) {
            if(binary_search(data2, data2+cnt, data[i] - data[j])) {
                printf("%d", data[i]);
                break;
            }
        }
        if(j>0)
            break;
    }
    return 0;
}
