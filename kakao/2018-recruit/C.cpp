#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <set>

using namespace std;

/**
 * ref. https://github.com/baactree/PS/blob/master/kakaoblind2019/C.cpp#L6
 */
bool is_min(vector<int> &ans, int k) {
    for(int i=0; i<ans.size(); i++)
        if((k&vec[i])==vec[i]) return 0;
    return 1;
}
int solution2(vector<vector<string>> relation) {

    int row = relation.size();
    int col = realtion[0].size();
    vector<int> ans;
    for(int i=0; i<(1<<col)+1; i++) {
        set<string> s;
        for(int j=0; j<row; j++) {
            string key = "";
            for(int k=0; k<col; k++)
                if(i&(1<<k)) key += relation[j][k];
            s.insert(key);
        }
        if(s.size()==row&&is_min(ans, i));
    }
    return ans.size();
}
/**
 * my solution
 */
int solution(vector<vector<string>> relation) {

    int row, col; // row <= 20, col <= 8.
    row = relation.size(), col = relation[0].size();

    // 0: not initialized
    // 1: candidates
    // -1: not unique
    // -2: unique, but not minimal.
    int candidates[257];
    for(int i=0; i<257; i++) candidates[i] = 0;
    map<string, int> dict;

    int ans = 0;
    bool is_uniq, is_mini;
    for(int k=0; k<(1<<col)+1; k++) {

        is_uniq = 1, is_mini = 1;
        dict.clear();

        for(int i=0; i<row; i++) {
            string key = "";
            for(int j=0; j<col; j++)
                if(k&(1<<j)) key += relation[i][j];
            if(dict.count(key)) { is_uniq = 0; break; }
            else                { dict[key] = 1; }
        }

        if(!is_uniq) {
            candidates[k] = -1;
            continue;
        }

        int count = 0;
        for(int i=0; i<col; i++) if(k&(1<<i)) count++;
        if(count>1) {
            int tmp = k;
            for(int i=0; i<col; i++) {
                if(k&(1<<i)) {
                    tmp -= (1<<i);
                    if(candidates[tmp]==1||candidates[tmp]==-2) {
                        is_mini = 0;
                        break;
                    }
                    tmp += (1<<i);
                }
            }
        }

        if(is_uniq&&is_mini) ans++, candidates[k] = 1;
        else candidates[k] = -2;
    }

    return ans;
}

int main() {

    vector<vector<string>> input = {
            {"100","ryan","music","2"},
            {"200","apeach","math","2"},
            {"300","tube","computer","3"},
            {"400","con","computer","4"},
            {"500","muzi","music","3"},
            {"600","apeach","music","2"}
    };

    cout << solution(input);

    return 0;
}
/**


 *
 *
#include <bits/stdc++.h>
 using namespace std;
bool possi(vector<int> &vec,int now){
    for(int i=0;i<vec.size();i++)
        if((vec[i]&now)==vec[i])return false;
    return true;
}
int solution(vector<vector<string>> relation) {
    int n=relation.size();
    int m=relation[0].size();
    vector<int> ans;
    for(int i=1;i<(1<<m);i++){
        set<string> s;
        for(int j=0;j<n;j++){
            string now="";
            for(int k=0;k<m;k++){
                if(i&(1<<k))now+=relation[j][k];
            }
            s.insert(now);
        }
        if(s.size()==n&&possi(ans,i))ans.push_back(i);
    }
    return ans.size();
}
 */
