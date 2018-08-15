#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <map>

using namespace std;

int tc, t;
int N;
char buf[10];
int A[10001];

bool DEBUG = false;
map<string, int> dic;

string s[10] = {"ZRO", "ONE", "TWO", "THR", "FOR", "FIV", "SIX", "SVN", "EGT", "NIN"};

int main() {

//    FILE *fp = freopen("../data/3501.input", "r", stdin);
//    if(!fp)
//        perror("freopen error");

    for(int i=0; i<10; i++) dic[s[i]] = i;
//    for(int i=0; i<10; i++) cout << dic[s[i]] << " ";

    scanf("%d", &tc);
    t = 0;
    while(t++ < tc) {

        scanf("%s", buf);
        scanf("%d", &N);
//        cout << buf << ", " << N << "\n";
        for(int i=0; i<N; i++) {
            scanf("%s", buf);
            A[i] = dic[string(buf)];
        }

        sort(A, A+N);
        printf("#%d\n", t);
        for(int i=0; i<N; i++)
            printf("%s ", s[A[i]].c_str());
        printf("\n");
    }

    return 0;
}
