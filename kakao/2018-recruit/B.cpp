#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

struct stage {
    int n;
    int success, total;
    float p;
    bool operator < (const stage &s2) const {
        if(p>s2.p) return 1;
        else if(p==s2.p) return n<s2.n;
        else return 0;
    }
};

vector<int> solution(int N, vector<int> stages) {

    vector<int> cnt(N+2), sum(N+2);
    stage ss[N+2];

    for(int i=0; i<stages.size(); i++)
        cnt[stages[i]]++;
    sum[N+1] = cnt[N+1];
    for(int i=N; i>0; i--)
        sum[i] = cnt[i]+sum[i+1];
    for(int i=1; i<N+1; i++) {
        ss[i].n = i;
        ss[i].p = sum[i]? (cnt[i])/float(sum[i]):0;
    }
    sort(ss+1, ss+N+1);
    vector<int> ans;
    for(int i=1; i<N+1; i++)
        ans.push_back(ss[i].n);

    return ans;
}

int main() {

    int n[2] = {5, 4};
    vector<vector<int>> ss(2);
    ss[0] = {2, 1, 2, 6, 2, 4, 3, 3};
    ss[1] = {4, 4, 4, 4, 4};

    for(int i=0; i<2; i++) {

        vector<int> sol = solution(n[i], ss[i]);

        for(int j=0; j<sol.size(); j++)
            cout << sol[j] << " ";
        cout << "\n\n";
    }

}