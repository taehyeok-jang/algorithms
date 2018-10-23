#include <iostream>
#include <vector>
#include <ctime>
using namespace std;
//struct tree {
//    int n, age;
//};
struct m {
    int power;
    vector<int> trees, next;
} map[11][11];
int tc, test, N, M, K; // N<=10, M<=1000, K<=N^2
int add[11][11];
int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
bool out_of_bounds(int x, int y) { return x<0||x>=N||y<0||y>=N; }

void spring() {
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(map[i][j].trees.size()==0) continue;
            while(map[i][j].trees.size()>0&&map[i][j].power>=map[i][j].trees.back()) {
                int age = map[i][j].trees.back();
                map[i][j].power -= age;
                map[i][j].next.push_back(age+1);
                map[i][j].trees.pop_back();
            }
        }
    }
}
void summer() {
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(map[i][j].trees.size()==0&&map[i][j].next.size()==0) continue;
            while(!map[i][j].trees.empty())
                map[i][j].power += map[i][j].trees.back()/2, map[i][j].trees.pop_back();
            while(!map[i][j].next.empty())
                map[i][j].trees.push_back(map[i][j].next.back()), map[i][j].next.pop_back();
        }
    }
}
void fall() {
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(map[i][j].trees.size()==0) continue;
            for(int k=0; k<map[i][j].trees.size(); k++) {
                if(map[i][j].trees[k]%5==0) {
                    int nx, ny;
                    for(int d=0; d<8; d++) {
                        nx = i+dx[d], ny = j+dy[d];
                        if(out_of_bounds(nx, ny)) continue;
                        map[nx][ny].trees.push_back(1);
                    }
                }
            }
        }
    }
}
void winter() {
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            map[i][j].power += add[i][j];
}

void print() {
    cout << "trees\n";
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(map[i][j].trees.size())
                for(int k=0; k<map[i][j].trees.size(); k++)
                    cout << map[i][j].trees[k] << " ";
            else
                cout << "-";
            cout << "\t";
        }
        cout << "\n";
    }
    cout << "power\n";
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cout << map[i][j].power << "\t";
        }
        cout << "\n";
    }
    cout << "\n";
}

int main() {
    tc = 1;
//    cin >> tc;
    test = 0;
    clock_t start = clock();
    while(test++ < tc) {
        cin >> N >> M >> K;
        for(int i=0; i<N; i++)
            for(int j=0; j<N; j++)
                cin >> add[i][j];
        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                map[i][j].power = 5;
                map[i][j].trees.clear(), map[i][j].next.clear();
            }
        }
        for(int i=0; i<M; i++) {
            int x, y, a;
            cin >> x >> y >> a;
            map[x-1][y-1].trees.push_back(a); // (y,x). (transposed map).
        }

//        int year = 0;
        while(K--) {
//            cout << "@@ year " << ++year << "\n";
//            print();
            spring();
            summer();
            fall();
            winter();
        }

        int ans = 0;
        for(int i=0; i<N; i++)
            for(int j=0; j<N; j++)
                ans += map[i][j].trees.size();
//        cout << "#" << test << " " << ans << "\n";
        cout << ans;
    }
    clock_t end = clock();
//    cout << (end-start)/(double)1000000 << endl;
    return 0;
}

