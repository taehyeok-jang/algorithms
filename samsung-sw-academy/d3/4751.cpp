#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;

int tc, t;

int N;
char S[100];

bool DEBUG = false;

int main() {

//    FILE *fp = freopen("../data/3501.input", "r", stdin);
//    if(!fp)
//        perror("freopen error");

    scanf("%d", &tc);
    t = 0;
    while(t++ < tc) {

        scanf("%s", S);
        int N = strlen(S);

        printf("..");
        for(int i=0; i<N-1; i++)
            printf("#...");
        printf("#..\n");
        for(int i=0; i<2*N; i++)
            printf(".#");
        printf(".\n");

        printf("#.");
        for(int i=0; i<N-1; i++)
            printf("%c.#.", S[i]);
        printf("%c.#\n", S[N-1]);

        for(int i=0; i<2*N; i++)
            printf(".#");
        printf(".\n");
        printf("..");
        for(int i=0; i<N-1; i++)
            printf("#...");
        printf("#..\n");



//        printf("#%d %d\n", t, a);
    }

    return 0;
}
