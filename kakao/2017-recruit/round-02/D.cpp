#include <string>
#include <vector>
#include <iostream>

using namespace std;

void pre_process(string p, int *lps, int m) {
    lps[0] = 0;
    int i = 1, len = 0;
    while(i<m) {
        if(p[i]==p[len]) {
            lps[i++] = ++len;
        }
        else { // (p[i] != p[len])
            if(len>0)
                len = lps[len - 1];
            else
                lps[i++] = 0;
        }
    }
}
bool match(string pattern, int *lps, string txt) {

    int m = pattern.size(), n = txt.size();
    int i = 0, j = 0;
    while(i<n) {
        if(pattern[j]==txt[i])
            j++, i++;
        if(j==m) {
            return 1;
        }
        else if(i<n&&pattern[j]!=txt[i]) {
            if(j!=0) j = lps[j-1];
            else i++;
        }
    }

    return 0;
}

void parse(string &musicinfo, int &start, int &end, string &title, string &info) {

    int a, b, c, d;
    sscanf(musicinfo.c_str(), "%d:%d,%d:%d", &a, &b, &c, &d);
    start = 60*a+b, end = 60*c+d;

    char buf[2000]; int j, k;
    j = 12; k = 0;
    while(musicinfo[j]!=',')
        buf[k++] = musicinfo[j++];
    buf[k] = 0; title = string(buf);
    j += 1, k = 0;
    while(j<musicinfo.size())
        buf[k++] = musicinfo[j++];
    buf[k] = 0; info = string(buf);
}
string tokenize(string s) {
    vector<char> v;
    int i = 0;
    while(i<s.size()) {
        if(i<s.size()-1&&(s[i]=='A'||s[i]=='C'||s[i]=='D'||s[i]=='F'||s[i]=='G')) {
            if(s[i+1]=='#') v.push_back(s[i]+32), i += 2;
            else            v.push_back(s[i]), i += 1;
        }
        else {
            v.push_back(s[i]), i += 1;
        }
    }
    return string(v.begin(), v.end());
}

string solution(string m, vector<string> musicinfos) {

    m = tokenize(m);
    int lps[m.size()];
    pre_process(m, lps, m.size());

    int start, end; string ans, title, info;
    bool is_match = 0; int duration = 0;
    for(int i=0; i<musicinfos.size(); i++) {

        parse(musicinfos[i], start, end, title, info);
        info = tokenize(info);
        if(info.size()>end-start)
            info = info.substr(0, end-start);

        string dup = info;
        while(dup.size()<end-start) dup += info;

//        if(m.size()<=end-start&&dup.find(m, 0)!=string::npos) {
        if(m.size()<=end-start&&match(m, lps, dup)) {
            if(is_match) {
                if(duration<end-start) {
                    duration = end-start;
                    ans = title;
                }
            }
            else {
                is_match = 1;
                duration = end-start;
                ans = title;
            }
        }
    }

    return is_match? ans:"(None)";
}
/*

string solution(string m, vector<string> musicinfos) {

    m = tokenize(m);
    int lps[m.size()];
    pre_process(m, lps, m.size());

    int start, end; string ans, title, info;
    bool is_match = 0; int duration = 0;
    for(int i=0; i<musicinfos.size(); i++) {

        parse(musicinfos[i], start, end, title, info);
        info = tokenize(info);
        if(info.size()>end-start)
            info = info.substr(0, end-start);

        string dup = info;
        while(dup.size()<end-start) dup += info;

//        if(dup.find(m, 0)<string::npos) {
        if(match(m, lps, dup)&&m.size()<=end-start) {
            if(is_match) {
                // 조건이 일치하는 음악이 여러 개일 때에는 라디오에서 재생된 시간이 제일 긴 음악 제목을 반환한다.
                // 재생된 시간도 같을 경우 먼저 입력된 음악 제목을 반환한다.
                if(duration<end-start) {
                    duration = end-start;
                    ans = title;
                }
            }
            else {
                is_match = 1;
                duration = end-start;
                ans = title;
            }
        }
    }

    return is_match? ans:"(None)";
}*/

