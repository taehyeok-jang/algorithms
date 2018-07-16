#include <iostream>
#include <vector>
#include <set>
#include <cmath>

using namespace std;

int tc, t;
int MAP[4][4];

#define MAX 10000000

vector<int> vec;
//set<int> comb;
bool exist[MAX];
int answer;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

bool DEBUG = false;

void dfs(int x, int y, int depth, int num) {

    if(depth == 7) {
        if(!exist[num]) {
//            cout << num << "\n";
            exist[num] = true;
            answer++;
        }
        return;
    }

    for(int i=0; i<4; i++)
        if((x+dx[i]>=0&&x+dx[i]<4)&&(y+dy[i]>=0&&y+dy[i]<4))
            dfs(x+dx[i], y+dy[i], depth+1, num+MAP[x][y]*(int)pow(10, depth));
}

int main() {

//    FILE *fp = freopen("../data/2819.input", "r", stdin);
//    if(!fp)
//        perror("freopen error");

    scanf("%d", &tc);
    t = 0;
    while(t++ < tc) {

        for(int i=0; i<4; i++)
            for(int j=0; j<4; j++)
                scanf("%d", &MAP[i][j]);

        for(int i=0; i<MAX; i++)
            exist[i] = false;

        answer = 0;
        for(int i=0; i<4; i++)
            for(int j=0; j<4; j++)
                dfs(i, j, 0, 0);

        printf("#%d %d\n", t, answer);
    }

    return 0;
}