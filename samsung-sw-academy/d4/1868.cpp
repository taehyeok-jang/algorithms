#include <iostream>

using namespace std;

int tc, t;
int N;
int **MAP;
bool **clicked;

// 12 -> 1 -> 3 -> 5 -> 6 -> 7 -> 9 -> 11.
int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

bool DEBUG = false;

void dfs(int x, int y) {

    clicked[x][y] = true;

    bool isZero = true;
    for(int i=0; i<8; i++) {
        if((x+dx[i]<0||x+dx[i]>=N)||(y+dy[i]<0||y+dy[i]>=N))
            continue;
        if(MAP[x+dx[i]][y+dy[i]]==1) {
            isZero = false;
            break;
        }
    }
    // if isZero, dfs more.
    if(isZero) {
        for(int i=0; i<8; i++) {
            if((x+dx[i]<0||x+dx[i]>=N)||(y+dy[i]<0||y+dy[i]>=N))
                continue;
            if(!clicked[x+dx[i]][y+dy[i]])
                dfs(x+dx[i], y+dy[i]);
        }
    }
}

int main() {

//    FILE *fp = freopen("../data/1868.input", "r", stdin);
//    if(!fp)
//        perror("freopen error");

    scanf("%d", &tc);
    t = 0;
    while(t++ < tc) {

        scanf("%d", &N);

//        cout << "N: " << N << "\n";

        MAP = new int*[N];
        for(int i=0; i<N; i++)
            MAP[i] = new int[N];
        char str[N];
        for(int i=0; i<N; i++) {
            scanf("%s", str);
            for(int j=0; j<N; j++) {
                if(str[j] == '*')   MAP[i][j] = 1;
                else                MAP[i][j] = 0;
            }
        }

        clicked = new bool*[N];
        for(int i=0; i<N; i++)
            clicked[i] = new bool[N];
        for(int i=0; i<N; i++)
            for(int j=0; j<N; j++)
                clicked[i][j] = false;


        int count = 0;

        // find '0' zone first.
        for(int x=0; x<N; x++) {
            for(int y=0; y<N; y++) {

                if(MAP[x][y]==1 || clicked[x][y])
                    continue;

                bool isZero = true;
                for(int i=0; i<8; i++) {
                    if((x+dx[i]<0||x+dx[i]>=N)||(y+dy[i]<0||y+dy[i]>=N))
                        continue;
                    if(MAP[x+dx[i]][y+dy[i]]==1) {
                        isZero = false;
                        break;
                    }
                }
                // if isZero, can search adjs with no cost.
                if(isZero) {
                    dfs(x, y);
                    count++;
                }
            }
        }
//        cout << count << "\n";

//        for(int x=0; x<N; x++) {
//            for (int y = 0; y < N; y++) {
//                printf("%d ", clicked[x][y] || MAP[x][y]);
//            }
//            printf("\n");
//        }

        for(int x=0; x<N; x++)
            for(int y=0; y<N; y++)
                if(MAP[x][y]==0 && !clicked[x][y])
                    count++;

        printf("#%d %d\n", t, count);
    }

    return 0;
}