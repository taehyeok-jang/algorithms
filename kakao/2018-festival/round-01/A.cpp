#include <iostream>
#include <cmath>

using namespace std;

int tc, t;
int P, Q;

bool DEBUG = false;

int RA[10] = {500, 300, 200, 50, 30, 10};
int RB[10] = {512, 256, 128, 64, 32};

int main() {

//    FILE *fp = freopen("../data/kakao/A.input", "r", stdin);
//    if(!fp)
//        perror("freopen error");

    scanf("%d", &tc);
    t = 0;
    while(t++ < tc) {

        int A, B;
        scanf("%d%d", &A, &B);

        int ra = 0, rb = 0;

        int s = 0;
        for(int i=0; i<6; i++) {
            s += (i+1);
            if(A <= s) {
                ra = RA[i]*10000;
                break;
            }
        }
        s = 0;
        for(int i=0; i<5; i++) {
            s += (int)pow(2, i);
            if(B <= s) {
                rb = RB[i]*10000;
                break;
            }
        }
        ra = (A==0)? 0:ra;
        rb = (B==0)? 0:rb;

        printf("%d\n", ra+rb);
    }

    return 0;
}