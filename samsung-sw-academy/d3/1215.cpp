#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;

int tc, t;
int L;
char map[8][8], buf[8];
bool DEBUG = false;

int main() {

//    FILE *fp = freopen("../data/3501.input", "r", stdin);
//    if(!fp)
//        perror("freopen error");

//    scanf("%d", &tc);
    tc = 10;
    t = 0;
    while(t++ < tc) {

        scanf("%d", &L);
        for(int i=0; i<8; i++) {
            scanf("%s", buf);
            for(int j=0; j<8; j++) map[i][j] = buf[j];
        }

        int count = 0;
        int a, b;

        for(int x=0; x<8; x++) {
            for(int y=0; y<8-L+1; y++) {
                a = y, b = y+L-1;
                while(a<b&&map[x][a]==map[x][b]) a++, b--;
                if(a>=b) count++;
            }
        }
        for(int y=0; y<8; y++) {
            for(int x=0; x<8-L+1; x++) {
                a = x, b = x+L-1;
                while(a<b&&map[a][y]==map[b][y]) a++, b--;
                if(a>=b) count++;
            }
        }

        printf("#%d %d\n", t, count);
    }

    return 0;
}
