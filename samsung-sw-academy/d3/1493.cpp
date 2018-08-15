#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;

int tc, t;
int P, Q;

bool DEBUG = false;

pair<int, int> f(int n) {

    if(n==1)
        return make_pair(1, 1);
    int k = 1;
    while((k*(k+1))/2<n) k++;
    int x = n-((k*(k-1))/2);
    int y = k+1-x;

    return make_pair(x, y);
}

int g(pair<int, int> p) {

    int x = p.first, y = p.second;
    return ((x+y-1)*(x+y-2))/2+x;
}

int main() {

//    FILE *fp = freopen("../data/3501.input", "r", stdin);
//    if(!fp)
//        perror("freopen error");

    scanf("%d", &tc);
    t = 0;
    while(t++ < tc) {

        scanf("%d%d", &P, &Q);
        pair<int, int> p1, p2;
        p1 = f(P), p2 = f(Q);
        printf("#%d %d\n", t, g(make_pair(p1.first+p2.first, p1.second+p2.second)));
    }

    return 0;
}


/**

 1,1

 (1,2), (2,1).
 (1,3), (2,2), (3,1)
 (1,4), (2,3), (3,2), (4,1)




 */