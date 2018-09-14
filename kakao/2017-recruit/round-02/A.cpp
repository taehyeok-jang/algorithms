#include <string>
#include <vector>

using namespace std;

char val_to_char(int val) {
    if(val<10) return val+48;
    else       return val+55;
}

string solution(int n, int t, int m, int p) {

    vector<char> seq, ans;
    seq.push_back('0');

    int num = 1, tmp;
    while(seq.size()<t*m) {
        tmp = num;
        string s = "";
        while(tmp) {
            s += val_to_char(tmp%n); // TODO slow...?
            tmp /= n;
        }
        for(int i=0; i<s.size(); i++)
            seq.push_back(s[s.size()-i-1]);
        num++;
    }

    for(int i=0; i<t; i++)
        ans.push_back(seq[i*m+p-1]);
    return string(ans.begin(), ans.end());
}

#include <iostream>

int main() {

//    for(int i=48; i<80; i++)
//        cout << (char)i << " -> " << i << "\n";

    int n[3] = {2, 16, 16};
    int t[3] = {4, 16, 16};
    int m[3] = {2, 2, 2};
    int p[3] = {1, 1, 2};

    for(int i=0; i<3; i++)
        cout << solution(n[i], t[i], m[i], p[i]) << "\n";

    return 0;
}