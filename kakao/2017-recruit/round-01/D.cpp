#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

string int_to_string(int time) {
    int hour, min;
    hour = time/60, min = time%60;
    string s = "xx:xx";
    s[0] = hour/10+48, s[1] = hour%10+48;
    s[3] = min/10+48, s[4] = min%10+48;
    return s;
}

int string_to_int(string s) {
    int hour, min;
    hour = 10*(s[0]-48)+s[1]-48;
    min = 10*(s[3]-48)+s[4]-48;
    return 60*hour+min;
}

struct comparator {
    bool operator () (const string t1, const string t2) {
        return string_to_int(t1)<string_to_int(t2);
    }
} time_comparator;

// [08:00, 08:01, 08:02, 08:03]
// shuttle. 09:00, 09:0t, 09:2t ... total n times.
// so add if timetable[i] <= 09:xt.
// t1: table 시간, t2: 버스 시간
//bool compare(string t1, string t2) {
//
//    bool same = 1;
//    for(int i=0; i<5; i++)
//        if(t1[i]!=t2[i]) {
//            same = 0; break;
//        }
//    if(same) return 1;
//
//    for(int i=0; i<5; i++) {
//        if(i==2) continue;
//        if(t1[i]>t2[i]) return 0;
//    }
//    return 1;
//
//    // 더 일찍이거나 같으면 return 1.
//}


string solution(int n, int t, int m, vector<string> timetable) {

    // timetable sort.
    sort(timetable.begin(), timetable.end(), time_comparator);

    //
    for(int i=0; i<timetable.size(); i++)
        cout << timetable[i] << " ";
    cout << "\n";

    queue<int> waiting;
    int l, r, mid, idx;
    int departure; bool ride, possible;
    l = 0, r = 1440;
    while(l+1<r) {
        mid = (l+r)/2;
        cout << "mid: " << mid << "\n";
        cout << "l: " << l << ", " << "r: " << r << "\n";

        departure = string_to_int("09:00");
        idx = 0;
        ride = 0, possible = 1;

        for(int i=0; i<n; i++) {


        }
/*

        for(int i=0; i<n; i++) {

            cout << "at " << int_to_string(departure) << "\n";
            while(idx<timetable.size()&&string_to_int(timetable[idx])<=departure) {
                cout << "ride ";
                waiting.push(idx);
                if(idx<timetable.size()-1&&(timetable[idx]==timetable[idx+1])) {
                    idx++;
                    continue;
                }
                if(!ride&&mid<=string_to_int(timetable[idx])) {
                    cout << "me!! ";
                    waiting.push(-1);
                    ride = 1;
                }
                idx++;
            }
            cout << "\n";
            int j = m;
            while(waiting.size()>0&&j--) waiting.pop();
            departure += t;
        }*/

        possible = 1;
        while(waiting.size()>0) {
            if(waiting.front()==-1) possible = 0;
            waiting.pop();
        }

        puts((ride&&possible)? "possible":"no");
        cout << "\n";
        if(l==mid) break;
        if(!(ride&&possible))   r = mid-1;
        else                    l = mid;
    }

    return int_to_string(l);
}


int main() {

    int n[6] = {1, 2, 2, 1, 1, 10};
    int t[6] = {1, 10, 1, 1, 1, 60};
    int m[6] = {5, 2, 2, 5, 1, 45};

    vector<vector<string>> str(6);
    str[0] = {"08:00", "08:01", "08:02", "08:03"};
    str[1] = {"09:10", "09:09", "08:00"};
    str[2] = {"09:00", "09:00", "09:00", "09:00"};
    str[3] = {"00:01", "00:01", "00:01", "00:01", "00:01"};
    str[4] = {"23:59"};
    str[5] = {"23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59"};

    for(int i=0; i<6; i++) {
        cout << solution(n[i], t[i], m[i], str[i]);
        cout << "  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\n";

    }
}