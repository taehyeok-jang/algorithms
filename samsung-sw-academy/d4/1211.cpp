#include <iostream>
#include <vector>

using namespace std;

int tc, t;
int MAP[100][100];

int dy[2] = {1, -1};

bool DEBUG = false;

int main() {

//    FILE *fp = freopen("../data/1211.input", "r", stdin);
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

        int index = -1;
        int MIN = 654321;
        for(int i=0; i<100; i++) {

            if(MAP[0][i] == 0)
                continue;

            int step = 0;
            int x = 0;
            int y = i;
            while(x != 100) {

//            if(t == 11)
//                cout << "(" << x << "," << y << ")\n";

                for(int i=0; i<2; i++) {
                    if((y+dy[i]>=0&&y+dy[i]<100) && MAP[x][y+dy[i]]==1) {
                        while((y+dy[i]>=0&&y+dy[i]<100) && MAP[x][y+dy[i]]==1) {
//                        if(t == 11)
//                            cout << "(" << x << "," << y << ")\n";
                            step++;
                            y += dy[i];
                        }
                        break;
                    }
                }

                step++;
                x++;
            }

            if(step <= MIN) {
                MIN = step;
                index = i;
            }
        }


        printf("#%d %d\n", t, index);
    }

    return 0;
}