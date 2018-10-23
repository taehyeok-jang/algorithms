#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int tc, t;
int M, N;
int y, x, c, p;
int A[105], B[105];
struct bc {
    int id, c, p;
    bool operator < (const bc &bc2) const { return p > bc2.p; }
};
vector<bc> map[10][10];

int dy[5] = { 0, -1, 0, 1, 0 };
int dx[5] = { 0, 0, 1, 0, -1 };

int abs(int n) { return n > 0 ? n : -n; }
int max(int a, int b) { return a > b ? a : b; }
bool out_of_bounds(int y, int x) { return y < 0 || y >= 10 || x < 0 || x >= 10; }

int main() {
    cin >> tc;
    t = 0;
    while (t++ < tc) {
        for (int i = 0; i < 10; i++)
            for (int j = 0; j < 10; j++)
                map[i][j].clear();
        cin >> M >> N;
        A[0] = 0, B[0] = 0;
        for (int i = 1; i < M+1; i++) cin >> A[i];
        for (int i = 1; i < M+1; i++) cin >> B[i];
        while (N--) {
            cin >> x >> y >> c >> p;
            x--, y--;
            for (int i = y - c; i <= y + c; i++) {
                for (int j = x - c; j <= x + c; j++) {
                    if (out_of_bounds(i, j)) continue;
                    if (abs(i - y) + abs(j - x) <= c) map[i][j].push_back({N, c, p });
                }
            }
        }
        for (int i = 0; i < 10; i++)
            for (int j = 0; j < 10; j++)
                sort(map[i][j].begin(), map[i][j].end());

        int ans = 0, y1, x1, y2, x2, charge;
        y1 = 0, x1 = 0, y2 = 9, x2 = 9;
        for (int i = 0; i < M+1; i++) {
            y1 += dy[A[i]], x1 += dx[A[i]];
            y2 += dy[B[i]], x2 += dx[B[i]];
            charge = 0;
            if (map[y1][x1].size() && map[y2][x2].size()) {
                for (int j = 0; j < map[y1][x1].size(); j++) {
                    for (int k = 0; k < map[y2][x2].size(); k++) {
                        if (map[y1][x1][j].id == map[y2][x2][k].id) charge = max(charge, max(map[y1][x1][j].p, map[y2][x2][k].p));
                        else charge = max(charge, map[y1][x1][j].p + map[y2][x2][k].p);
                    }
                }
            }
            else {
                if (map[y1][x1].size()) charge = map[y1][x1][0].p;
                if (map[y2][x2].size()) charge = map[y2][x2][0].p;
            }
            ans += charge;
        }
        cout << "#" << t << " " << ans << "\n";
    }


    return 0;
}