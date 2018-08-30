#include <stdio.h>
#include <algorithm>

using namespace std;
int A[100], mx;// sliding window.
char buf[1<<10];
char read() {
    static int idx = 1<<10;
    if (idx == 1<<10) { fread(buf, 1, 1<<10, stdin); idx = 0; }
    return buf[idx++];
}
int readInt() {
    int sum = 0;
    char now = read();
    while (now == 10 || now == 32) now = read();
    while (now >= 48 && now <= 57) { sum = sum*10 + now-48; now = read(); }
    return sum;
}

int main() {

    int N, t, p;
    N = readInt();
    for(int i=1; i<N+1; i++) {
        t = readInt(); p = readInt();
        if(A[i%100]>mx) mx = A[i%100];
        else A[i%100] = mx;
        A[(i+t)%100] = max(A[(i+t)%100], A[i%100]+p);
    }

    printf("%d", max(mx, A[(N+1)%100]));
    return 0;
}
