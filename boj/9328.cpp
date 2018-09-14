#include <iostream>
#include <vector>
#include <cstring>

#define MAX 102
#define ALPHA_SIZE 26
using namespace std;

vector<pair<int, int> > v;

int h, w;
char map[MAX][MAX];
bool visited[MAX][MAX];
bool key[ALPHA_SIZE];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
bool flag;

bool out_of_bounds(int x, int y) { return x<0||x>h+1||y<0||y>w+1; }

int dfs(int x, int y) {
    int ret = 0;
    visited[x][y] = 1;

    if(map[x][y]=='$') ret++;
    else if(map[x][y]>='a'&&map[x][y]<='z') {
        key[map[x][y]-'a'] = 1;
        flag = 1;
    }

    for(int d=0; d<4; d++) {
        int nx = x+dx[d];
        int ny = y+dy[d];
        if(out_of_bounds(nx, ny)) continue;
        if(map[nx][ny]=='*'||visited[nx][ny]) continue;

        if(map[nx][ny]>='A'&&map[nx][ny]<='Z'&&!key[map[nx][ny]-'A']) {
            v.push_back(make_pair(nx, ny));
            continue;
        }
        ret += dfs(nx, ny);
    }

    return ret;
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--) {

        memset(visited, 0, sizeof(visited));
        memset(key, 0, sizeof(key));
        memset(map, 0, sizeof(map));
        v.clear();

        scanf("%d %d", &h, &w);
        getchar();

        for(int i=1; i<h+1; i++) {
            for(int j=1; j<w+1; j++)
                map[i][j] = getchar();
            getchar();
        }

        while(1) {
            char c = getchar();
            if(c == '0' || c == '\n') break;
            else key[c - 'a'] = 1;
        }

        int ret = dfs(0, 0);
        while(1) {
            flag = 0;
            for(int i=0; i<v.size(); i++)
                if(key[map[v[i].first][v[i].second]-'A'])
                    ret += dfs(v[i].first, v[i].second);
            if(flag==0)
                break;
        }

        printf("%d\n", ret);
    }
    return 0;
}
