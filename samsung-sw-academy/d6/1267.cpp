#include <iostream>
#include <vector>

using namespace std;
#define MAX 1001
int tc, t;
int V, E;
struct node {
    vector<int> adjs;
} nodes[MAX];
int visited[MAX];
int s[MAX], st;

void topological_sort(int i) {
    for(auto adj: nodes[i].adjs) {
        if(!visited[adj]) {
            visited[adj] = 1;
            topological_sort(adj);
        }
    }
    s[st++] = i;
}

int main() {

    tc = 10, t = 0;
    while(t++ < tc) {

        for(int i=0; i<MAX; i++)
            nodes[i].adjs.clear(), visited[i] = 0;

        scanf("%d%d", &V, &E);
        int a, b;
        for(int i=0; i<E; i++) {
            scanf("%d%d", &a, &b);
            nodes[a].adjs.push_back(b);
        }

        st = 0;
        for(int i=1; i<V+1; i++)
            if(!visited[i]) {
                visited[i] = 1;
                topological_sort(i);
            }

        printf("#%d", t);
        while(st) printf(" %d", s[--st]);
        printf("\n");
    }

    return 0;
}
