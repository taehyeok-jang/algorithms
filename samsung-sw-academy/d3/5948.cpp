#include <iostream>
#include <algorithm>
using namespace std;
int tc, t;
int main() {
    int A[7], B[210];
    int visited[701] = {0,};
    cin >> tc;
    t = 0;
    while(t++ < tc) {
        for(int i=0; i<7; i++)
            cin >> A[i];
        sort(A, A+7, greater<int>());
        int idx = 0;
        for(int i=0; i<5; i++)
            for(int j=i+1; j<6; j++)
                for(int k=j+1; k<7; k++) {
                    if(visited[A[i]+A[j]+A[k]]==t) continue;
                    B[idx++] = A[i]+A[j]+A[k];
                    visited[A[i]+A[j]+A[k]] = t;
                }
        sort(B, B+idx, greater<int>());
        cout << "#" << t << " " << (B[4]) << "\n";
    }
    return 0;
}
