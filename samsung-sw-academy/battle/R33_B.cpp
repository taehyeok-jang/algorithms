#include <iostream>
#include <vector>

using namespace std;
#define MAX 1001

int tc, t;
int N, M;
struct node {
    vector<int> adjs;
} nodes[MAX];
bool visited[MAX];

int q[MAX], f, r, size;


int main() {

//    FILE *fp = freopen("../data/3501.p", "r", stdin);
//    if(!fp)
//        perror("freopen error");

    scanf("%d", &tc);
    t = 0;
    while(t++ < tc) {

        for(int i=0; i<MAX; i++)
            nodes[i].adjs.clear(), visited[i] = 0;

        scanf("%d%d", &N, &M);
        int a, b;
        for(int i=0; i<M; i++) {
            scanf("%d%d", &a, &b);
            nodes[a].adjs.push_back(b);
            nodes[b].adjs.push_back(a);
        }

        size = f = r = 0;
        q[r++] = 1, visited[1] = 1;
        int depth = 0, ans = 0;
        while(depth<2) {
            size = r-f;
            while(size--) {
                int k = q[f++];
                for(auto adj: nodes[k].adjs)
                    if(!visited[adj]) {
                        q[r++] = adj, visited[adj] = 1;
                        ans++;
                    }
            }
            depth++;
        }

        printf("#%d %d\n", t, ans);
    }

    return 0;
}
