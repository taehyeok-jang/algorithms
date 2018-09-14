#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(string msg) {

    vector<int> ans;
    map<string, int> dict;
    for(int i=0; i<26; i++)
        dict[string(1, i+65)] = i+1;
    dict[""] = -1;

    int idx = 0, k = 27; string w;
    while(idx<msg.size()) {
        w = "";
        while(idx<msg.size()&&dict.count(w))
            w += msg[idx++];

        if(idx<msg.size()||!dict.count(w)) {
            ans.push_back(dict[w.substr(0, w.size()-1)]);
            dict[w] = k++, idx--;
        }
        else {
            ans.push_back(dict[w]);
        }
    }

    return ans;
}

#include <iostream>

int main() {
//
//    map<string, int> dict;
//    for(int i=0; i<26; i++)
//        dict[string(1, i+65)] = i+1;
//    dict[""] = -1;
//
//    map<string, int>::iterator it;
//    for(it=dict.begin(); it!=dict.end(); it++)
//        cout << it->first << ", " << it->second << "\n";
//
//    string ss = "ABC";
//    cout << ss+'c' << "\n";
//
//    cout << ss.substr(0, 3) << "\n";

    string input[3] = {
            "KAKAO",
            "TOBEORNOTTOBEORTOBEORNOT",
            "ABABABABABABABAB"
    };

    for(int i=0; i<3; i++) {
        vector<int> sol = solution(input[i]);
        for(int j=0; j<sol.size(); j++)
            cout <<  sol[j] << " ";
        cout << "\n";
    }

    return 0;
}