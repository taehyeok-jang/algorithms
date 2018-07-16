#include <iostream>
#include <cmath>
#include <map>

using namespace std;

int tc, t;
int N;
int weight[10];

//int cache[512][512][512];
map<long long, int> map1;

bool DEBUG = false;

// weight<= 10^4, used<10^3
int solve(long long left, long long right, int used) {

    if(used == (int)pow(2, N)-1)
        return 1;

    long long key = left*pow(10, 7)+right*pow(10, 3)+used;
    if(map1[key])
        return map1[key];

    int count = 0;
    for(int i=0; i<N; i++) {
        if((1<<i) & used)
            continue;

        count += solve(left+weight[i], right, used|(1<<i));
        if(left >= right+weight[i])
            count += solve(left, right+weight[i], used|(1<<i));
    }

    return map1[key] = count;
}

int main() {

//    FILE *fp = freopen("../data/3234.input", "r", stdin);
//    if(!fp)
//        perror("freopen error");

    scanf("%d", &tc);
    t = 0;
    while(t++ < tc) {

        map1.clear();

        scanf("%d", &N);
        for(int i=0; i<N; i++)
            scanf("%d", &weight[i]);

        int count = 0;
        for(int i=0; i<N; i++)
            count += solve(weight[i], 0, (1<<i));

        printf("#%d %d\n", t, count);
    }

    return 0;
}