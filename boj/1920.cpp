#include <stdio.h>
#include <algorithm>
#include <cstring>

using namespace std;

int arr[500001];
int N, M;


int binary_search(int arr[], int val, int size) {

    int l, r, m;
    l = 0, r = size;
    while(l<=r) {
        m = (l+r)/2;
        if(arr[m]==val) return m;
        if(arr[m]>val) r = m-1;
        else           l = m+1;
    }
    return -1;
}

int main() {

    scanf("%d", &N);
    for(int i=0; i<N; i++) scanf("%d", &arr[i]);
    sort(arr, arr+N);

    scanf("%d", &M);
    int t, idx;
    for(int i=0; i<M; i++) {
        scanf("%d", &t);
        idx = binary_search(arr, t, N);
        printf("%d ", idx==-1? 0:1);
    }

    return 0;
}
