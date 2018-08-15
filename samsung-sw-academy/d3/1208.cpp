#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

int tc, t;
int D;
priority_queue<int, vector<int>, greater<int>> minPQ;
priority_queue<int, vector<int>, less<int>> maxPQ;
int A[100];
bool DEBUG = false;

int main() {

//    FILE *fp = freopen("../data/3501.input", "r", stdin);
//    if(!fp)
//        perror("freopen error");

//    scanf("%d", &tc);

    tc = 10;
    t = 0;
    while(t++ < tc) {

        while(maxPQ.size()>0) maxPQ.pop();
        while(minPQ.size()>0) minPQ.pop();

        scanf("%d", &D);
        int sum = 0;
        for(int i=0; i<100; i++) scanf("%d", &A[i]);
//        cout << "D: " << D << "\n";
//        for(int i=0; i<100; i++) cout << A[i] << " ";
//        cout << "\n";
        sort(A, A+100);
        for(int i=0; i<50; i++) minPQ.push(A[i]);
        for(int i=50; i<100; i++) maxPQ.push(A[i]);

        int a, b;
        for(int i=0; i<D; i++) {
            a=maxPQ.top(); maxPQ.pop();
            b=minPQ.top(); minPQ.pop();
            maxPQ.push(a-1);
            minPQ.push(b+1);
        }

        printf("#%d %d\n", t, maxPQ.top()-minPQ.top());
    }

    return 0;
}
