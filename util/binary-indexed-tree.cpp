#include <iostream>

using namespace std;

class segment_tree {
public:
    int size;
    vector<int> tree;
    segment_tree(vector<int> &input) {
        size = input.size();
        int h = (int)ceil(log2(size));
        tree.resize(1<<(h+1));
        init(input, 1, 0, size-1);
    }
    int init(vector<int> &input, int now, int s, int e) {
        if(s==e) return tree[now] = input[s];
        else return tree[now] = init(input, 2*now, s, (s+e)/2)
                                + init(input, 2*now+1, (s+e)/2+1, e);
    }
    int upd(int pos, int val, int now, int s, int e) {
        if(pos<s||pos>e) return tree[now]; // should return original val to upper node.
        if(s==e) return tree[now] = val;
        else return tree[now] = upd(pos, val, 2*now, s, (s+e)/2)
                                + upd(pos, val, 2*now+1, (s+e)/2+1, e);
    }
    int qry(int l, int r, int now, int s, int e) {
        if(l>e||r<s) return 0; // need to tune.
        if(l<=s&&e<=r) return tree[now];
        return qry(l, r, 2*now, s, (s+e)/2)
               + qry(l, r, 2*now+1, (s+e)/2+1, e);
    }
};
