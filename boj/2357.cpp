#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAX 2000000000
#define MIN -2000000000

struct segment_tree {
    int size;
    int *tree;
    bool comp;
    segment_tree(int input[], int s, bool c) {
        size = s;
        int h = (int)ceil(log2(size));
        tree = new int[(1<<(h+1))];
        comp = c;
        init(input, 1, 0, size-1);
    }
    int init(int input[], int now, int s, int e) {
        if(s==e) return tree[now] = input[s];
        else return tree[now] = comp? max(init(input, 2*now, s, (s+e)/2), init(input, 2*now+1, (s+e)/2+1, e))
                                     :min(init(input, 2*now, s, (s+e)/2), init(input, 2*now+1, (s+e)/2+1, e));
    }
    int qry(int now, int s, int e, int l, int r) {
        if(e<l||r<s) return comp? MIN:MAX; // exclusive
        if(l<=s&&e<=r) return tree[now];
        return comp? max(qry(2*now, s, (s+e)/2, l, r), qry(2*now+1, (s+e)/2+1, e, l, r))
                    :min(qry(2*now, s, (s+e)/2, l, r), qry(2*now+1, (s+e)/2+1, e, l, r));
    }
};

//#define DEBUG 1
#ifdef DEBUG
#endif

int N, M;
int A[100001];

int main() {

    scanf("%d%d", &N, &M);
    for(int i=1; i<N+1; i++) scanf("%d", &A[i]);
    segment_tree min_tree(A, N+1, 0), max_tree(A, N+1, 1);
    int a, b;
    for(int i=0; i<M; i++) {
        scanf("%d%d", &a, &b);
        printf("%d %d\n", min_tree.qry(1, 0, N, a, b), max_tree.qry(1, 0, N, a, b));
    }
    return 0;
}
