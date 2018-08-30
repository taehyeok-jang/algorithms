#include <iostream>
#include <cstring>

using namespace std;
#define MAX 500001
int tc, t;
int start[MAX], size[MAX];
char buf[MAX]; int L;
int a, b;

int main() {

//    FILE *fp = freopen("../data/battle.input", "r", stdin);
//    if(!fp)
//        perror("freopen error");

    scanf("%d\n", &tc);
    t = 0;
    while(t++ < tc) {

        memset(start, 0, sizeof(int)*MAX);
        memset(size, 0, sizeof(int)*MAX);

        scanf("%[^\n]s", buf);
        L = strlen(buf);
        scanf("%d %d ", &a, &b);

        int i, s;
        s = 0;
        for(int i=0; i<L; i++) {
            if(buf[i]==' ') start[i] = -1, s = i+1;
            else start[i] = s;
        }
        i = s = 0;
        while(i<L) {
            while(i<L&&buf[i]!=' '&&buf[i]!='\0') s++, i++;
            for(int j=0; j<s; j++) size[i-1-j] = s;
            i++, s = 0;
        }

        long long ans = 0;
        long long fm;
        for(int m=a; m<b+1; m++) { // O(N*(1/a+1/(a+1)+...+1/b)) ~= O(C*N) (C: constant)
            i = fm = 0;
            while(i<L) {
                if(buf[i]==' ') {
                    i++;
                }
                else { // == any words.
                    fm += size[i]+1;
                    i = start[i];
                    i += m;
                }
            }
            fm -= 1;
//            cout << "m: " << m << ", fm: " << fm << '\n';
            ans += (long long)m*fm;
        }

        printf("#%d %lld\n", t, ans);
    }

    return 0;
}