#include <iostream>
#include <vector>

using namespace std;

#define MAX 1001
int tc, t;
int N, M;
int MAP[MAX][MAX];

int cache[4][MAX][MAX];

#define UNDEFINED -97654321

bool DEBUG = false;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int solve(int prev_d, int x, int y) {

//    cout << prev_d << " ...  " << x << ", " << y << "\n\n";
    if(x==N-1&&y==M-1) return MAP[x][y];
    if(cache[prev_d][x][y] != UNDEFINED) return cache[prev_d][x][y];

    int max_score = UNDEFINED;
    if(prev_d == 1) {
        if(y+1<M)   max_score = max(max_score, solve(1, x, y+1)+MAP[x][y]);
        if(x+1<N)   max_score = max(max_score, solve(2, x+1, y)+MAP[x][y]);
    }
    else if(prev_d == 3) {
        if(y-1>=0)  max_score = max(max_score, solve(3, x, y-1)+MAP[x][y]);
        if(x+1<N)   max_score = max(max_score, solve(2, x+1, y)+MAP[x][y]);
    }
    else { // prev_d == 0, 2
        if(y+1<M)   max_score = max(max_score, solve(1, x, y+1)+MAP[x][y]);
        if(y-1>=0)  max_score = max(max_score, solve(3, x, y-1)+MAP[x][y]);
        if(x+1<N)   max_score = max(max_score, solve(2, x+1, y)+MAP[x][y]);
    }

    return cache[prev_d][x][y] = max_score;
}

int main() {

    tc = 1;
    t = 0;
    while(t++ < tc) {

        scanf("%d%d", &N, &M);
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
                scanf("%d", &MAP[i][j]);

        for(int i=0; i<4; i++)
            for(int j=0; j<N; j++)
                for(int k=0; k<M; k++)
                    cache[i][j][k] = UNDEFINED;

        printf("%d", solve(0, 0, 0));
    }

    return 0;
}