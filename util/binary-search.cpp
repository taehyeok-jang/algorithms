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

/*
====================================================
 std::lower_bound / std::upper_bound 
====================================================

DEF. 
----------------------------------------------------
template< class ForwardIt, class T >
ForwardIt lower_bound( ForwardIt first, ForwardIt last, const T& value );

template< class ForwardIt, class T >
ForwardIt upper_bound( ForwardIt first, ForwardIt last, const T& value );

Difference? 
----------------------------------------------------
- lower_bound : return an index of first element (>= value).
- upper_bound : return an index of first element (> value).

E.g. 
----------------------------------------------------
arr = {1, 2, 4, 4, 4, 7, 9}

lower_bound(arr, arr+7, 4) → arr+2 (4, the first 4 among 4's.)
upper_bound(arr, arr+7, 4) → arr+5 (7, the first element greater than 4.)

즉:

          lower_bound
              ↓
arr = {1, 2, [4, 4, 4], 7, 9}
                        ↑
                  upper_bound

applications.
----------------------------------------------------

// 1. check the existence of a value. 
auto it = lower_bound(arr.begin(), arr.end(), x);
if (it != arr.end() && *it == x) {
    // x exists.
}

// 2. counting; multiset (allow duplicates)
int count = upper_bound(arr.begin(), arr.end(), x) 
          - lower_bound(arr.begin(), arr.end(), x);

// 3. floor / ceil 
// ceil: lower_bound → minimum among elements >= x
// floor: upper_bound-1 → maximum among elements <= x.

====================================================
*/
