#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <map>

using namespace std;

int tc, t;
int P, Q;

//#define DEBUG 1
#ifdef DEBUG
#endif
map<string, int> dic;

int main() {

    dic.clear();

    scanf("%d%d", &P, &Q);
    char buf[21];
    for(int i=0; i<P; i++) {
        scanf("%s", buf);
        dic[buf]++;
    }
    for(int i=0; i<Q; i++) {
        scanf("%s", buf);
        dic[buf]++;
    }
    int cnt = 0;
    for(auto it=dic.begin(); it!=dic.end(); it++)
        if(it->second==2)
            cnt++;

    printf("%d\n", cnt);
    for(auto it=dic.begin(); it!=dic.end(); it++)
        if(it->second==2)
            printf("%s\n", it->first.c_str());



    return 0;
}
