#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

class BIT {
public:
    int size;
    vector<long long> tree;

    BIT(vector<long long> &input) {
        size = input.size();
        int h = (int)ceil(log2(size));
        tree = vector<long long>(1<<(h+1));
        init(input, 1, 0, size-1);
    }
    long long init(vector<long long> &input, int node, int start, int end) {
        if(start==end) return tree[node] = input[start];
        else return tree[node] = init(input, 2*node, start, (start+end)/2)
                                 + init(input, 2*node+1, (start+end)/2+1, end);
    }
    void update(int pos, int val) {
        _update(pos, val, 1, 0, size-1);
    }
    long long _update(int pos, int val, int node, int start, int end) {
        if(pos<start||pos>end) return tree[node];
        if(start==end) { tree[node] = val; return tree[node]; }
        tree[node] = _update(pos, val, 2*node, start, (start+end)/2)
                     + _update(pos, val, 2*node+1, (start+end)/2+1, end);
        return tree[node];
    }
    long long query(int left, int right) {
        return _query(1, 0, size-1, left, right);
    }
    long long _query(int node, int start, int end, int left, int right) {
        if(left>end||right<start) return 0; // exclusive.
        if(left<=start&&end<=right) return tree[node]; // inclusive.
        return _query(2*node, start, (start+end)/2, left, right)
               + _query(2*node+1, (start+end)/2+1, end, left, right);
    }
};

int N, M, K;
vector<long long> A;

int main() {

    scanf("%d%d", &N, &M);
    A = vector<long long>(N+1, 0);

    BIT bit(A);
    int q, a, b;
    for(int i=0; i<M; i++) {
        scanf("%d%d%d", &q, &a, &b);
        if(q==0) printf("%lld\n", bit.query(min(a, b), max(a, b)));
        if(q==1) bit.update(a, b);
    }

    return 0;
}
