#include <iostream>

using namespace std;

#define MAX 87654321

int tc, t;
int L, K;
char str[2000];
int ADD[26];
int DELETE[26];

int cache[2001][2001];

bool DEBUG = false;

int solve(int head, int tail) {

    if(head >= tail)
        return 0;
    if(str[head] == str[tail])
        return solve(head+1, tail-1);

    int cost = MAX;
    int t, temp;

    // use head.
    cost = min(cost, ADD[str[head]-97]+solve(head+1, tail));

    t = tail;
    temp = 0;
    while(t!=head && str[t]!=str[head]) {
        temp += DELETE[str[t]-97];
        t--;
    }
    cost = min(cost, temp+solve(head+1, t-1));

    // use tail.
    cost = min(cost, ADD[str[tail]-97]+solve(head, tail-1));

    t = head;
    temp = 0;
    while(t!=tail && str[t]!=str[tail]) {
        temp += DELETE[str[t]-97];
        t++;
    }
    cost = min(cost, temp+solve(t+1, tail-1));

    // jump each.
    cost = min(cost, DELETE[str[head]-97]+solve(head+1, tail));
    cost = min(cost, DELETE[str[tail]-97]+solve(head, tail-1));

    return cache[head][tail] = cost;
}

int main() {

//    FILE *fp = freopen("../data/4699.input", "r", stdin);
//    if(!fp)
//        perror("freopen error");

    scanf("%d", &tc);
    t = 0;
    while(t++ < tc) {

        scanf("%d%d", &L, &K);
        scanf("%s", str);
//        for(int i=0; i<L; i++)
//            str.push_back(temp[i]);
        for(int i=0; i<K; i++)
            scanf("%d%d", &ADD[i], &DELETE[i]);

        for(int i=0; i<L+1; i++)
            for(int j=0; j<L+1; j++)
                cache[i][j] = -1;

        printf("#%d %d\n", t, solve(0, L-1));
    }

    return 0;
}