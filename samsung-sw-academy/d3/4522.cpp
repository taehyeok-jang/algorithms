#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;

int tc, t;
char S[20];
int L;

bool DEBUG = false;

bool solve(int left, int right) {

    if(left >= right)
        return true;

    char a = S[left];
    char b = S[right];

    if(a=='*'||b=='*')
        return true;

    if(a == b)
        return solve(left+1, right-1);
    else
        return false;
}

int main() {

//    FILE *fp = freopen("../data/3501.input", "r", stdin);
//    if(!fp)
//        perror("freopen error");

    scanf("%d", &tc);
    t = 0;
    while(t++ < tc) {

        scanf("%s", S);
        L = strlen(S);

        string s = (solve(0, L-1))? "Exist":"Not exist";
        printf("#%d %s\n", t, s.c_str());
    }

    return 0;
}
