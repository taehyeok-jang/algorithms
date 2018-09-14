#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int value[26];
char str[20][15];

struct p {
    char c; int k;
    bool operator < (const p &p2) const { return k>p2.k; }
};

int main() {

    scanf("%d", &N);
    for(int i=0; i<N; i++) scanf("%s", str[i]);

    for(int i=0; i<N; i++) {
        int k = 1;
        for(int j=0; j<strlen(str[i]); j++) {
            value[str[i][strlen(str[i])-j-1]-65] += k;
            k *= 10;
        }
    }

    p pp;
    vector<p> vv;
    for(int i=0; i<26; i++) {
        if(value[i]) {
            pp.c = i+65, pp.k = value[i];
            vv.push_back(pp);
        }
    }
    sort(vv.begin(), vv.end());

    int sum = 0, idx = 9;
    for(int i=0; i<vv.size(); i++)
        sum += vv[i].k*(idx--);

    printf("%d", sum);
    return 0;
}
