#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int N, K;
int ans;
vector<vector<int>> dict;

void dfs(int idx, int p, int cnt, int reg) {

    if(idx==N) {
        ans = max(ans, cnt);
        return;
    }

    int check = 0, need = 0;
    for(auto c: dict[idx])
        if(((1<<c)&reg)==0) check |= (1<<c);
    for(int i=0; i<26; i++)
        if(((1<<i)&check)) need++;

    if(need==0) {
        dfs(idx+1, p, cnt+1, reg);
        return;
    }
    else {
        // not use
        dfs(idx+1, p, cnt, reg);
        // use
        if(p>=need) {
            for(auto c: dict[idx])
                reg |= (1<<c);
            dfs(idx+1, p-need, cnt+1, reg);
        }
    }
}

int main() {

//    FILE *fp = freopen("../data/battle.input", "r", stdin);
//    if(!fp)
//        perror("freopen error");

    scanf("%d%d", &N, &K);
    if(K<5) { printf("%d", 0); return 0; }
    if(K==26) { printf("%d", N); return 0; }

    dict.resize(N);
    char buf[20];
    for(int i=0; i<N; i++) {
        scanf("%s", buf);
        for(int j=4; j<strlen(buf)-4; j++)
            dict[i].push_back(buf[j]-97);
    }

    int reg = (1<<('a'-97)) + (1<<('c'-97)) + (1<<('i'-97))
                + (1<<('n'-97)) + (1<<('t'-97));
    ans = 0;
    dfs(0, K-5, 0, reg);
    printf("%d", ans);
    return 0;
}
