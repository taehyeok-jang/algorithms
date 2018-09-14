#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int dx[4] = {0, 1, 0, 1};
int dy[4] = {0, 0, 1, 1};

struct block {
    char c;
    bool b;
};

int clear(int m, int n, vector<vector<block>> &map){

    bool block;
    for(int x=0; x<m-1; x++) {
        for(int y=0; y<n-1; y++) {
            if(map[x][y].c == '0') continue;

            block = 1;
            for(int d=0; d<3; d++)
                if(map[x+dx[d]][y+dy[d]].c!=map[x+dx[d+1]][y+dy[d+1]].c)
                    block = 0;
            if(block)
                for(int d=0; d<4; d++)
                    map[x+dx[d]][y+dy[d]].b = 1;
        }
    }
    int count = 0;
    for(int x=0; x<m; x++)
        for(int y=0; y<n; y++)
            if(map[x][y].b==1)
                count++, map[x][y].c = '0', map[x][y].b = 0;
    return count;
}

void move(int m, int n, vector<vector<block>> &map) {

    queue<char> q;
    for(int y=0; y<n; y++) {
        while(q.size()>0) q.pop();

        for(int x=m-1; x>=0; x--)
            if(map[x][y].c!='0')
                q.push(map[x][y].c);

        int x = m-1;
        while(q.size()>0) { map[x][y].c = q.front(); q.pop(); x--; }
        while(x>=0) { map[x][y].c = '0'; x--; }
    }
}

int solution(int m, int n, vector<string> board) {

    vector<vector<block>> map(m);
    for(int i=0; i<m; i++) map[i].resize(n);

    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
            map[i][j].c = board[i][j];
    int ans = 0;
    while(true) {
        int c = clear(m, n, map);
        if(c==0) break;
        ans += c;
        move(m, n, map);
    }

    return ans;
}

int main() {

    int m[2] = {4, 6};
    int n[2] = {5, 6};
    vector<vector<string>> input(2);
    input[0] = {"CCBDE", "AAADE", "AAABF", "CCBBF"};
    input[1] = {"TTTANT", "RRFACC", "RRRFCC", "TRRRAA", "TTMMMF", "TMMTTJ"};

    for(int i=0; i<2; i++)
        cout << solution(m[i], n[i], input[i]) << "\n";

    return 0;
}