#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#include <iostream>

struct file {
    string head;
    int number, idx;
    file() { };
    file(string _h, int _n, int _i) { head = _h; number = _n; idx = _i; }
    bool operator < (const file &f2) const {
        int cmp;
        if((cmp=head.compare(f2.head))!=0) {
//            cout << head << " and " << f2.head << " -> " << head.compare(f2.head) << "\n";
            return cmp<0? 1:0;
        }
        else {
            if(number!=f2.number)
                return number<f2.number;
            else
                return idx<f2.idx;
        }
    };
};

string strupr(string str) {
    for(int i=0; i<str.size(); i++)
        if('A'<=str[i]&&str[i]<='Z') str[i] += 32;
    return str;
}

bool is_num(char c) {

    return c>=48&&c<58;
}

vector<string> solution(vector<string> files) {

    vector<string> ref;

    for(int i=0; i<files.size(); i++)
        ref.push_back(strupr(files[i]));

    vector<file> ff;
    char buf[100]; int number, j;
    for(int i=0; i<files.size(); i++) {

        number = 0; j = 0;
        while(!is_num(ref[i][j])) buf[j++] = ref[i][j];
        buf[j] = 0;
        while(j<ref[i].size()&&is_num(ref[i][j])) number = 10*number+(ref[i][j++]-48);

//        cout << files[i] << "\n";
//        cout << buf << ", " << number << "\n";

        ff.push_back(file(string(buf), number, i));
    }
    sort(ff.begin(), ff.end());

    vector<string> ans;
    for(int i=0; i<files.size(); i++)
        ans.push_back(files[ff[i].idx]);
    return ans;
}


int main() {

    vector<vector<string>> files(2);
    files[0] = {"img12.png?", "img10.png?", "img02.png?", "img1.png?", "IMG01.GIF?", "img2.JPG?"};
    files[1] = {"F-5 Freedom Fighter?", "B-50 Superfortress?", "A-10 Thunderbolt II?", "F-14 Tomcat?"};

    for(int i=0; i<2; i++) {
        vector<string> ans = solution(files[i]);
        for(int j=0; j<ans.size(); j++)
            cout << ans[j] << " ";
        cout << "\n";
    }
    return 0;
}