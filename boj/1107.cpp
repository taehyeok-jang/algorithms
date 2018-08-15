#include <iostream>
#include <cmath>
#include <queue>

//using namespace std;

#define MAX 1000000

int abs(int n) { return n>0? n:-n; }
int min(int a, int b) { return a<b? a:b; }

int main() {

    int n, m, t, a, s;
    bool b[10];
    scanf("%d%d", &n, &m);
    for(int i=0; i<10; i++) b[i] = true;
    while(m--) { scanf("%d", &t); b[t] = false; }
    int ans = abs(n-100);
    std::queue<int> q;
    for(int i=0; i<10; i++) if(b[i]) { q.push(i); }
    int cnt = 0;
    while(!q.empty()) {
        s=q.size(), cnt++;
        while(s--) {
            a=q.front(), q.pop();
            ans = min(ans, cnt+abs(n-a));
//            printf("%d\n", a);
            for(int i=0; i<10; i++) {
                if(b[i]&&a&&10*a+i<=MAX) { q.push(10*a+i); }
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}