/**
 *
input
3
5 20 2
2 2 3 2 3
3 4 2 3 2
4 4 4 5 2
3 3 3 2 2
2 3 2 2 5
2 3 2
3 1 1
10 1000 8
14 6 9 16 8 16 5 9 16 2
9 6 2 15 2 9 7 11 6 9
2 2 4 4 4 2 8 10 16 12
12 9 12 9 15 3 5 3 16 9
10 2 16 11 7 12 6 10 13 16
7 8 12 8 3 14 16 3 13 6
10 8 16 7 13 9 13 7 12 15
12 2 7 8 5 16 12 3 8 10
5 11 13 5 6 12 12 5 11 4
16 5 16 9 7 15 5 11 12 6
9 2 7
9 4 2
6 8 3
5 2 9
4 2 6
3 9 1
4 3 5
7 1 5
10 1000 8
83 57 47 37 10 18 55 63 93 25
9 33 71 7 97 41 31 45 73 14
37 4 2 92 98 49 88 91 59 84
25 97 60 41 100 87 51 28 75 71
25 3 3 69 93 37 62 10 81 84
5 17 10 11 85 13 42 100 83 1
95 25 90 33 17 73 28 87 73 63
21 62 90 36 47 42 10 28 56 38
31 2 42 74 53 48 27 75 30 6
36 1 93 63 35 12 83 35 60 86
9 2 7
9 4 2
6 8 3
5 2 9
4 2 6
3 9 1
4 3 5
7 1 5

# 3번째 input 은 양분 크기가 큼.

output
#1 157
#2 1357
#3 11137

# 자체 생성 input 을 돌린 결과 output 입니다.

 */

/*
 *
 * #include <iostream>
#include <vector>
#include <ctime>
using namespace std;
//struct tree {
//    int n, age;
//};
struct m {
    int power, a, b;
    int trees[4001], next[4001];
} map[11][11];
int tc, test, N, M, K; // N<=10, M<=1000, K<=N^2
int add[11][11];
int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
bool out_of_bounds(int x, int y) { return x<0||x>=N||y<0||y>=N; }

void spring() {
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(map[i][j].a==0) continue;
            while(map[i][j].a>0&&map[i][j].power>=map[i][j].trees[map[i][j].a]) {
                int age = map[i][j].trees[map[i][j].a--];
                map[i][j].power -= age;
                map[i][j].next[++map[i][j].b] = age+1;
            }
        }
    }
}
void summer() {
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(map[i][j].a==0&&map[i][j].b==0) continue;
            while(map[i][j].a>0)
                map[i][j].power += map[i][j].trees[map[i][j].a--]/2;
            while(map[i][j].b>0)
                map[i][j].trees[++map[i][j].a] = map[i][j].next[map[i][j].b--];
        }
    }
}
void fall() {
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(map[i][j].a==0) continue;
            for(int k=1; k<=map[i][j].a; k++) {
                if(map[i][j].trees[k]%5==0) {
                    int nx, ny;
                    for(int d=0; d<8; d++) {
                        nx = i+dx[d], ny = j+dy[d];
                        if(out_of_bounds(nx, ny)) continue;
                        map[nx][ny].trees[++map[nx][ny].a] = 1;
                    }
                }
            }
        }
    }
}
void winter() {
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            map[i][j].power += add[i][j];
}

void print() {
    cout << "trees\n";
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(map[i][j].a)
                for(int k=0; k<map[i][j].a; k++)
                    cout << map[i][j].trees[k] << " ";
            else
                cout << "-";
            cout << "\t";
        }
        cout << "\n";
    }
    cout << "power\n";
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cout << map[i][j].power << "\t";
        }
        cout << "\n";
    }
    cout << "\n";
}

int main() {
    cin >> tc;
    test = 0;
    clock_t start = clock();
    while(test++ < tc) {
        cin >> N >> M >> K;
        for(int i=0; i<N; i++)
            for(int j=0; j<N; j++)
                cin >> add[i][j];
        for(int i=0; i<N; i++)
            for(int j=0; j<N; j++)
                map[i][j].power = 5, map[i][j].a = 0, map[i][j].b = 0;

        for(int i=0; i<K; i++) {
            int x, y, age;
            cin >> x >> y >> age;
            map[y][x].trees[++map[y][x].a] = age;
        }

        int year = 0;
        while(M--) {
//            cout << "@@ year " << ++year << "\n";
//            print();
            spring();
            summer();
            fall();
            winter();
        }

        int ans = 0;
        for(int i=0; i<N; i++)
            for(int j=0; j<N; j++)
                ans += map[i][j].a;
        cout << "#" << test << " " << ans << "\n";
    }
    clock_t end = clock();
    cout << (end-start)/(double)1000000 << endl;
    return 0;
}

 */