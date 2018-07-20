#include <iostream>
#include <vector>

using namespace std;

int tc, t;
int N, M;
int tk[100001];

#define MAX 100000000000001

bool DEBUG = false;

int main() {

//    FILE *fp = freopen("../data/3074.input", "r", stdin);
//    if(!fp)
//        perror("freopen error");

    scanf("%d", &tc);
    t = 0;
    while(t++ < tc) {

        scanf("%d%d", &N, &M);

        for(int i=0; i<N; i++)
            scanf("%d", &tk[i]);

        long long left = 1;
        long long right = MAX;

        long long sum, mid;
        while(left <= right) {

            sum = 0;
            mid = (left+right)/2;

            for(int i=0; i<N; i++)
                sum += (mid/tk[i]);

            if(sum >= M)
                right = mid-1;
            else
                left = mid+1;
        }

        printf("#%d %lld\n", t, left);
    }

    return 0;
}