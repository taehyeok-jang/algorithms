#include <string>

using namespace std;

int score(int point, char bonus) {

    if(bonus=='S') return point;
    if(bonus=='D') return point*point;
    if(bonus=='T') return point*point*point;
}

int solution(string dartResult) {

    int ans = 0, i = 0, prev = 0;
    int point; char bonus;
    bool op1, op2; // *, #
    while(i<dartResult.size()) {

        if(dartResult[i+1]=='0') point = 10, i += 2;
        else                     point = dartResult[i++]-48;
        bonus = dartResult[i++];

        if(i==dartResult.size()||(dartResult[i]>=48&&dartResult[i]<58)) {
            ans += score(point, bonus);
            prev = score(point, bonus);
            continue;
        }

        op1 = op2 = 0;
        if(dartResult[i]=='*') op1 = 1;
        if(dartResult[i]=='#') op2 = 1;
        i++;
        if(op1) {
            ans += prev+2*score(point, bonus);
            prev = 2*score(point, bonus);
        }
        if(op2) {
            ans -= score(point, bonus);
            prev = -score(point, bonus);
        }
    }

    return ans;
}


#include <iostream>

int main() {

    string str[7] = {
            "1S2D*3T",
            "1D2S#10S",
            "1D2S0T",
            "1S*2T*3S",
            "1D#2S*3S",
            "1T2D3D#",
            "1D2S3T*"
    };

    for(int i=0; i<7; i++)
        cout << solution(str[i]) << "\n";
}

