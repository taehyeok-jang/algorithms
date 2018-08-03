#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

#define MAX 100001
int tc, t;
int N, K;

bool visited[2*MAX+1];

bool DEBUG = false;

int main() {

//    FILE *fp = freopen("../data/3501.input", "r", stdin);
//    if(!fp)
//        perror("freopen error");

//    scanf("%d", &tc);
    tc = 1;
    t = 0;
    while(t++ < tc) {

        scanf("%d%d", &N, &K);
        memset(visited, 0, sizeof(bool)*(2*K+1));

        int time = 0;
        visited[N] = true;

        queue<int> q;
        q.push(N);
        while(!q.empty()) {

//            cout << "time: " << time << "\n";

            int size = q.size();
            while(size--) {

                int pos = q.front();
                q.pop();

//                cout << pos << "\n";

                if(pos == K) {
                    printf("%d\n", time);
                    return 0;
                }

                if(pos-1>=0 && !visited[pos-1]) {
                    visited[pos-1] = true;
                    q.push(pos-1);
                }
                if(pos<K && !visited[pos+1]) {
                    visited[pos+1] = true;
                    q.push(pos+1);
                }
                if(pos<K && !visited[2*pos]) {
                    visited[2*pos] = true;
                    q.push(2*pos);
                }
            }

            time++;
//            cout << pos << ", " << time << "\n";
        }


    }

    return 0;
}