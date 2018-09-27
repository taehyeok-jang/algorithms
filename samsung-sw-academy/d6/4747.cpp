#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
#define MAX 10001
int tc, t;
int N, AVG;
int visited[MAX], V[MAX];
vector<int> v1, v2, v3;

// TODO time complexity..?
bool dfs(int idx, int val, vector<int> &vec) {

    if(val==AVG) return 1;
    if(idx==N) return 0;
    if(visited[idx]) return dfs(idx+1, val, vec); // in case for v2, v3.

    // 1. first include V[i] unless val+V[i]>AVG,
    // 2. next or far next return 0, jump to i+1.
    for(int i=idx; i<N; i++) {
        if(visited[i]||val+V[i]>AVG) continue;
        vec.push_back(V[i]);
        visited[i] = 1;
        if(dfs(i+1, val+V[i], vec)) return 1;
        vec.pop_back();
        visited[i] = 0;
    }
    // if there is no elem that satisfies val+V[i]<AVG at idx,
    return 0;
}

int main() {

//    FILE *fp = freopen("../data/battle.input", "r", stdin);
//    if(!fp)
//        perror("freopen error");

    scanf("%d", &tc);
    t = 0;
    while(t++ < tc) {

        for(int i=0; i<MAX; i++) visited[i] = 0;
        v1.clear(), v2.clear(), v3.clear();

        scanf("%d", &N);
        int sum = 0;
        for(int i=0; i<N; i++) {
            scanf("%d", &V[i]);
            sum += V[i];
        }
        sort(V, V+N, greater<int>());
        AVG = sum/3;

        dfs(0, 0, v1);
        dfs(0, 0, v2);
        dfs(0, 0, v3);

        // TODO then how to adjust v1, if dfs(v2) return 0?
        printf("#%d\n", t);
        for(int i=0; i<v1.size(); i++) printf("%d ", v1[i]);
        printf("\n");
        for(int i=0; i<v2.size(); i++) printf("%d ", v2[i]);
        printf("\n");
        for(int i=0; i<v3.size(); i++) printf("%d ", v3[i]);
        printf("\n");
    }

    return 0;
}


/*
 *
*
bool dfs(int idx, int val, vector<int> &vec) {

    cout << idx << ", " << val << "\n";
    if(val==AVG) { cout << "success! return 1.\n"; return 1; }
    if(idx==N) return 0;
    if(visited[idx]) return dfs(idx+1, val, vec); // in case for v2, v3.

    // 1. first include V[i] unless val+V[i]>AVG,
    // 2. next or far next return 0, jump to i+1.
    for(int i=idx; i<N; i++) {
        if(val+V[i]>AVG) continue;
        vec.push_back(V[i]);
        visited[i] = 1;
        if(dfs(i+1, val+V[i], vec)) {
            cout << idx << ", " << val << " ";
            cout << "return 1.\n";
            return 1;
        }
        vec.pop_back();
        visited[i] = 0;
    }
    // if there is no elem that satisfies val+V[i]<AVG at idx,
    cout << "return 0.\n";
    return 0;
}
 */