#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;

int tc, t;
int N, M;
char buf[51], mem[51];

bool DEBUG = false;


int main() {

//    FILE *fp = freopen("../data/3501.input", "r", stdin);
//    if(!fp)
//        perror("freopen error");

    scanf("%d", &tc);
    t = 0;
    while(t++ < tc) {

        memset(buf, 0, sizeof(char)*51);
        scanf("%s", mem);

        int cnt = 0;
        char s = '0';
        for(int i=0; i<strlen(mem); i++) {

            if(mem[i]!=s) {
                cnt++;
                if(s=='0') s = '1';
                else       s = '0';
            }
        }

        printf("#%d %d\n", t, cnt);
    }

    return 0;
}
