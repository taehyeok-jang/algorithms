#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

struct log {
    int command; // 1: enter, 2: leave, 3: change.
    string id;
    log(int _c, string _i) { command = _c; id = _i; }
};

string action(int c) {
    if(c==1)        return "님이 들어왔습니다.";
    else if(c==2)   return "님이 나갔습니다.";
}
vector<string> solution(vector<string> record) {
    map<string, string> users;
    vector<log> logs;
    char a[20], b[20], c[20];
    for(int i=0; i<record.size(); i++) {
        sscanf(record[i].c_str(), "%s %s %s", a, b, c);
        if(command[0]=='E') {
            users[string(b)] = string(c);
            logs.push_back(log(1, string(b)));
        }
        else if(command[0]=='L') {
            logs.push_back(log(2, string(b)));
        }
        else {
            users[string(b)] = string(c);
            logs.push_back(log(3, string(b)));
        }
    }
    vector<string> ans;
    for(int i=0; i<logs.size(); i++)
        if(logs[i].command==1||logs[i].command==2)
            ans.push_back(users[logs[i].id]+action(logs[i].command));
    return ans;
}

int main() {

    vector<string> input = {"Enter uid1234 Muzi", "Enter uid4567 Prodo", "Leave uid1234", "Enter uid1234 Prodo", "Change uid4567 Ryan"};
    vector<string> sol = solution(input);
    for(int i=0; i<sol.size(); i++)
        cout << sol[i];

//    string sentence = "Rudolph is 12 years old";
////    char sentence []="Rudolph is 12 years old"/;
//    char str [20];
//    int i;
//
//    sscanf (sentence.c_str(),"%s %*s %d",str,&i);
//    printf ("%s -> %d\n",str,i);

}