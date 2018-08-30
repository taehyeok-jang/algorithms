#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;
#define MAX 2001
struct state {
    int a, b;
};
int S;
state q[100000]; int f, r, size;
int visited[MAX][MAX];

int main() {

    scanf("%d", &S);
    f = r = 0;
    q[r++] = state({1, 0});
    visited[1][0] = 1;

    int time = 0;
    while(f!=r) {

        size = r-f;
        while(size--) {

            state s = q[f++];
//            cout << s.a << ", " << s.b << "\n";
            if(s.a==S) { printf("%d", time); return 0; }

            if(!visited[s.a][s.a]) {
                q[r++] = state({s.a, s.a});
                visited[s.a][s.a] = 1;
            }
            if(s.b>0&&s.a<1001&&!visited[s.a+s.b][s.b]) {
                q[r++] = state({s.a+s.b, s.b});
                visited[s.a+s.b][s.b] = 1;
            }
            if(s.a-1>=0&&!visited[s.a-1][s.b]) {
                q[r++] = state({s.a-1, s.b});
                visited[s.a-1][s.b] = 1;
            }
        }
        time++;
    }

    return 0;
}
