#include <iostream>
#include <cstdio>
#include <vector>

//using namespace std;
//
//#define MAX_N 201
//#define MAX_M 201
//
//int N, M;
//int adj[MAX_N][MAX_M];
//vector<int> aMatch, bMatch;
//vector<bool> visited;

int dfs(int a) {

    if(visited[a])
        return false;
    visited[a] = true;

    for(int b=0; b<M; b++) {
        if(adj[a][b]) {
            if(bMatch[b]==-1||dfs(bMatch[b])) {
                aMatch[a] = b;
                bMatch[b] = a;
                return true;
            }
        }
    }
    return false;
}

int bipartite_match() {

    aMatch = vector<int>(N, -1);
    bMatch = vector<int>(M, -1);

    int size = 0;
    for(int i=0; i<N; i++) {
        visited = vector<bool>(N, 0);
        if(dfs(i))
            size++;
    }

    return size;
}

int main() {

//    FILE *fp = freopen("../data/2188.input", "r", stdin);
//    if(!fp)
//        perror("freopen error");

    int b, k;
    scanf("%d%d", &N, &M);
    for(int a=0; a<N; a++) {
        scanf("%d", &k);
        while(k--) scanf("%d", &b), adj[a][b-1] = true;
    }

    cout << bipartite_match() << "\n";
    return 0;
}
