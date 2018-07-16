#include <iostream>
#include <vector>

using namespace std;

int tc, t;
int N, B;
int H[20];

int MIN;

bool DEBUG = false;

void solve(int index, int current_height) {

    if(current_height >= B) {
        MIN = min(MIN, abs(B-current_height));
        return;
    }
    if(index == N)
        return;

    solve(index+1, current_height+H[index]);
    solve(index+1, current_height);
}

int main() {

//    FILE *fp = freopen("../data/1486.input", "r", stdin);
//    if(!fp)
//        perror("freopen error");

    scanf("%d", &tc);
    t = 0;
    while(t++ < tc) {

        scanf("%d%d", &N, &B);
        for(int i=0; i<N; i++)
            scanf("%d", &H[i]);

        MIN = 87654321;
        solve(0, 0);

        printf("#%d %d\n", t, MIN);
    }

    return 0;
}