int main() {

    string pp = "a";
    string txt = "abc";
    cout << (txt.find(pp, 0)!=string::npos) << "\n";

//    pos = inf.find(m, pos)) != std::string::npos

    string m[3] = {"ABCDEFG", "CC#BCC#BCC#BCC#B", "ABC"};

    vector<vector<string>> tt(3);
//    for(int i=0; i<3; i++) tt[i].resize(2);
    tt[0] = {"12:00,12:14,HELLO,CDEFGAB", "13:00,13:05,WORLD,ABCDEF"};
    tt[1] = {"03:00,03:30,FOO,CC#B", "04:00,04:08,BAR,CC#BCC#BCC#B"};
    tt[2] = {"12:00,12:14,HELLO,C#DEFGAB", "13:00,13:05,WORLD,ABCDEF"};

    for(int i=0; i<3; i++)
        cout << "sol @@@@@: " << solution(m[i], tt[i]) << "\n";

    vector<string> ttt = { "03:00,03:00,FOO,A" };
    cout<<solution("A", ttt);


    return 0;
}

/*
 *
#include <string>
#include <vector>
#include <iostream>

using namespace std;

void pre_process(string p, int *lps, int m) {
    lps[0] = 0;
    int i = 1, len = 0;
    while(i<m) {
        if(p[i]==p[len]) {
            lps[i++] = ++len;
        }
        else { // (p[i] != p[len])
            if(len>0)
                len = lps[len - 1];
            else
                lps[i++] = 0;
        }
    }
}
bool is_match(string pattern, int *lps, string txt) {

    int m = pattern.size();
    int n = txt.size();

    int i = 0;
    int j = 0;
    while(i<n) {
        if(pattern[j]==txt[i])
            j++, i++;

        if(j==m) {
            return 1;
        }
        else if(i<n&&pattern[j]!=txt[i]) {
            if(j!=0) j = lps[j-1];
            else i++;
        }
    }

    return 0;
}

void parse(string &musicinfo, int &start, int &end, string &title, string &info) {

    int a, b, c, d;
    sscanf(musicinfo.c_str(), "%d:%d,%d:%d", &a, &b, &c, &d);
    start = 60*a+b, end = 60*c+d;

    char buf[2000]; int j, k;
    j = 12; k = 0;
    while(musicinfo[j]!=',')
        buf[k++] = musicinfo[j++];
    buf[k] = 0; title = string(buf);
    j += 1, k = 0;
    while(j<musicinfo.size())
        buf[k++] = musicinfo[j++];
    buf[k] = 0; info = string(buf);
}

string tokenize(string s) {
    vector<char> v;
    int i = 0;
    while(i<s.size()) {
        if(i<s.size()-1&&(s[i]=='A'||s[i]=='C'||s[i]=='D'||s[i]=='F'||s[i]=='G')) {
            if(s[i+1]=='#') v.push_back(s[i]+32), i += 2;
            else            v.push_back(s[i]), i += 1;
        }
        else {
            v.push_back(s[i]), i += 1;
        }
    }
    return string(v.begin(), v.end());
}



string solution(string m, vector<string> musicinfos) {

    string ans = "";

    m = tokenize(m);
    int lps[m.size()];
    pre_process(m, lps, m.size());

int start, end; string title, info, duplicate;
bool match = 0, is_matched;
int duration = 0;
for(int i=0; i<musicinfos.size(); i++) {

parse(musicinfos[i], start, end, title, info);
//        cout << start << ", " << end << "\n";
//        cout << title << ", " << info << "\n\n";

if(info.size()>end-start)
info = info.substr(0, end-start);
info = tokenize(info);
//        cout << title << ", " << info << "\n\n";

duplicate = "";
duplicate += info; duplicate += info;

is_matched = (m.size()<duplicate.size())? is_match(m, lps, duplicate):is_match(info, lps, m);
if(is_matched) {
if(match) {
if(duration<end-start) {
duration = end-start;
ans = title;
}
}
else {
match = 1;
duration = end-start;
ans = title;
}
}
}

return match? ans:"(None)";
}

 */
