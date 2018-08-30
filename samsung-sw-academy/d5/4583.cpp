#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <map>

using namespace std;

int tc, t;
int card[7];
int a[21], b[21];
int M;
long long K;
map<pair<int, int>, int> cache;

//#define DEBUG 1
#ifdef DEBUG
#endif

inline int hashed(int* arr) {
    int key = 0, p = 1;
    for(int i=0; i<7; i++) { key += arr[6-i]*p; p *= 10; }
    return key;
}

inline void swap(int *arr, int i, int j) {
    int tmp = arr[i];
    arr[i] = arr[j], arr[j] = tmp;
}

int main() {

//    FILE *fp = freopen("../data/battle.input", "r", stdin);
//    if(!fp)
//        perror("freopen error");

    scanf("%d", &tc);
    t = 0;
    while(t++ < tc) {

        for(int i=0; i<7; i++) card[i] = i+1;
        scanf("%d%lld", &M, &K);
        int p, q;
        for(int i=0; i<M; i++) {
            scanf("%d%d", &p, &q);
            a[i] = p-1, b[i] = q-1;
        }
        cache.clear();

        cache[make_pair(M-1, hashed(card))] = 1;
        int period = 0; bool solved = 0;
        for(int i=0; i<K/M+1; i++) {
            for(int j=0; j<M; j++) {
                swap(card, a[j], b[j]), period++;
                pair<int, int> key = make_pair(j, hashed(card));
                if(cache[key]||period==K) { solved = 1; break; }
                else(cache[key] = 1);
            }
            if(solved) break;
        }
        for(int i=0; i<K%period; i++) swap(card, a[i%M], b[i%M]);

        printf("#%d ", t);
        for(int i=0; i<7; i++) printf("%d", card[i]-1);
        printf("\n");
    }

    return 0;
}
