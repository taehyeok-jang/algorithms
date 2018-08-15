#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

int M, N;
int map[51][51];
int visited[51][51], visited2[51][51];
struct room {
    int x, y, area;
    room(int a, int b, int c) { x=a, y=b, area=c; }
};
vector<room> rooms;
bool DEBUG = false;

bool out_of_bound(int x, int y) { return x<0||x>=M||y<0||y>=N; }

int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};

int dfs(int x, int y, int num) {

    if(visited[x][y]) return 0;
    visited[x][y] = num;
    int a = 1;
    for(int d=0; d<4; d++) {
        if(out_of_bound(x+dx[d], y+dy[d]))
            continue;
        if(((1<<d)&map[x][y]))
            continue;

        a += dfs(x+dx[d], y+dy[d], num);
    }
    return a;
}

int main() {

//    FILE *fp = freopen("../data/3501.input", "r", stdin);
//    if(!fp)
//        perror("freopen error");

    scanf("%d%d", &N, &M);
    for(int i=0; i<M; i++)
        for(int j=0; j<N; j++)
            scanf("%d", &map[i][j]);
    memset(visited, 0, sizeof(bool)*51*51);
    memset(visited2, 0, sizeof(bool)*51*51);

    int num = 0;
    int area, max_area = -1;
    for(int x=0; x<M; x++) {
        for(int y=0; y<N; y++) {
            if(!visited[x][y]) {
                num++;
                area = dfs(x, y, num);
                max_area = max(max_area, area);
                rooms.push_back(room(x, y, area));
            }
        }
    }

    int merge_area = -1;
    int a, b;
    for(int i=0; i<M-1; i++) {
        for(int j=0; j<N; j++) {
            a=visited[i][j]-1, b=visited[i+1][j]-1;
            if(a!=b) merge_area = max(merge_area, rooms[a].area+rooms[b].area);
        }
    }
    for(int i=0; i<M; i++) {
        for(int j=0; j<N-1; j++) {
            a=visited[i][j]-1, b=visited[i][j+1]-1;
            if(a!=b) merge_area = max(merge_area, rooms[a].area+rooms[b].area);
        }
    }

    cout << num << "\n";
    cout << max_area << "\n";
    cout << merge_area << "\n";

    return 0;
}
