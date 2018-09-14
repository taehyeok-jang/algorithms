#include <stdio.h>
#include <algorithm>
#include <vector>

#define MAX 4001
using namespace std;

int N;
int arr[4][MAX];
vector<int> L, R;

int main() {

    scanf("%d", &N);
    for(int i=0; i<N; i++)
        for(int j=0; j<4; j++)
            scanf("%d", &arr[j][i]);

    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            L.push_back(arr[0][i]+arr[1][j]);
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            R.push_back(arr[2][i]+arr[3][j]);

    sort(L.begin(), L.end());
    sort(R.begin(), R.end());

    long long ans = 0;
    for(int i=0; i<L.size(); i++) {
        auto l = lower_bound(R.begin(), R.end(), -L[i]);
        auto r = upper_bound(R.begin(), R.end(), -L[i]);
        ans += r-l;
    }

    printf("%lld", ans);
    return 0;
}


/*
 *
 * other's source.
 *
 * instead of using bound_function, binary search + linear search.
 *
#include <cstdio>
#include <algorithm>
using namespace std;

int a[4000], b[4000], c[4000], d[4000];
int sum[16000000], dp[16000000] = {0};

int si = 0;

int same(int mid) {
	if (dp[mid]) return dp[mid];

	int cnt = 1;
	int t1 = mid, t2 = mid;

	while (t1 > 0 && sum[t1] == sum[t1 - 1]) { cnt++; t1--; }
	while (t2 < si - 1 && sum[t2] == sum[t2 + 1]) { cnt++; t2++; }

	for (int i = t1; i <= t2; i++)
		dp[i] = cnt;

	return cnt;
}

int main() {
	int n, ci = 0, di = 0;
	int l, r, mid, t1;
	long long cnt = 0;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf("%d %d %d %d", &a[i], &b[i], &c[i], &d[i]);
	sort(c, c + n), sort(d, d + n);

	for(int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			sum[si++] = c[i] + d[j];

	sort(sum, sum + si);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			l = 0, r = si - 1;
			t1 = a[i] + b[j];

			while (l <= r) {
				mid = (l + r) / 2;
				if (sum[mid] + t1 > 0) r = mid - 1;
				else if (sum[mid] + t1 < 0) l = mid + 1;
				else { cnt += same(mid); break; }
			}
		}

	printf("%lld", cnt);
}

 */