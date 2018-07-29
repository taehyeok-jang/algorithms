#include <iostream>

using namespace std;

int tc, t;
int N;
int MAP[100][100];
bool calculated[100][100][4];
int cache[100][100];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};


bool DEBUG = false;

int solve(int x, int y) {

    

    if(x==0 && y==0)
        return 0;
}

int main() {

    FILE *fp = freopen("../data/4901.input", "r", stdin);
    if(!fp)
        perror("freopen error");

    scanf("%d", &tc);
    tc = 1;
    t = 0;
    while(t++ < tc) {

        scanf("%d", &N);
        char buffer[N];
        for(int i=0; i<N; i++) {
            scanf("%s", buffer);
            for(int j=0; j<N; j++)
                MAP[i][j] = buffer[j]-48;
        }
        memset(calculated, 0, sizeof(bool)*100*100*4);

        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++)
                cout << MAP[i][j] << " ";
            cout << "\n";
        }



        printf("#%d \n", t);
    }

    return 0;
}