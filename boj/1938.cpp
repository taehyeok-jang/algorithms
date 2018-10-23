#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct point {
	int x, y, d;
	bool operator == (const point &p2) const { return (x == p2.x&&y == p2.y) && d == p2.d; }
};
int N;
char map[51][51];
int visited[51][51][2]; // x, y, d.
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int ddx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int ddy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
queue<point> q;

bool out_of_bounds(int x, int y) { return x < 0 || x >= N || y < 0 || y >= N; }
bool stick_out_of_bounds(int px, int py, int d) {
	if (d == 0)	return out_of_bounds(px, py - 1) || out_of_bounds(px, py + 1);
	else		return out_of_bounds(px - 1, py) || out_of_bounds(px + 1, py);
}
bool is_obstacle(int px, int py, int d) {
	if (d == 0)	return map[px][py - 1] == '1'||map[px][py]=='1'||map[px][py + 1] == '1';
	else		return map[px - 1][py] == '1' || map[px][py] == '1' ||map[px + 1][py] == '1';
}
bool can_rotate(int px, int py) {
	int nx, ny;
	for (int d = 0; d < 8; d++) {
		nx = px + ddx[d], ny = py + ddy[d];
		if (out_of_bounds(nx, ny)) return 0;
		if (map[nx][ny] != '0') return 0;
	}
	return 1;
}

point find(char c) {
	int idx = 0;
	int x[3] = { 0, }, y[3] = { 0, };
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (map[i][j] == c)
				x[idx] = i, y[idx] = j, idx++;
	int cx = 0, cy = 0, d;
	for (int i = 0; i < 3; i++)
		cx += x[i], cy += y[i];
	if (x[0] == x[1])	d = 0; // horizontal.
	else				d = 1; // vertical.
	return point({ cx/3, cy/3, d });
}


int main() {
	cin >> N;
	string s;
	for (int i = 0; i < N; i++)
		cin >> map[i];

	point start = find('B');
	point end = find('E');

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (map[i][j] != '1')
				map[i][j] = '0';

	q.push(start);
	visited[start.x][start.y][start.d] = 1;
	
	int cnt = 0; bool solved = 0;
	while(!q.empty()) {
		int size = q.size();
		while (size--) {
			point cur = q.front(); q.pop();
			if (cur == end) {
				solved = 1;
				break;
			}
			// shift
			int nx, ny;
			for (int d = 0; d < 4; d++) {
				nx = cur.x + dx[d], ny = cur.y + dy[d];
				if (stick_out_of_bounds(nx, ny, cur.d)) continue;
				if (visited[nx][ny][cur.d]||is_obstacle(nx, ny, cur.d)) continue;
				q.push(point({ nx, ny, cur.d }));
				visited[nx][ny][cur.d] = 1;
			}
			// rotate 
			int nd = (cur.d + 1) % 2;
			if (stick_out_of_bounds(cur.x, cur.y, nd)) continue;
			if (visited[cur.x][cur.y][nd]||!can_rotate(cur.x, cur.y)) continue;
			q.push(point({ cur.x, cur.y, nd }));
			visited[cur.x][cur.y][nd] = 1;
		}
		if (solved) break;
		cnt++;
	}
	if(solved)  cout << cnt;
	else		cout << (0);
	return 0;
}