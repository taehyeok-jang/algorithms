#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

#define MAX 1001
#ifdef DEBUG
#endif

int tc, t;
int N, M;
bool visited[MAX];

struct node {
    vector<int> childs;
} nodes[MAX];

void dfs(int idx) {
    visited[idx] = 1;
    for(auto c: nodes[idx].childs)
        if(!visited[c])
            dfs(c);
}

int main() {

    memset(visited, 0, sizeof(bool)*MAX);
    for(int i=1; i<N+1; i++) nodes[i].childs.clear();

    scanf("%d%d", &N, &M);
    int a, b;
    for(int i=0; i<M; i++) {
        scanf("%d%d", &a, &b);
        nodes[a].childs.push_back(b);
        nodes[b].childs.push_back(a);
    }

    int cnt = 0;
    for(int i=1; i<N+1; i++)
        if(!visited[i]) {
            cnt++;
            dfs(i);
        }

    printf("%d", cnt);
    return 0;
}
