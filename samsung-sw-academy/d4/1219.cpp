#include <iostream>
#include <vector>

using namespace std;

int tc, t, tt;
int E;
int EDGE[2][100];
int USED[2][100];

bool DEBUG = false;

bool solve(int v) {

    if(v == 99)
        return true;
    if(USED[0][v]&&USED[1][v])
        return false;

    bool a = false;
    bool b = false;

    if(!USED[0][v]) {
        USED[0][v] = true;
        a = solve(EDGE[0][v]);
    }
    if(!USED[1][v]) {
        USED[1][v] = true;
        b = solve(EDGE[1][v]);
    }

    return a||b;
}

int main() {

//    FILE *fp = freopen("../data/1219.input", "r", stdin);
//    if(!fp)
//        perror("freopen error");

    tc = 10;
    t = 0;
    while(t++ < tc) {

        scanf("%d%d", &tt, &E);

        for(int i=0; i<2; i++) {
            for(int j=0; j<100; j++) {
                EDGE[i][j] = -1;
                USED[i][j] = false;
            }
        }

        for(int i=0; i<E; i++) {
            int a, b;
            scanf("%d%d", &a, &b);
            if(EDGE[0][a] == -1) EDGE[0][a] = b;
            else                 EDGE[1][a] = b;
        }
//        for(int i=0; i<2; i++) {
//            for (int j = 0; j < 100; j++) {
////                if(EDGE[i][j] != -1)
////                    cout << j << ", " << EDGE[i][j] << "\n";
//            }
//        }

        printf("#%d %d\n", t, solve(0));
    }

    return 0;
}