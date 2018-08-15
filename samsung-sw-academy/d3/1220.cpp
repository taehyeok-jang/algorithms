#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

int tc, t;
int size;
int map[100][100];

bool DEBUG = false;

int solve(int col) {

    int state = 0;
    int cnt = 0;
    for(int i=0; i<size; i++) {
        if(map[i][col] == 1) {
            state = 1;
        }
        else if(map[i][col] == 2) {
            if(state == 1) cnt++;
            state = 2;
        }
    }
    return cnt;
}

int main() {

//    FILE *fp = freopen("../data/3501.input", "r", stdin);
//    if(!fp)
//        perror("freopen error");

//    scanf("%d", &tc);
    tc = 10;
    t = 0;
    while(t++ < tc) {

        scanf("%d", &size);
        for(int i=0; i<size; i++)
            for(int j=0; j<size; j++)
                scanf("%d", &map[i][j]);

        int cnt = 0;
        for(int c=0; c<size; c++)
            cnt += solve(c);

        printf("#%d %d\n", t, cnt);
    }

    return 0;
}
