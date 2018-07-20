#include <iostream>
#include <vector>

using namespace std;

int tc, t;
int P, Q;
char str[500];
char c[8] = {'(', ')', '[', ']', '{', '}', '<', '>'};
int count_[8];

bool DEBUG = false;

int main() {

//    FILE *fp = freopen("../data/1218.input", "r", stdin);
//    if(!fp)
//        perror("freopen error");

    tc = 10;
    t = 0;
    while(t++ < tc) {

        int n;
        scanf("%d", &n);
        scanf("%s", str);

        for(int i=0; i<8; i++)
            count_[i] = 0;

        for(int i=0; i<n; i++) {
            for(int j=0; j<8; j++) {
                if(str[i] == c[j]) {
                    count_[j]++;
                    break;
                }
            }
        }

        bool valid = true;
        for(int i=0; i<4; i++) {
            if(count_[2*i] != count_[2*i+1]) {
                valid = false;
                break;
            }
        }



        printf("#%d %d\n", t, valid);
    }

    return 0;
}