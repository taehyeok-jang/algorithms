#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

int arr[1000001];
int N;
long long M;

int main() {

    scanf("%d%lld", &N, &M);
    for(int i=0; i<N; i++) scanf("%d", &arr[i]);
    sort(arr, arr+N);

    vector<int> v;
    int l, r, m, ans = -1;
    long long sum;
    l = 0, r = arr[N-1];
    while(l<=r) {
        m = (l+r)/2;
        sum = 0;
        for(int i=0; i<N; i++)
            if(arr[i]>m) sum += (arr[i]-m);
        if(sum==M) { ans = m; break; }
        if(sum>M) l = m+1, ans = max(ans, m);
        else      r = m-1;
    }

    printf("%d", ans);
    return 0;
}



