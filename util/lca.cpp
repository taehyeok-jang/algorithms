#include <stdio.h>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

/**
 * where to apply LCA?
 * 1. find a distance between 2 nodes on tree.
 *      => dist[a]+dist[b]-2*dist[lca(a,b]
 * 2.
 */
struct node {
    int n;
    int key;
    node *left, *right;
};
/**
 * ver 1.
 * O(c*N)
 */
struct lca1 {

    bool find_path(node *root, vector<int> &path, int k) {

        if(root==NULL) return 0;

        path.push_back(root->key);
        if(root->key==k) return 1;
        if((root->left&&find_path(root->left, path, k))
           ||(root->right&&find_path(root->right, path, k)))
            return 1;

        path.pop_back();
        return 0;
    }

    int find_lca(node *root, int n1, int n2) {

        vector<int> path1, path2;
        if(!find_path(root, path1, n1)||!find_path(root, path2, n2))
            return -1;
        int i;
        for(i=0; i<path1.size()&&i<path2.size(); i++)
            if(path1[i]!=path2[i])
                break;
        return path1[i-1];
    }
};
/**
 * ver 2.
 * O(N).
 * single traversal, supposing both node n1, n2 exist.
 */
struct lca2 {

    node* find_lca(node *root, int n1, int n2) {

        if(root==NULL) return NULL;
        if(root->key==n1||root->key==n2) return root;

        node *l_lca = find_lca(root->left, n1, n2);
        node *r_lca = find_lca(root->right, n1, n2);

        if(l_lca&&r_lca) return root;
        return (l_lca!=NULL)? l_lca:r_lca;
    }
};

/**
 * ver 3.
 * use segment tree.
 *
 * why LCA algorithm that uses segment tree?
 * => if there are many queries for lca, we need to get in log(N) time.
 *
 * algorithm.
 * 1) generate tree.
 * 2) euler tour filling in euler[V+E], level[V+E] array.
 * 3) query by translated indexs.
 */
using namespace std;

int N, M;
vector<vector<int>> graph;
bool visited[100001];
int idx[100001], euler[200001], level[200001];
int k;

struct node {
    vector<int> childs;
} nodes[100001]; // node 1: root.

// return idx that has minimum level at given range.
// why need range qry? we can get idx that has max height in given range.
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
        // why <=?: we should get idx that first occurred in euler tour.
        return tree[now] = level[left]<=level[right]? left:right;
    }
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
// O(V+E).
void euler_tour(int now, int depth) {
    euler[k] = now, level[k] = depth;
    idx[now] = k++;
    for(auto c: nodes[now].childs) {
        euler_tour(c, depth+1);
        euler[k] = now, level[k] = depth;
        k++;
    }
}
int lca(st &seg_tree, int a, int b) {
    int ii = seg_tree.qry(min(idx[a],idx[b]), max(idx[a], idx[b]), 1, 0, seg_tree->size-1);
    return euler[ii];
}
int dist(int a, int b) {
    return level[idx[a]]+level[idx[b]]-2*level[idx[lca(a, b)]]; // TODO need check.
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
        printf("%d\n", lca(a, b));
    }

    return 0;
}

