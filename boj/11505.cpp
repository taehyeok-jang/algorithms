#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

#define MOD 1000000007

class segment_tree {
public:
    int size;
    vector<long long> tree;
    segment_tree(vector<long long> &input) {
        size = input.size();
        int h = (int)ceil(log2(size));
        tree.resize(1<<(h+1));
        init(input, 1, 0, size-1);
    }
    long long init(vector<long long> &input, int now, int s, int e) {
        if(s==e) return tree[now] = input[s];
        else {
            return tree[now] = (init(input, 2*now, s, (s+e)/2)
                         *init(input, 2*now+1, (s+e)/2+1, e))%MOD;
        }
    }
    long long upd(int pos, int val, int now, int s, int e) {
        if(pos<s||pos>e) return tree[now];
        if(s==e) return tree[now] = val;
        else return tree[now] = (upd(pos, val, 2*now, s, (s+e)/2)
                                *upd(pos, val, 2*now+1, (s+e)/2+1, e))%MOD;
    }
    long long qry(int l, int r, int now, int s, int e) {
        if(l>e||r<s) return 1;
        if(l<=s&&e<=r) return tree[now];
        return (qry(l, r, 2*now, s, (s+e)/2)
               *qry(l, r, 2*now+1, (s+e)/2+1, e))%MOD;
    }
};

int N, M, K;
vector<long long> A;
int main() {

    scanf("%d%d%d", &N, &M, &K);
    A.resize(N+1, 1);
    for(int i=1; i<N+1; i++) scanf("%d", &A[i]);

    segment_tree st(A);
    int q, a, b;
    for(int i=0; i<M+K; i++) {
        scanf("%d%d%d", &q, &a, &b);
        if(q==1) st.upd(a, b, 1, 0, N);
        if(q==2) printf("%lld\n", st.qry(a, b, 1, 0, N));
    }
    return 0;
}
