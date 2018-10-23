#include <iostream>
#include <cmath>
using namespace std;
#define MAX 1000005
typedef long long ll;
int N, M, K;
ll A[MAX];

struct segment_tree {
    int size;
    ll *tree, *lazy;
    segment_tree(ll arr[], int n) {
        size = n;
        int h = (int)ceil(log2(size));
        tree = new ll[1<<(h+1)];
        lazy = new ll[1<<(h+1)];
        for(int i=0; i<(1<<(h+1)); i++) lazy[i] = 0;
        init(arr, 1, 0, size-1);
    }
    ll init(ll arr[], int now, int s, int e) {
        if(s==e) return tree[now] = arr[s];
        else return tree[now] = init(arr, 2*now, s, (s+e)/2)
                                + init(arr, 2*now+1, (s+e)/2+1, e);
    }
    void propagate(int now, int s, int e) {
        if(lazy[now]==0) return;
        if(s!=e) { // not leaf node.
            lazy[2*now] += lazy[now];
            lazy[2*now+1] += lazy[now];
        }
        tree[now] += lazy[now]*(e-s+1);
        lazy[now] = 0;
    }
    ll upd(int l, int r, int val, int now, int s, int e) {
        propagate(now, s, e);
        if(l>e||r<s) return tree[now];
        if(l<=s&&e<=r) {
            lazy[now] += val;
            propagate(now, s, e); // update tree, lazy.
            return tree[now];
        }
        return tree[now] = upd(l, r, val, 2*now, s, (s+e)/2)
                           + upd(l, r, val, 2*now+1, (s+e)/2+1, e);
    }
    ll qry(int l, int r, int now, int s, int e) {
        propagate(now, s, e);
        if(l>e||r<s) return 0;
        if(l<=s&&e<=r) return tree[now];
        return qry(l, r, 2*now, s, (s+e)/2)
               + qry(l, r, 2*now+1, (s+e)/2+1, e);
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin >> N >> M >> K;
    for(int i=0; i<N; i++)
        cin >> A[i];
    segment_tree st(A, N);
    int a, b, c, d;
    for(int i=0; i<M+K; i++) {
        cin >> a;
        if(a==1) {
            cin >> b >> c >> d;
            st.upd(b-1, c-1, d, 1, 0, st.size-1);
        }
        else {
            cin >> b >> c;
            cout << st.qry(b-1, c-1, 1, 0, st.size-1) << "\n";
        }
    }
    return 0;
}
