#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <list>

using namespace std;

int tc, tt;

bool DEBUG = false;

int main() {

//    FILE *fp = freopen("../data/3501.input", "r", stdin);
//    if(!fp)
//        perror("freopen error");

//    scanf("%d", &tc);
    tc = 10;
    tt = 0;
    while(tt++ < tc) {

        list<int> ll;
        int N, M, t, p, k;
        char c[4];
        list<int>::iterator it;
        scanf("%d", &N);
        for(int i=0; i<N; i++) { scanf("%d", &t), ll.push_back(t); }

        scanf("%d", &M);
        for(int i=0; i<M; i++) {
            scanf("%s", c);
            scanf("%d%d", &p, &k);
            it = ll.begin();
            for(int i=0; i<p; i++) it++;
            for(int i=0; i<k; i++) {
                scanf("%d", &t), ll.insert(it, t);
            }

//            for(it=ll.begin(); it!=ll.end(); it++)
//                cout << *it << " ";
//            cout << "\n";
        }

        printf("#%d ", tt);
        int b = 0;
        for(it=ll.begin(); it!=ll.end(); b++, it++) {
            if(b == 10) break;
            cout << *it << " ";
        }
        cout << "\n";
    }

    return 0;
}
