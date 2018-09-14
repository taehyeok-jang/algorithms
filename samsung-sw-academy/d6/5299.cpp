#include <iostream>
#include <cstring>

using namespace std;

#define MAX 1000000001 // 10^9
#define sqrt_MAX 31623 // 10^4.5
#define OVERFLOW 0

// arr[i][j]. the value of decimal number, which is 11...1(i) of length j.
int arr[sqrt_MAX][31]; // memory ~= 10^6.
int tc, t;
int N;

int main() {

    // pre process.
    long long n;
    for(int i=2; i<sqrt_MAX; i++) // O(10^4.5*31) ~= O(10^6)
        for(int j=2; j<32; j++) {
            if(j==2) { arr[i][j] = i+1; continue; }
            n = (long long)arr[i][j-1]*i+1;
            if(n<MAX) arr[i][j] = n;
            else break;
        }

    scanf("%d", &tc);
    t = 0;
    while(t++ < tc) {

        scanf("%d", &N);
        long long ans = 0;

        // 2 digits.
        for(int a=1; a<(N/a-1); a++)  // O(sqrt(N))
            ans += ((N/a-2)*(N/a+1))/2; // sum of 2~N/a-1.

        // more than 3 digits.
        for(int a=1; a*a<(N/a-1); a++) { // O(sqrt(N))
            for(int i=2; i*i+i+1<=N/a; i++) { // O(sqrt(N)) ... O(N^(1/4)).
                for(int j=3; j<31; j++) { // O(C).
                    if(arr[i][j]==OVERFLOW) break;
                    if(arr[i][j]*a<=N) ans++;
                    else break;
                }
            }
        }
        printf("#%d %lld\n", t, ans);
    }

    return 0;
}

