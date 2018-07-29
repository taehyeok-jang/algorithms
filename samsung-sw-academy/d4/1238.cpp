#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

int tc, t;
int N, start;

bool DEBUG = false;

vector<int> adjs[101];
bool visited[101];

int main() {

//    FILE *fp = freopen("../data/1238.input", "r", stdin);
//    if(!fp)
//        perror("freopen error");

    tc = 10;
    t = 0;
    while(t++ < tc) {

        for(int i=0; i<101; i++)
            adjs[i].clear();
        memset(visited, 0, sizeof(bool)*101);

        scanf("%d%d", &N, &start);
        int from, to;

        int current_depth = 0;
        int last_max = 0;

        for(int i=0; i<N/2; i++) {
            scanf("%d%d", &from, &to);
            adjs[from].push_back(to);
        }

        queue<pair<int, int>> calls;
        calls.push(make_pair(1, start));

        while(!calls.empty()) {

            int depth = calls.front().first;
            int turn = calls.front().second;
            calls.pop();

            if(current_depth < depth) {
                current_depth = depth;
                last_max = turn;
            }
            else if(current_depth == depth) {
                last_max = max(last_max, turn);
            }

            vector<int>::iterator it;
            for(it=adjs[turn].begin(); it!=adjs[turn].end(); it++) {

                if(!visited[*it]) {
                    calls.push(make_pair(depth+1, *it));
                    visited[*it] = true;
                }
            }
        }

        printf("#%d %d\n", t, last_max);
    }

    return 0;
}