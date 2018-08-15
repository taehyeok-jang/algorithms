#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;

int tc, t;
int N;
char map[100][100], buf[100];
int cache[100][100][100][2];
int MAX;

bool DEBUG = false;

bool is_pal(int a, int b, int c, int hv) {

    if(a>=b) return 1;
    if(cache[a][b][c][hv] != -1) return cache[a][b][c][hv];

    is_pal(a+1, b, c, hv); // TODO
    is_pal(a, b-1, c, hv);

    bool pal = 0;
    if(hv==0&&(map[c][a]==map[c][b]))       pal =  is_pal(a+1, b-1, c, hv);
    else if(hv==1&&(map[a][c]==map[b][c]))  pal =  is_pal(a+1, b-1, c, hv);

    if(pal) { MAX = max(MAX, b-a+1); return cache[a][b][c][hv] = 1; }
    else    { return cache[a][b][c][hv] = 0; }
}

int main() {

//    FILE *fp = freopen("../data/3501.input", "r", stdin);
//    if(!fp)
//        perror("freopen error");

    scanf("%d", &tc);
    tc = 10;
    t = 0;
    while(t++ < tc) {

        scanf("%d", &N);
        for(int i=0; i<100; i++) {
            scanf("%s", buf);
            for(int j=0; j<100; j++) map[i][j] = buf[j];
        }
        for(int i=0; i<100; i++)
            for(int j=0; j<100; j++)
                for(int k=0; k<100; k++)
                    cache[i][j][k][0] = -1, cache[i][j][k][1] = -1;

        MAX = -1;
        for(int x=0; x<100; x++) is_pal(0, 99, x, 0);
        for(int y=0; y<100; y++) is_pal(0, 99, y, 1);

        printf("#%d %d\n", t, MAX);
    }

    return 0;
}
