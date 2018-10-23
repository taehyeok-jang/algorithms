#include <stdio.h>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#define MAX (int)1e6+1
using namespace std;
int N;
int A[MAX];

map<int, vector<int>> nodes;

/**
 * Impl Code of 'https://kks227.blog.me/220791986409?Redirect=Log&from=postView'
 * TLE -> map as storage is little slow...
 */

// contains max length of LIS in range 0~i.
struct seg_tree {
    int size;
    int *tree;
    seg_tree(int n) {
        size = n;
        int h = (int)ceil(log2(n));
        tree = new int[(1<<(h+1))];
        init(1, 0, size-1);
    }
    int init(int now, int s, int e) {
        if(s==e) return tree[now] = 0;
        return tree[now] = max(init(2*now, s, (s+e)/2),
                               init(2*now+1, (s+e)/2+1, e));
    }
    int qry(int l, int r, int now, int s, int e) {
        if(l>e||r<s) return 0;
        if(l<=s&&e<=r) return tree[now];
        return max(qry(l, r, 2*now, s, (s+e)/2),
                   qry(l, r, 2*now+1, (s+e)/2+1, e));
    }
    int upd(int pos, int val, int now, int s, int e) {
        if(pos<s||pos>e) return tree[now];
        if(s==e) return tree[now] = val;
        return tree[now] = max(upd(pos, val, 2*now, s, (s+e)/2),
                               upd(pos, val, 2*now+1, (s+e)/2+1, e));
    }
};

int main() {
    scanf("%d", &N);
    for(int i=0; i<N; i++) scanf("%d", &A[i]);
    seg_tree st(N);

    for(int i=0; i<N; i++) nodes[A[i]].push_back(i);
    // complexity: total N elements partially sorted.
    for(auto it=nodes.begin(); it!=nodes.end(); it++)
        sort(it->second.begin(), it->second.end(), greater<int>());

    int elem; vector<int> idxs;
    int ans = 0, len;
    for(auto it=nodes.begin(); it!=nodes.end(); it++) {
        elem = it->first;
        idxs = it->second;
        for(int i=0; i<idxs.size(); i++) {
//            printf("%d %d\n", elem, idxs[i]);
            len = st.qry(0, i, 1, 0, N-1)+1;
            st.upd(i, len, 1, 0, N-1);
            ans = ans<len? len:ans;
        }
    }
    printf("%d", ans);
    return 0;
}


/*
#include <stdio.h>
#include <cmath>
#define MAX (int)1e6+1
using namespace std;
int N;
int A[MAX];

int max(int a, int b) { return a>b? a:b; }

// contains max length of LIS in range min_val...max_val.
struct seg_tree {
    int size;
    int *tree;
    seg_tree(int n) {
        size = n;
        int h = (int)ceil(log2(n));
        tree = new int[(1<<(h+1))];
        init(1, 0, size-1);
    }
    int init(int now, int s, int e) {
        if(s==e) return tree[now] = 0;
        return tree[now] = max(init(2*now, s, (s+e)/2),
                               init(2*now+1, (s+e)/2+1, e));
    }
    int qry(int l, int r, int now, int s, int e) {
        if(l>e||r<s) return 0;
        if(l<=s&&e<=r) return tree[now];
        return max(qry(l, r, 2*now, s, (s+e)/2),
                   qry(l, r, 2*now+1, (s+e)/2+1, e));
    }
    int upd(int pos, int val, int now, int s, int e) {
        if(pos<s||pos>e) return tree[now];
        if(s==e) return tree[now] = val;
        return tree[now] = max(upd(pos, val, 2*now, s, (s+e)/2),
                               upd(pos, val, 2*now+1, (s+e)/2+1, e));
    }
};

int main() {
    scanf("%d", &N);
    for(int i=0; i<N; i++) scanf("%d", &A[i]);
    seg_tree st(MAX);
    int ans = 0, len;
    for(int i=0; i<N; i++) {
        // len(=dp[i]): length of LIS which has A[i] at last element.
        // update tree[idx](idx corresponds to A[i] in seg_tree) to length of LIS, having A[i] as last element.
        len = st.qry(0, A[i]-1, 1, 0, MAX-1)+1;
        st.upd(A[i], len, 1, 0, MAX-1);
        ans = ans<len? len:ans;
    }
    printf("%d", ans);
    return 0;
}

*/
