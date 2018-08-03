#include <iostream>
#include <vector>

using namespace std;

int tc, t;
int R, C;
char MAP[20][20];

bool visited[16][4][20][20];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

bool DEBUG = false;

pair<int, int> next_coord(pair<int, int> coord, int d) {

    int nx = (coord.first+dx[d]+R)%R;
    int ny = (coord.second+dy[d]+C)%C;

    return make_pair(nx, ny);
}

bool is_num(char c) {

    return c>=48&&c<58;
}

int solve(int m, int d, pair<int, int> coord) {

//    cout << coord.first << "," << coord.second << ": " << MAP[coord.first][coord.second] << "\n";

    if(visited[m][d][coord.first][coord.second])
        return false;

    visited[m][d][coord.first][coord.second] = true;

    switch(MAP[coord.first][coord.second]) {
        case '<':   return solve(m, 3, next_coord(coord, 3));
        case '>':   return solve(m, 1, next_coord(coord, 1));
        case '^':   return solve(m, 0, next_coord(coord, 0));
        case 'v':   return solve(m, 2, next_coord(coord, 2));
        case '_':   if(m == 0)  return solve(m, 1, next_coord(coord, 1));
                    else        return solve(m, 3, next_coord(coord, 3));
        case '|':   if(m == 0)  return solve(m, 2, next_coord(coord, 2));
                    else        return solve(m, 0, next_coord(coord, 0));
        case '?':   return solve(m, 0, next_coord(coord, 0)) || solve(m, 1, next_coord(coord, 1)) ||
                            solve(m, 2, next_coord(coord, 2)) || solve(m, 3, next_coord(coord, 3));
        case '.':   return solve(m, d, next_coord(coord, d));
        case '@':   return 1;
        case '+':   return solve((m+1)%16, d, next_coord(coord, d));
        case '-':   return solve((m+15)%16, d, next_coord(coord, d));
        default:    if(is_num(MAP[coord.first][coord.second]))
                        return solve(MAP[coord.first][coord.second]-48, d, next_coord(coord, d));
                    else {
                        cout << "error occured." << "\n";
                        return 0;
                    }
    }
}

int main() {

//    FILE *fp = freopen("../data/1824.input", "r", stdin);
//    if(!fp)
//        perror("freopen error");

    scanf("%d", &tc);
    t = 0;
    while(t++ < tc) {

        scanf("%d%d", &R, &C);

        for(int i=0; i<R; i++) {
            char buf[20];
            scanf("%s", buf);
            for(int j=0; j<C; j++)
                MAP[i][j] = buf[j];
        }

        for(int m=0; m<16; m++)
            for(int d=0; d<4; d++)
                for(int x=0; x<20; x++)
                    for(int y=0; y<20; y++)
                        visited[m][d][x][y] = false;

        string s = solve(0, 1, make_pair(0, 0))? "YES": "NO";
        printf("#%d %s\n", t, s.c_str());
    }

    return 0;
}