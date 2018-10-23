#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
int S[21][21];
int min(int a, int b) { return a<b? a:b; }
int abs(int n) { return n>0? n:-n; }
int main() {
    cin >> N;
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            cin >> S[i][j];

    vector<int> perm;
    for(int i=0; i<N/2; i++) perm.push_back(0);
    for(int i=0; i<N/2; i++) perm.push_back(1);

    int ans = 654321;
    vector<int> a, b;
    do {
        a.clear(), b.clear();
        for(int i=0; i<N; i++)
            if(perm[i]==0)  a.push_back(i);
            else            b.push_back(i);
        int aa = 0, bb = 0;
        for(int i=0; i<N/2; i++)
            for(int j=0; j<N/2; j++)
                aa += S[a[i]][a[j]], bb += S[b[i]][b[j]];
        ans = min(ans, abs(bb-aa));
    } while(next_permutation(perm.begin(), perm.end()));

    cout << ans;
    return 0;
}

/**
4
0 1 2 3
4 0 5 6
7 1 0 2
3 4 5 0
 */