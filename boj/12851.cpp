#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

#define MAX 100001
int N, K;
int min_time[2*MAX+1];

bool DEBUG = false;

int main() {

    scanf("%d%d", &N, &K);
    for(int i=0; i<2*MAX+1; i++) min_time[i] = 100001;

    int time = 0, count = 0;
    bool solve = 0;

    queue<int> q;
    q.push(N);
    min_time[N] = 0;
    while(!q.empty()) {

        int size = q.size();
        while(size--) {

            int pos = q.front();
            q.pop();

            if(pos == K) {
                solve = 1, count++;
                continue;
            }

            if(pos-1>=0&&time+1<=min_time[pos-1]) {
                q.push(pos-1);
                min_time[pos-1] = time+1;
            }
            if(pos<K&&time+1<=min_time[pos+1]) {
                q.push(pos+1);
                min_time[pos+1] = time+1;
            }
            if(pos<K&&time+1<=min_time[2*pos]) {
                q.push(2*pos);
                min_time[2*pos] = time+1;
            }
        }
        if(solve) break;
        time++;
    }

    printf("%d\n%d\n", time, count);


    return 0;
}