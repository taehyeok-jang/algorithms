#include <iostream>
#include <vector>
#include <set>

using namespace std;

int tc, t;
int N, ans, F[1002];
vector<vector<int>> tree;
set<int> root;
int visited[1002];

int max(int a, int b) { return a>b? a:b; }

int dist(int here) {
    int d = 0;
    visited[here] = 1;
    for(auto child: tree[here])
        if(!visited[child])
            d = max(d, dist(child));
    return 1+d;
}

void find_circle(int here, vector<int> &vec) {

    visited[here] = 1;
    vec.push_back(here);

    if(visited[F[here]]) {
        int i = vec.size()-1, count = 1;
        while(i>=0&&vec[i]!=F[here])
            i--, count++;
        ans = max(ans, i<0? 0:count); // i<0: no cycle.
    }
    else {
        find_circle(F[here], vec);
    }
}

int main() {

//    FILE *fp = freopen("../data/battle.input", "r", stdin);
//    if(!fp)
//        perror("freopen error");

    scanf("%d", &tc);
    t = 0;
    while(t++ < tc) {

        scanf("%d", &N);
        for(int i=1; i<N+1; i++) scanf("%d", &F[i]);

        tree.clear(); tree.resize(N+1);
        root.clear();
        for(int i=1; i<N+1; i++) visited[i] = 0;

        for(int i=1; i<N+1; i++) tree[F[i]].push_back(i);
        for(int i=1; i<N+1; i++) if(i==F[F[i]]) root.insert(max(i, F[i]));

        ans = 0;
        for(auto r: root) {
            visited[r] = 1;
            int d = 0;
            for(auto child: tree[r])
                if(child!=F[r])
                    d = max(d, dist(child));
            ans += (1+dist(F[r])+d);
        }
        for(int i=1; i<N+1; i++) {
            vector<int> vec;
            if(!visited[i])
                find_circle(i, vec); // update ans.
        }

        printf("#%d %d ", t, ans);
    }

    return 0;
}
