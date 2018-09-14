#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

struct data {
    string s;
    int t;
    data() { };
    data(string _s, int _t) { s = _s; t = _t; }
};

string strupr(string str) {
    for(int i=0; i<str.size(); i++)
        if('A'<=str[i]&&str[i]<='Z') str[i] += 32;
    return str;
}

int solution(int cacheSize, vector<string> cities) {

    map<string, int> cache;
    data log[100001]; int f, r;
    f = r = 0;
    int ans = 0, size = 0, time = 1;
    for(int i=0; i<cities.size(); i++) {

        string str = strupr(cities[i]);
        if(cache.count(str)) {
            ans += 1;
        }
        else {
            ans += 5;
            if(size<cacheSize) {
                size++;
            }
            else {
                data d;
                while(f<r) {
                    d = log[f++];
                    if(cache.count(d.s)==0||cache[d.s]>d.t) continue;
                    else break;
                }
                cache.erase(d.s);
            }
        }

        log[r++] = data(str, time);
        cache[str] = time;
        time++;
    }

    return ans;
}

int main() {

    int n[6] = {3, 3, 2, 5, 2, 0};
    vector<vector<string>> input(6);
    input[0] = { "Jeju", "Pangyo", "Seoul", "NewYork", "LA", "Jeju", "Pangyo", "Seoul", "NewYork", "LA"};
    input[1] = {"Jeju", "Pangyo", "Seoul", "Jeju", "Pangyo", "Seoul", "Jeju", "Pangyo", "Seoul"};
    input[2] = {"Jeju", "Pangyo", "Seoul", "NewYork", "LA", "SanFrancisco", "Seoul", "Rome", "Paris", "Jeju", "NewYork", "Rome"};
    input[3] = {"Jeju", "Pangyo", "Seoul", "NewYork", "LA", "SanFrancisco", "Seoul", "Rome", "Paris", "Jeju", "NewYork", "Rome"};
    input[4] = {"Jeju", "Pangyo", "NewYork", "newyork"};
    input[5] = {"Jeju", "Pangyo", "Seoul", "NewYork", "LA"};

//    int n = 3;
//    vector<string> input = {"a", "b", "c", "d", "a", "a", "a", "b", "c", "d"};

    for(int i=0; i<6; i++)
        cout << solution(n[i], input[i]) << "\n";

    return 0;
}