#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;

int tc, t;
// S, D, H, C.
char input[1000];
bool card[4][14];

bool DEBUG = false;

int index(char c) {

    if(c == 'S')        return 0;
    else if(c == 'D')   return 1;
    else if(c == 'H')   return 2;
    else if(c == 'C')   return 3;
    else                return -1;
}

int main() {

//    FILE *fp = freopen("../data/3501.input", "r", stdin);
//    if(!fp)
//        perror("freopen error");

    scanf("%d", &tc);
    t = 0;
    while(t++ < tc) {

        scanf("%s", input);

        memset(card, 0, sizeof(bool)*4*14);
        int i = 0;
        char c;
        int j;
        bool error = false;
        while(i < strlen(input)) {

            c = input[i];
            j = (input[i+1]-48)*10+(input[i+2]-48);
            if(card[index(c)][j]) {
                error = true;
                break;
            }
            card[index(c)][j] = true;

            i += 3;
        }

        if(error) {
            printf("#%d ERROR\n", t);
            continue;
        }

        printf("#%d", t);
        for(int i=0; i<4; i++) {
            int count = 0;
            for(int j=1; j<14; j++)
                if(!card[i][j])
                    count++;
            printf(" %d", count);
        }
        printf("\n");
    }

    return 0;
}
