#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;

int tc, t;
int N;
int map[100][100];

bool DEBUG = false;

int main() {

//    FILE *fp = freopen("../data/3501.input", "r", stdin);
//    if(!fp)
//        perror("freopen error");

//    scanf("%d", &tc);
    tc = 10;
    t = 0;
    while(t++ < tc) {

        scanf("%d", &N);
        for(int i=0; i<100; i++)
            for(int j=0; j<100; j++)
                scanf("%d", &map[i][j]);

        int m = 0;
        int sum;

        for(int i=0; i<100; i++) {
            sum = 0;
            for(int j=0; j<100; j++) sum += map[i][j];
            m = max(m, sum);
        }
        for(int i=0; i<100; i++) {
            sum = 0;
            for(int j=0; j<100; j++) sum += map[j][i];
            m = max(m, sum);
        }
        sum = 0;
        for(int i=0; i<100; i++) sum += map[i][i];
        m = max(m, sum);
        sum = 0;
        for(int i=0; i<100; i++) sum += map[i][99-i];
        m = max(m, sum);

//        for(int i=0; i<100; i++) {
//            for(int j=0; j<100; j++) cout << map[i][j] << " ";
//            cout << "\n";
//        }


        printf("#%d %d\n", t, m);
    }

    return 0;
}
