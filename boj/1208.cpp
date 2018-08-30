#include <iostream>
#include <cstring>
#include <map>

#define MAX 2000001
#define OFFSET 1000001
using namespace std;

int N, S;
int A[41];
int check[MAX];
//map<pair<int, double>, double> cache;
//long long cache[41][1000001];

// TODO memory overflow.
//long long solve(int idx, int sum) {
//
//    if(idx==N) return 0;
//    pair<int, int> key = make_pair(idx, sum+offset);
//    if(cache[key]) return cache[key];
//
//    long long ans = (sum+A[idx]==S)? 1:0;
//    ans += solve(idx+1, sum);
//    ans += solve(idx+1, sum+A[idx]);
//
//    return cache[key] = ans+offset;
//}

int main() {

    scanf("%d%d", &N, &S);
    for(int i=0; i<N; i++) scanf("%d", &A[i]);

    int m = MAX;
    for(int i=0; i<N; i++) {
        for(int j=m; j>=0; j--) {
            if(check[j]) {
                m = m>j? m:j;
                check[j+A[i]] += 1;
            }
        }
    }

//    printf("%lld", solve(0, 0));
    return 0;
}
