#include <string>
#include <map>
#include <iostream>

using namespace std;


string strupr(string str) {
    for(int i=0; i<str.size(); i++)
        if('A'<=str[i]&&str[i]<='Z') str[i] += 32;
    return str;
}

bool is_char(char c) {
    return ('a'<=c&&c<='z');
}

int solution(string str1, string str2) {

    str1 = strupr(str1);
    str2 = strupr(str2);

    map<string, int> dict1, dict2;
    map<string, int>::iterator it;
    int idx; string elem;

    idx = 0;
    while(idx<str1.size()-1) {
        if(is_char(str1[idx])&&is_char(str1[idx+1])) {
            elem = ""; elem += str1[idx], elem += str1[idx+1];
            if(dict1.count(elem)) dict1[elem] += 1;
            else                  dict1[elem] = 1;
        }

        idx += 1;
    }

    idx = 0;
    while(idx<str2.size()-1) {
        if(is_char(str2[idx])&&is_char(str2[idx+1])) {
            elem = ""; elem += str2[idx], elem += str2[idx+1];
            if(dict2.count(elem)) dict2[elem] += 1;
            else                  dict2[elem] = 1;
        }

        idx += 1;
    }
    int ans = 0;
    double A = 0, B = 0;
    for(it=dict1.begin(); it!=dict1.end(); it++) {
        string s = it->first;
        if(dict2.count(s)) B += min(dict1[s], dict2[s]), dict2[s] = max(dict1[s], dict2[s]);
        else dict2[s] = dict1[s];
    }
    for(it=dict2.begin(); it!=dict2.end(); it++)
        A += it->second;

    return (A==0)? 65536:(B/A)*65536;
}

int main() {

    string str1[4] = {"FRANCE", "handshake", "aa1+aa2", "E=M*C^2"};
    string str2[4] = {"french", "shake hands", "AAAA12", "e=m*c^2"};

    for(int i=0; i<4; i++)
        cout << solution(str1[i], str2[i]) << "\n";

    return 0;

}