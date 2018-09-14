/**
 * binary search, upper&lower bound's ideas are all same!.
 *
 */

int binary_search(int arr[], int val, int size) {

    int l, r, m;
    l = 0, r = size-1;
    while(l<=r) {
        m = (l+r)/2;
        if(arr[m]==val) return m;
        if(arr[m]>val) r = m-1;
        else           l = m+1;
    }
    return -1;
}

/**
 * tips.
 * var 'r' in upper_bound, lower_bound.
 * we update 'r' that satisfies v[m]>val or v[m]>=val, until logarithmic iteration ends.
 * so we can get minimum 'r'!
 */

int upper_bound(vector<int> &v, int val) {

    int l, r, m;
    l = 0, r = v.size;
    while(l<r) {
        m = (l+r)/2;
        if(v[m]>val) r = m;
        else         l = m+1;
    }
    return r; // return 'r'
}

int lower_bound(vector<int> &v, int val) {

    int l, r, m;
    l = 0, r = v.size;
    while(l<r) {
        m = (l+r)/2;
        if(v[m]>=val) r = m;
        else          l = m+1;
    }
    return r; // return 'r'
}

int main() {

    vector<int> tmp;
    tmp.resize(20);
    for(int i=0; i<20; i++) scanf("%d", &tmp[i]);

    int t;
    scanf("%d", &t);
    cout << lower_bound(tmp, t, 20) << "\n";
    cout << upper_bound(tmp, t, 20) << "\n";

    return 0;
}