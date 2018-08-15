#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;

int tc, t;
int a, b, c, d; // <=20

//string cache[3][21][21][21][21];
string cache[3][441][441];

bool DEBUG = false;

// #: initialize, $: impossible
string solve(int prev, int a, int b, int c, int d) {

//    cout << "call " << prev << " .. " << a << ", " << b << ", " << c << ", " << d << "\n";

    if(a==0&&b==0&&c==0&&d==0) {
        if(prev == 2) return "";
        else {
            if(prev) return "1";
            else return "0";
        }
    }
    if(cache[prev][21*a+b][21*c+d] != "#") { return cache[prev][21*a+b][21*c+d]; }
    string p = "$";
    if(prev==2||prev==0) {
        if(a>0) {
            p = solve(0, a-1, b, c, d);
            if(p!="$") return "0" + p;
        }
        if(b>0) {
            p = solve(1, a, b-1, c, d);
            if(p!="$") return "0" + p;
        }
    }
    if(prev==2||prev==1) {
        if(c>0) {
            p = solve(0, a, b, c-1, d);
            if(p!="$") return "1" + p;
        }
        if(d>0) {
            p = solve(1, a, b, c, d-1);
            if(p!="$") return "1" + p;
        }
    }
//    cout << prev << " .. " << a << ", " << b << ", " << c << ", " << d << " return " << p << "\n";
    return cache[prev][21*a+b][21*c+d] = p;
}

int main() {

    FILE *fp = freopen("../data/battle.input", "r", stdin);
    if(!fp)
        perror("freopen error");

    for(int i=0; i<3; i++)
        for(int j=0; j<441; j++)
            for(int k=0; k<441; k++)
                cache[i][j][k] = "#";

    scanf("%d", &tc);
    t = 0;
    while(t++ < tc) {

        scanf("%d%d%d%d", &a, &b, &c, &d);
        string s = solve(2, a, b, c, d);
        printf("#%d %s\n", t, (s=="$")? "impossible":s.c_str());


    }

//
//    cout << solve(0, 0, 0, 0, 0) << "\n";
//    cout << solve(1, 0, 0, 0, 0) << "\n";
//    cout << solve(2, 0, 0, 0, 0) << "\n";
//
//    cout << solve(2, 1, 0, 0, 0) << "\n";
//    cout << solve(2, 0, 1, 0, 0) << "\n";
//    cout << solve(2, 0, 0, 1, 0) << "\n";
//    cout << solve(2, 0, 0, 0, 1) << "\n";

//        // TODO heavy.
//        for(int p=0; p<3; p++)
//            for(int i=0; i<a; i++)
//                for(int j=0; j<b; j++)
//                    for(int k=0; k<c; k++)
//                        for(int l=0; l<d; l++)
//                            cache[p][i][j][k][l] = "#";


    return 0;
}

