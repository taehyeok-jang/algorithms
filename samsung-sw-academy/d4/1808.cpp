#include <iostream>
#include <map>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;


#define MAX 1000001
//#define min(a, b) a<b? a:b;

int tc, t;
int X, L;

bool possible[10];
int cache[MAX];
//map<long long, int> cache;

bool DEBUG = false;

int length(int num) {

    int l = 0;
    while(pow(10, l) <= num)
        l++;

    return l;
}

int solve(int n) {

    if(n == X)
        return 0;
    if(cache[n] != -1)
        return cache[n];

    int count = 654321;

    // generate num set through bfs.
    queue<int> q;
    q.push(0);
    while(!q.empty()) {

        int m = q.front();
        q.pop();

//        cout << "n: " << n << ", m: " << m << "\n";

//        if(m>X)
//            continue;
        if(n!=0 && n*m>X)
            continue;
        if(m>1) {
            if(X%m == 0) {
                if(n == 0)  count = min(count, length(m)+solve(m));
                else        count = min(count, length(m)+1+solve(n*m));
            }
        }

        for(int i=0; i<10; i++) {
            if(possible[i]) {

                if(n==0 && i==X)
                    return 1;

                if(m==0) {
                    if(i>0 && i<=X)
                        q.push(i);
                }
                else if(10*m+i <= X) {
                    q.push(10*m+i);
                }
            }
        }

    }

    return cache[n] = count;
}

int main() {

//    FILE *fp = freopen("../data/1808.input", "r", stdin);
//    if(!fp)
//        perror("freopen error");

    scanf("%d", &tc);
    t = 0;
    while(t++ < tc) {

        for(int i=0; i<10; i++)
            scanf("%d", &possible[i]);
        scanf("%d", &X);

//        for(int i=0; i<10; i++)
//            cout << possible[i] << " ";
//        cout << "\n";
//        cout << "X: " << X << "\n";

        for(int i=0; i<X+1; i++)
            cache[i] = -1;

        int count = solve(0);
        count = (count==654321)? -1:count+1;

        printf("#%d %d\n", t, count);
    }

    return 0;
}