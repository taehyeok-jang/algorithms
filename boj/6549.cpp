#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

struct segment_tree {
    int size;
    vector<int> input;
    vector<int> tree;
    segment_tree(vector<int> &ii) {
        input = ii;
        size = input.size();
        int h = (int)ceil(log2(size));
        tree.resize(1<<(h+1));
        init(input, 1, 0, size-1);
    }
    int init(vector<int> &input, int now, int s, int e) {
        if(s==e) return tree[now] = s;
        else {
            int m1 = init(input, 2*now, s, (s+e)/2);
            int m2 = init(input, 2*now+1, (s+e)/2+1, e);
            if(input[m1]<=input[m2]) return tree[now] = m1;
            else                     return tree[now] = m2;
        }
    }
    int qry(int now, int s, int e, int l, int r) {
        if(l>e||r<s) return -1;
        if(l<=s&&e<=r) return tree[now];
        int m1 = qry(2*now, s, (s+e)/2, l, r);
        int m2 = qry(2*now+1, (s+e)/2+1, e, l, r);
        if(m1==-1||m2==-1) return (m1==-1)? m2:m1;
        return (input[m1]<=input[m2])? m1:m2;
    }
    long long largest(int l, int r) {
        int m = this->qry(1, 0, size-1, l, r);
        long long area = (long long)(r-l+1)*(long long)input[m];
        if(l<m) area = max(area, largest(l, m-1));
        if(m<r) area = max(area, largest(m+1, r));
        return area;
    }
};
#ifdef DEBUG
#endif

int N;
vector<int> A;
int main() {

    scanf("%d", &N);
    A.resize(N);
    for(int i=0; i<N; i++) scanf("%d", &A[i]);
    segment_tree st(A);

    printf("%lld\n", st.largest(0, N-1));

    return 0;
}
