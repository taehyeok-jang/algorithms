#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
#define MAX 200001
#define INF 5000005

int N, K;
int dist[MAX], previous[MAX];
stack<int> logs;

int main() {

    scanf("%d%d", &N, &K);
    for(int i=0; i<MAX; i++) dist[i] = INF, previous[i] = -1;
    dist[N] = 0;

    queue<int> q;
    q.push(N);

    bool solved = 0; int d = 0;
    while(!solved) {

        int size = q.size();
        while(size--) {

            int pos = q.front(); q.pop();
            if(pos==K) {
                solved = 1;
                break;
            }
            if(pos>0) {
                if((d+1)<dist[pos-1]) {
                    dist[pos-1] = (d+1), previous[pos-1] = pos;
                    q.push(pos-1);
                }
            }
            if(pos<K) {
                if((d+1)<dist[pos+1]) {
                    dist[pos+1] = (d+1), previous[pos+1] = pos;
                    q.push(pos+1);
                }
                if((d+1)<dist[2*pos]) {
                    dist[2*pos] = (d+1), previous[2*pos] = pos;
                    q.push(2*pos);
                }
            }
        }

        if(solved) break;
        d++;
    }

    printf("%d\n", d);
    int cur = K;

    while(cur!=N) logs.push(cur), cur = previous[cur];
    logs.push(N);
    while(!logs.empty())
        printf("%d ", logs.top()), logs.pop();

    return 0;
}
