#include <stdio.h>
#include <string.h>

using namespace std;
#define MAX 200000
int tc, t;
char A[MAX];

int main() {

//    FILE *fp = freopen("../data/battle.input", "r", stdin);
//    if(!fp)
//        perror("freopen error");

    scanf("%d", &tc);
    t = 0;
    while(t++ < tc) {

        scanf("%s", A);
        int sum, i, h;
        sum = i = h = 0;
        while(A[i]!='\0') {
            if(A[i]=='(') {
                if(A[i+1]=='(') h += 1, i++;
                else            sum += h, i += 2;
            }
            else { // A[i]==')' only the case ')' after ')'.
                sum += 1, h -= 1,  i++;
            }
        }
        printf("#%d %d\n", t, sum);
    }

    return 0;
}
