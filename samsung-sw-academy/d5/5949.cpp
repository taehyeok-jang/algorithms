#include <iostream>
using namespace std;
int tc, t;
int main() {
    ios::sync_with_stdio(false);
    string S, T;
    cin >> tc;
    t = 0;
    while(t++ < tc) {
        cin >> S >> T;
        int cnt = 0;
        for(int i=0; i<S.size(); i++)
            if(S[i]=='a') cnt++;

        long long ans = 0;
        int i = 0, j = 0, k = 0;
        while(k<cnt) { // length of S, T same.

            while(i<S.size()&&S[i]=='b') i++;
            while(j<T.size()&&T[j]=='b') j++;
//            cout << i << ", " << j << "\n";
            ans += (i-j>0)? i-j:j-i;
            i++, j++, k++;
        }
        cout << "#" << t << " " << ans << "\n";
    }
    return 0;
}

/**
2
abb
bba
abab
baba
 */