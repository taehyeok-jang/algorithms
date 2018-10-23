/*
#include<iostream>
#include<vector>
using namespace std;
int N;
int map[101][101];
int dy[4] = { 0, -1, 0, 1 };
int dx[4] = { 1, 0, -1, 0 };
struct point { int x, y; };
struct curve { int g; vector<point> st; } curves[21];
point rotate(point p, point org) {
	int x, y;
	x = p.x - org.x, y = p.y - org.y;
	return point({ -y + org.x, x + org.y });
}
int main() {
	cin >> N;
	int x, y, d, g;
	for (int i = 0; i < N; i++) {
		cin >> x >> y >> d >> g;
		curves[i].g = g;
		curves[i].st.push_back(point{ x, y });
		curves[i].st.push_back(point{ x+dx[d], y+dy[d] });
	}
	bool flag = 1;
	while (flag) {
		flag = 0;
		for (int i = 0; i < N; i++) {
			if (curves[i].g == 0) continue;
			flag = 1;
			point org = curves[i].st.back();
			for (int j = curves[i].st.size() - 2; j >= 0; j--)
				curves[i].st.push_back(rotate(curves[i].st[j], org));
			curves[i].g -= 1;
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < curves[i].st.size(); j++) {
			point p = curves[i].st[j];
			map[p.x][p.y] = 1;
		}
	}
	int ans = 0;
	for (int i = 0; i < 100; i++)
		for (int j = 0; j < 100; j++)
			if (map[i][j] == 1 && map[i + 1][j] == 1 && map[i][j + 1] == 1 && map[i + 1][j + 1] == 1)
				ans++;
	cout << ans;
	return 0;
}*/

/**
 * referenced from https://www.acmicpc.net/source/8413842
 * code author: kdk8361
 */
#include<stdio.h>
int main() {
    int dir[1<<12] = {0, };
    int map[101][101] = {0, };
    int dx[] = { 1,0,-1,0 }, dy[] = { 0,-1,0,1 };

    for(int i=0, cur = 2; i<10; i++, cur <<= 1)
        for(int j=cur/2; j<cur; j++)
            dir[j] = (dir[cur-j-1]+1)%4;

    int n, x, y, d, g;
    scanf("%d", &n);
    while(n--) {
        scanf("%d%d%d%d", &x, &y, &d, &g);
        map[y][x] = 1;
        for(int i=0; i<(1<<g); i++) {
            x += dx[(dir[i]+d)%4];
            y += dy[(dir[i]+d)%4];
            map[y][x] = 1;
        }
    }
    int ans = 0;
    for(int i=0; i<100; i++)
        for(int j=0; j<100; j++)
            ans += map[i][j]&map[i+1][j]&map[i][j+1]&map[i+1][j+1];
    printf("%d", ans);
    return 0;
}