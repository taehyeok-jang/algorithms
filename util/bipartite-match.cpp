#include <cstdio>
#include <vector>
#include <iostream>

/**
 * Bipartite Match
 * Time Complexity: O(VE). for each vertext, it can iterate maximum amortized E. so O(VE).
 */
using namespace std;

#define MAX 1001
int N, M;
bool visited[MAX]; // group 'a's visit.
int b[MAX];
vector<vector<int>> node;
int dfs(int here) {
    if(visited[here]) return 0;
    visited[here] = 1;
    for(int i=0; i<node[here].size(); i++) {
        int there = node[here][i];
        if(b[there]==-1||dfs(b[there])) { // can b[there] point to another elem in group 'b'?
            b[there] = here; // a' here <-> b' there.
            return 1;
        }
    }
    return 0;
}
int bmatch() {
    int ret = 0;
    for(int i=0; i<N; i++) {
        memset(visited, 0, sizeof(bool)*MAX);
        if(dfs(i)) ret++;
    }
    return ret;
}

int main() {

//    FILE *fp = freopen("../data/11375.input", "r", stdin);
//    if(!fp)
//        perror("freopen error");

    int there, k;
    scanf("%d%d", &N, &M);
    node = vector<vector<int>>(N);
    memset(b, -1, sizeof(int)*MAX);
    for(int here=0; here<N; here++) {
        scanf("%d", &k);
        while(k--) scanf("%d", &there), node[here].push_back(there-1);
    }

    cout << bmatch() << "\n";
    return 0;
}

