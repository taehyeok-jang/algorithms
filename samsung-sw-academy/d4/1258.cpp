#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int tc, t;
int N;
int MAP[100][100];
bool visited[100][100];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

bool DEBUG = false;

struct comparator {
    bool operator() (const pair<int, int> p1, const pair<int, int> p2) {
        if(p1.first*p1.second < p2.first*p2.second)
            return true;
        else if(p1.first*p1.second == p2.first*p2.second)
            return p1.first < p2.first;
        else
            return false;
    }
} matrix_comparator;

void dfs(queue<pair<int, int>> &q, int x, int y) {

//    cout << "dfs " << x << ", " << y << "\n";
//    cout << &q << "\n";

    visited[x][y] = true;
    q.push(make_pair(x, y));

    for(int i=0; i<4; i++) {
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(nx>=0&&nx<N&&ny>=0&&ny<N)
            if(!visited[nx][ny] && MAP[nx][ny]>0)
                dfs(q, nx, ny);
    }
}

int main() {

//    FILE *fp = freopen("../data/1258.input", "r", stdin);
//    if(!fp)
//        perror("freopen error");

    scanf("%d", &tc);
    t = 0;
    while(t++ < tc) {

        scanf("%d", &N);
        for(int i=0; i<N; i++)
            for(int j=0; j<N; j++)
                scanf("%d", &MAP[i][j]);

        memset(visited, 0, sizeof(bool)*100*100);

        // each contains top-left, top-right, bottom-right, bottom-left.
        vector<pair<int, int>> matrices;

        queue<pair<int, int>> q;
        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {

                if(!visited[i][j] && MAP[i][j]>0) {

                    dfs(q, i, j);
//                    cout << q.size() << "\n";

                    int top = N-1, bottom = 0, left = N-1, right = 0;
                    pair<int, int> p;
                    while(!q.empty()) {

                        p = q.front();
                        q.pop();

                        top = min(top, p.first);
                        bottom = max(bottom, p.first);
                        left = min(left, p.second);
                        right = max(right, p.second);
                    }

                    matrices.push_back(make_pair(bottom-top+1, right-left+1));
                }
            }
        }

        sort(matrices.begin(), matrices.end(), matrix_comparator);


//        cout << matrices.size() << "\n";

        printf("#%d %lu", t, matrices.size());
        for(int i=0; i<matrices.size(); i++)
            printf(" %d %d", matrices[i].first, matrices[i].second);
        printf("\n");

    }

    return 0;
}