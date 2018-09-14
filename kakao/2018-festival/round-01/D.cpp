#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

#define MAX 250002
int N, Q;
bool ans[MAX];

struct p {
    int n;
    int x,y;
} point[MAX];
p temp[MAX];
bool x_compare(const p &p1, const p &p2) { return p1.x<p2.x; }
bool y_compare(const p &p1, const p &p2) { return p1.y<p2.y; }
struct query {
    int n, s, d;
    int hp;
    bool operator < (const query &q2) const { return hp<q2.hp; }
} query[MAX];
struct dst {
    int a, b;
    int d;
    dst(int m, int n, int l) { a=m, b=n, d=l; }
    bool operator < (const dst &dst2) const { return d>dst2.d; }
};
priority_queue<dst> heap;

// union-find.
class UF {
public:
    int parent[MAX];
    int size[MAX];
    UF() { for(int i=0; i<MAX; i++) parent[i]=i, size[i]=1; }
    int find(int p) { while(p!=parent[p]) p=parent[p]; return p; }
    bool connected(int p, int q) { return find(p)==find(q); }
    void merge(int p, int q) { int rp = find(p); int rq = find(q); if (rp == rq) return;
        if(size[rp]<size[rq]) { parent[rp] = rq; size[rq]+=size[rp]; } else { parent[rq] = rp; size[rp]+= size[rq]; } }
} uf;

bool DEBUG = true;

int main() {

//    FILE *fp = freopen("../data/kakao/D.input", "r", stdin);
//    if(!fp)
//        perror("freopen error");
    scanf("%d%d", &N, &Q);
    for(int i=1; i<N+1; i++) point[i].n = i, scanf("%d%d", &point[i].x, &point[i].y);
    memcpy(temp, point, sizeof(p)*(N+1));

    sort(temp+1, temp+N+1, x_compare);
    for(int i=2; i<N+1; i++) { int a = temp[i-1].n, b = temp[i].n; heap.push(dst(a, b, point[b].x-point[a].x)); }
    sort(temp+1, temp+N+1, y_compare);
    for(int i=2; i<N+1; i++) { int a = temp[i-1].n, b = temp[i].n; heap.push(dst(a, b, point[b].y-point[a].y)); }

    for(int i=0; i<Q; i++) query[i].n = i, scanf("%d%d%d", &query[i].s, &query[i].d, &query[i].hp);
    sort(query, query+Q);

    // O(Qlog**N), and amortized O(Nlog**N)(~=O(N)).
    for(int i=0; i<Q; i++) {
//        cout << query[i].n << ": " << query[i].s << "," << query[i].d << ".. " << query[i].hp << "\n";
        while(heap.size()>0&&heap.top().d<=query[i].hp) {
            dst t = heap.top(); heap.pop();
            uf.merge(t.a, t.b);
        }
        ans[query[i].n] = uf.connected(query[i].s, query[i].d);
    }

    for(int i=0; i<Q; i++) puts(ans[i] ? "YES" : "NO");
    return 0;
}
