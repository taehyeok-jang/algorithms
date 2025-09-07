#include <iostream>

using namespace std;

// Segment Tree: A binary tree data structure that stores information about array segments (ranges).
// Each node represents an interval [l, r] and aggregates values (e.g., sum, min, max) over that range. 
// It supports:
//  - Range queries in O(log n)
//  - Point or range updates in O(log n)
// The entire tree can be built in O(n).

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
        return tree[now] = upd(pos, val, 2*now, s, (s+e)/2)
                                + upd(pos, val, 2*now+1, (s+e)/2+1, e);
    }
    int qry(int l, int r, int now, int s, int e) {
        if(l>e||r<s) return 0; // need to tune.
        if(l<=s&&e<=r) return tree[now];
        return qry(l, r, 2*now, s, (s+e)/2)
               + qry(l, r, 2*now+1, (s+e)/2+1, e);
    }
};


struct segment_tree_lazy_prop {
    int size;
    int *tree, *lazy;
    segment_tree_lazy_prop(int arr[], int n) {
        size = n;
        int h = (int)ceil(log2(size));
        tree = new int[1<<(h+1)];
        lazy = new int[1<<(h+1)];
        for(int i=0; i<(1<<(h+1)); i++) lazy[i] = 0;
        init(arr, 1, 0, size-1);
    }
    int init(int arr[], int now, int s, int e) {
        if(s==e) return tree[now] = arr[s];
        else return tree[now] = init(arr, 2*now, s, (s+e)/2)
                                + init(arr, 2*now+1, (s+e)/2+1, e);
    }
    void prop(int now, int s, int e) {
        if(lazy[now]==0) return;
        if(s!=e) { // not leaf node.
            lazy[2*now] += lazy[now];
            lazy[2*now+1] += lazy[now];
        }
        tree[now] += lazy[now]*(e-s+1);
        lazy[now] = 0;
    }
    int upd(int l, int r, int val, int now, int s, int e) {
        prop(now, s, e);
        if(l>e||r<s) return tree[now];
        if(l<=s&&e<=r) {
            lazy[now] += val;
            prop(now, s, e); // update tree, lazy.
            return tree[now];
        }
        return tree[now] = upd(l, r, val, 2*now, s, (s+e)/2)
                           + upd(l, r, val, 2*now+1, (s+e)/2+1, e);
    }
    int qry(int l, int r, int now, int s, int e) {
        prop(now, s, e);
        if(l>e||r<s) return 0;
        if(l<=s&&e<=r) return tree[now];
        return qry(l, r, 2*now, s, (s+e)/2)
               + qry(l, r, 2*now+1, (s+e)/2+1, e);
    }
};
