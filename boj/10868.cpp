#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

#define MAX 2000000000
int N, M;
vector<int> A;

class BIT {
public:
    int size;
    vector<int> tree;

    BIT(vector<int> &input) {
        size = input.size();
        int h = (int)ceil(log2(size));
        tree = vector<int>(1<<(h+1));
        init(input, 1, 0, size-1);
    }
    int init(vector<int> &input, int node, int start, int end) {
        if(start==end) return tree[node] = input[start];
        else return tree[node] = min(init(input, 2*node, start, (start+end)/2)
                                 ,init(input, 2*node+1, (start+end)/2+1, end));
    }
    void update(int pos, int val) {
        _update(pos, val, 1, 0, size-1);
    }
    int _update(int pos, int val, int node, int start, int end) {
        if(pos<start||pos>end) return tree[node];
        if(start==end) { tree[node] += val; return tree[node]; }
        tree[node] = min(_update(pos, val, 2*node, start, (start+end)/2)
                     , _update(pos, val, 2*node+1, (start+end)/2+1, end));
        return tree[node];
    }
    int query(int left, int right) {
        return _query(1, 0, size-1, left, right);
    }
    int _query(int node, int start, int end, int left, int right) {
        if(left>end||right<start) return MAX; // exclusive.
        if(left<=start&&end<=right) return tree[node]; // inclusive.
        return min(_query(2*node, start, (start+end)/2, left, right)
               , _query(2*node+1, (start+end)/2+1, end, left, right));
    }
};

int main() {

    scanf("%d%d", &N, &M);
    A = vector<int>(N);
    for(int i=0; i<N; i++)
        scanf("%d", &A[i]);

    BIT bit(A);
    int a, b;
    for(int i=0; i<M; i++) {
        scanf("%d%d", &a, &b);
        printf("%d\n", bit.query(a-1, b-1));
    }

    return 0;
}
