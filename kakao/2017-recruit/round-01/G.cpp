#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct res {
    int a, b;
    res(int _a, int _b) { a = _a; b = _b; };
    bool operator < (const res &l2) const { return a<l2.a; };
};

res str_to_time(string str) {

    int end = 0, hour = 0, min = 0, sec = 0;
    hour = 10*(str[11]-'0')+(str[12]-'0');
    min = 10*(str[14]-'0')+(str[15]-'0');
    for(int i=17; i<23; i++) {
        if(i==19) continue;
        sec = 10*sec+(str[i]-'0');
    }
    end = hour*60*60*1000+min*60*1000+sec;

    int duration = 0;
    if(24<str.size()-1) duration += 1000*(str[24]-'0');
    if(26<str.size()-1) duration += 100*(str[26]-'0');
    if(27<str.size()-1) duration += 10*(str[27]-'0');
    if(28<str.size()-1) duration += 1*(str[28]-'0');

    return res(end-duration+1+3000, end+3000);
}

int max(int a, int b) {
    return a>b? a:b;
}

int solution(vector<string> lines) {

    vector<res> v;
    for(int i=0; i<lines.size(); i++)
        v.push_back(str_to_time(lines[i]));

    int ans = 0, a, b, start, end;
    for(int i=0; i<v.size(); i++) {
        a = 0;
        start = v[i].a, end = v[i].a+999;
        for(int j=0; j<v.size(); j++)
            if(v[j].b>=start&&v[j].a<=end) a++;
        b = 0;
        start = v[i].b, end = v[i].b+999;
        for(int j=0; j<v.size(); j++)
            if(v[j].b>=start&&v[j].a<=end) b++;
        ans = max(ans, max(a, b));
    }
    return ans;
}

int main() {

    vector<string> ll = {"2016-09-15 01:00:04.001 2.0s", "2016-09-15 01:00:07.000 2s"};
//    vector<string> ll = {"2016-09-15 01:00:04.002 2.0s", "2016-09-15 01:00:07.000 2s"};

    cout << solution(ll) << "\n";
}


/**
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

#define BUFF_SIZE 86400000

int buff[BUFF_SIZE] = {0};

int solution(vector<string> lines) {
    int answer = 0;


    for (int i = 0; i < lines.size(); i++)
    {
        int end=0;
        int elapsed_time;
        int y, m, d, hh, mm, ss, zzz;
        double elapsed_double;
        sscanf(lines[i].c_str(), "%d-%d-%d %d:%d:%d.%d %lfs", &y, &m, &d, &hh, &mm,&ss, &zzz, &elapsed_double);
        elapsed_time = (int)(elapsed_double * 1000);

        end += hh*60;
        end += mm;
        end *= 60;
        end += ss;
        end *= 1000;
        end += zzz;

        for (int j = end - (elapsed_time-1) -999; j <= end; j++)
        {
            if (j < 0 || j >= BUFF_SIZE)
                continue;
            buff[j] += 1;
            answer = max(answer, buff[j]);
        }
    }

    return answer;
}
*/