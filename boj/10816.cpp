#include <stdio.h>
#include <algorithm>

using namespace std;

int arr[500001];
int N, M;

int upper_bound(int arr[], int val, int size) {

    int l, r, m;
    l = 0, r = size;
    while(l<r) {
        m = (l+r)/2;
        if(arr[m]>val) r = m;
        else           l = m+1;
    }
    return r;
}

int lower_bound(int arr[], int val, int size) {

    int l, r, m;
    l = 0, r = size;
    while(l<r) {
        m = (l+r)/2;
        if(arr[m]>=val) r = m;
        else            l = m+1;
    }
    return r;
}

int main() {

    scanf("%d", &N);
    for(int i=0; i<N; i++) scanf("%d", &arr[i]);
    sort(arr, arr+N);

    scanf("%d", &M);
    int t, l, r;
    for(int i=0; i<M; i++) {
        scanf("%d", &t);
        l = lower_bound(arr, t, N);
        r = upper_bound(arr, t, N);
        printf("%d ", r-l);
    }
    return 0;
}
