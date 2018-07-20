#include <iostream>
#include <vector>

using namespace std;

int tc, t;
int MAP[100][100];

int dy[2] = {1, -1};

bool DEBUG = false;

int main() {

//    FILE *fp = freopen("../data/1210.input", "r", stdin);
//    if(!fp)
//        perror("freopen error");

//    scanf("%d", &tc);
    tc = 10;
    t = 0;
    while(t++ < tc) {

        int n;
        scanf("%d", &n);

        for(int i=0; i<100; i++)
            for(int j=0; j<100; j++)
                scanf("%d", &MAP[i][j]);

        int start_y = -1;
        for(int i=0; i<100; i++) {
            if(MAP[99][i] == 2) {
                start_y = i;
                break;
            }
        }

        int x = 99;
        int y = start_y;
        while(x != 0) {

//            if(t == 11)
//                cout << "(" << x << "," << y << ")\n";

            for(int i=0; i<2; i++) {
                if((y+dy[i]>=0&&y+dy[i]<100) && MAP[x][y+dy[i]]==1) {
                    while((y+dy[i]>=0&&y+dy[i]<100) && MAP[x][y+dy[i]]==1) {
//                        if(t == 11)
//                            cout << "(" << x << "," << y << ")\n";
                        y += dy[i];
                    }
                    break;
                }
            }

            x--;
        }

        printf("#%d %d\n", t, y);
    }

    return 0;
}