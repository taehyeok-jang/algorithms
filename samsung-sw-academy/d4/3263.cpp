#include <iostream>

using namespace std;

#define MAX 100003

int tc, t;
int N;
int arr[MAX], length[MAX];

bool DEBUG = false;

int main() {

//    FILE *fp = freopen("../data/3263.input", "r", stdin);
//    if(!fp)
//        perror("freopen error");

    scanf("%d", &tc);
    t = 0;
    while(t++ < tc) {

        scanf("%d", &N);
        for(int i=0; i<N; i++)
            scanf("%d", &arr[i]);

        for(int i=0; i<N; i++)
            length[i] = 0;
        for(int i=0; i<N; i++)
            length[arr[i]] = length[arr[i]-1]+1;

//        for(int i=0; i<N+1; i++)
//            cout << length[i] << " ";
//        cout << "\n";

        int m = 0;
        for(int i=0; i<N+1; i++)
            m = max(m, length[i]);

        printf("#%d %d\n", t, N-m);
    }

    return 0;
}