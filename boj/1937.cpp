#include<iostream>
using namespace std;
int N;
int map[501][501], dp[501][501];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int max(int a, int b) { return a > b ? a : b; }
bool out_of_bounds(int x, int y) { return x < 0 || x >= N || y < 0 || y >= N; }

int solve(int x, int y) {
	// no cycle -> visited not needed.
	if (dp[x][y] != -1) return dp[x][y];
	int cnt = 0;
	int nx, ny;
	for (int d = 0; d < 4; d++) {
		nx = x + dx[d], ny = y + dy[d];
		if (out_of_bounds(nx, ny) || map[nx][ny] <= map[x][y]) continue;
		cnt = max(cnt, solve(nx, ny));
	}
	return dp[x][y] = 1+cnt;
}

int main() {
	ios::sync_with_stdio(false);
    cin.tie(NULL);
//	cin >> N;
//	for (int i = 0; i < N; i++)
//		for (int j = 0; j < N; j++)
//			cin >> map[i][j];
    N = 500; bool flag = 1; int k = 500*500;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(flag) map[i][j] = k--;
            else     map[i][N-j-1] = k--;
        }
        flag ^= 1;
    }
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			dp[i][j] = -1;
	int ans = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
				ans = max(ans, solve(i, j));
	cout << ans;
	return 0;
}

/**
    N = 500; bool flag = 1; int k = 500*500;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(flag) map[i][j] = k--;
            else     map[i][N-j-1] = k--;
        }
        flag ^= 1;
    }
 */

