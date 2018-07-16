#include <iostream>
#include <cmath>
#include <map>
#include <vector>

using namespace std;

int tc, t;
int N;
int x[20];
int y[20];
long long MIN;

map<long long, pair<int, int>> cache;

bool DEBUG = false;

long long inner_product(pair<int, int> vector) {

    return pow(vector.first, 2)+pow(vector.second, 2);
}

long long inner_product(int x, int y) {

    return pow(x, 2)+pow(y, 2);
}

// TODO can be implemented through DP.
// but not needed, by time complexity O(20C10)=O(2*10^5)
void solve(int index, int plus, int minus, pair<int, int> vector) {

    if(index == N) {
        MIN = min(MIN, inner_product(vector));
        return;
    }

    if(plus > 0) {
        vector.first += x[index];
        vector.second += y[index];
        solve(index+1, plus-1, minus, vector);

        vector.first -= x[index];
        vector.second -= y[index];
    }

    if(minus > 0) {

        vector.first -= x[index];
        vector.second -= y[index];
        solve(index+1, plus, minus-1, vector);

        vector.first += x[index];
        vector.second += y[index];
    }
}


// TODO
// need to do pruning.
// must not find sub-vectors sum's inner product.
/*
pair<int, int> solve(int currentX, int currentY, int used) {

    cout << currentX << ", " << currentY << "\n";

    if(used == (int)pow(2, N)-1)
        return make_pair(0, 0);

//    TODO
    long long key = currentX*pow(10, 12)+currentY*pow(10, 6)+used;
//    if(cache[key] != NULL)
//        return cache[key];

    // select i and @
    int first = -1;
    int second;
    pair<int, int> p, min_pair;
    long long min = 987654321987654321;
    long long ip;
    for(int i=0; i<N; i++) {

        if((1<<i)&used)
            continue;
        if(first==-1 && ((1<<i)&used)==0) {
            first = i;
            continue;
        }

        second = i;

        int vx = x[first]-x[second];
        int vy = y[first]-y[second];

        // TODO
        // specify detail implementation.

        // find a min case of |currentX-vx|^2+|currentY-vy|^2
        p = solve(currentX+vx, currentY+vy, used|(1<<first)|(1<<second));
        ip = inner_product(currentX+vx+p.first, currentY+vy+p.second);
        if(ip < min) {
            min = ip;
            min_pair.first = currentX+vx+p.first;
            min_pair.second = currentY+vy+p.second;
        }

        p = solve(currentX-vx, currentY-vy, used|(1<<first)|(1<<second));
        ip = inner_product(currentX-vx+p.first, currentY-vy+p.second);
        if(ip < min) {
            min = ip;
            min_pair.first = currentX-vx+p.first;
            min_pair.second = currentY-vy+p.second;
        }
    }

    return cache[key] = min_pair;
}
*/

int main() {

    FILE *fp = freopen("../data/1494.input", "r", stdin);
    if(!fp)
        perror("freopen error");

    scanf("%d", &tc);
    t = 0;
    while(t++ < tc) {

        scanf("%d", &N);
        for(int i=0; i<N; i++)
            scanf("%d%d", &x[i], &y[i]);

        MIN = 987654321987654321;
//        pair<int, int> p = solve(0, 0, 0);
        solve(0, N/2, N/2, make_pair(0, 0));

//        cout << "result vector: (" << p.first << "," << p.second << ")\n";

        printf("#%d %lld\n", t, MIN/*inner_product(p.first, p.second)*/);
    }

    return 0;
}