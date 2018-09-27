#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int N, M;
vector<vector<int>> graph;
bool visited[100001];
int idx[100001], euler[200001], level[200001];
int k;

struct node {
    vector<int> childs;
} nodes[100001]; // node 1: root.

struct st {
    int size;
    int *tree;
    st(int n) {
        size = n;
        int h = (int)ceil(log2(n));
        tree = new int[1<<(h+1)];
        init(1, 0, size-1);
    }
    int init(int now, int s, int e) {
        if(s==e) return tree[now] = s;
        int left = init(2*now, s, (s+e)/2);
        int right = init(2*now+1, (s+e)/2+1, e);
        return tree[now] = level[left]<=level[right]? left:right;
    }
    // return idx that has minimum level at given range.
    int qry(int l, int r, int now, int s, int e) {
        if(l>e||r<s) return -1;
        if(l<=s&&e<=r) return tree[now];
        int left = qry(l, r, 2*now, s, (s+e)/2);
        int right = qry(l, r, 2*now+1, (s+e)/2+1, e);
        if(left==-1||right==-1) return left==-1? right:left;
        else return level[left]<=level[right]? left:right;
    }
};

void generate(int i) {
    visited[i] = 1;
    for(auto adj: graph[i]) {
        if(visited[adj]) continue;
        nodes[i].childs.push_back(adj);
        generate(adj);
    }
}

void euler_tour(int now, int depth) {
    euler[k] = now, level[k] = depth;
    idx[now] = k++;
    for(auto c: nodes[now].childs) {
        euler_tour(c, depth+1);
        euler[k] = now, level[k] = depth;
        k++;
    }
}

int max(int a, int b) { return a>b? a:b; }
int min(int a, int b) { return a<b? a:b; }

int main() {

    int a, b;
    scanf("%d", &N);
    graph.resize(N+1);
    for(int i=0; i<N-1; i++) {
        scanf("%d%d", &a, &b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    generate(1);

    k = 0;
    euler_tour(1, 0);
    st seg_tree(k);


    scanf("%d", &M);
    for(int i=0; i<M; i++) {
        scanf("%d%d", &a, &b);
        int ii = seg_tree.qry(min(idx[a],idx[b]), max(idx[a], idx[b]), 1, 0, k-1);
        printf("%d\n", euler[ii]);
    }

    return 0;
}
