#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int N, S;
int A[41];
vector<int> L, R;

void dfs(int l, int r, int sum, int c) { // l <= x < r.

    if(l==r) {
        if(c==0) L.push_back(sum);
        else     R.push_back(sum);
        return;
    }
    dfs(l+1, r, sum, c);
    dfs(l+1, r, sum+A[l], c);
}

int lower_bound(vector<int> &v, int val, int size) {

    int l, r, m;
    l = 0, r = size;
    while(l<r) {
        m = (l+r)/2;
        if(v[m]>=val) r = m;
        else          l = m+1;
    }
    return r;
}

int upper_bound(vector<int> &v, int val, int size) {

    int l, r, m;
    l = 0, r = size;
    while(l<r) {
        m = (l+r)/2;
        if(v[m]>val) r = m;
        else         l = m+1;
    }
    return r;
}

int main() {

    scanf("%d%d", &N, &S);
    for(int i=0; i<N; i++) scanf("%d", &A[i]);

    dfs(0, N/2, 0, 0);
    dfs(N/2, N, 0, 1);

    sort(L.begin(), L.end());
    sort(R.begin(), R.end());

    long long ans = 0;
    int l, r;
    for(int i=0; i<L.size(); i++) {
        int p = S-L[i];
        l = lower_bound(R, p, R.size());
        r = upper_bound(R, p, R.size());
        ans += r-l;
    }

    if(S==0) ans--;
    printf("%lld", ans);
    return 0;
}
